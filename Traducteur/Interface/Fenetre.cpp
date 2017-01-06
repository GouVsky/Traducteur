//
//  Fenetre.cpp
//  Traducteur
//
//  Created by Grégoire on 27/06/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "icone.hpp"
#include "curseur.hpp"
#include "Fenetre.hpp"
#include "champTexte.hpp"
#include "ResourcePath.hpp"
#include "ConstructionPhrase.hpp"

using namespace sf;
using namespace std;


// Initialisation des différents éléments.

Fenetre::Fenetre()
{
    texture_source.clear(Color::White);
    texture_sortie.clear(Color::White);
    
    icone.setSmooth(true);
    langues.setSmooth(true);
}



// Mise à jour de la fenêtre.

void Fenetre::mise_a_jour()
{
    Icone icone;
    Curseur curseur;
    
    
    fenetre.clear();
    
    
    // Affichage d'un curseur.
    
    texture_source.draw(curseur.affichage(police, position_x, tableau_source));
    
    // Affichage des textures.
    
    texture_source.display();
    
    texture_sortie.display();
    
    // Création des sprites.
    
    sprite_source.setTexture(texture_source.getTexture());
    
    sprite_sortie.setTexture(texture_sortie.getTexture());
    sprite_sortie.setPosition(1043, 0);
    
    // Affichage des textures sur la fenêtre.
    
    fenetre.draw(sprite_source);
    fenetre.draw(sprite_sortie);
    
    // Affichage des boutons.
    
    tuple <string, string> langue = icone.creation_des_boutons(&fenetre, langues, langue_source, langue_sortie);
    
    langue_source = get <0> (langue);
    langue_sortie = get <1> (langue);
    
    fenetre.display();
}




// Affichage de l'icône de chargement du texte traduit.

void Fenetre::chargement_du_texte(clock_t debut)
{
    clock_t fin = clock();
    
    while (!stop)
    {
        // Si le temps de traduction du texte est supérieur à 1,2 secondes,
        // on affiche l'icône de chargement.
        
        if ((fin-debut) / (float) CLOCKS_PER_SEC > 1.2)
        {
            for (int i = 0; i <= 360; i += 30)
            {
                if (stop)
                {
                    break;
                }
                
                chargement.setTexture(icone);
                chargement.setScale(0.3, 0.3);
                chargement.setPosition(2025, 50);
                chargement.setOrigin(chargement.getLocalBounds().width / 2, chargement.getLocalBounds().height / 2);
                
                chargement.setRotation(i);
                
                fenetre.draw(chargement);
                
                fenetre.display();
                
                sleep(seconds(0.09));
                
                if (i == 360) i = 0;
            }
        }
        
        else fin = clock();
    }
    
    return;
}




// Création de la fenêtre.

int Fenetre::creation_de_la_fenetre()
{
    fenetre.create(VideoMode(2083, 1000, 32), "", Style::Close);
    
    fenetre.setFramerateLimit(30);
  
    // Création de deux textures.
    
    if(texture_source.create(1040, 1000) == false)
    {
        return EXIT_FAILURE;
    }
    
    if(texture_sortie.create(1040, 1000) == false)
    {
        return EXIT_FAILURE;
    }
    
    // Création des icônes.
    
    if(langues.loadFromFile(resourcePath() + "selection_langue.png") == false)
    {
        return EXIT_FAILURE;
    }
    
    if(icone.loadFromFile(resourcePath() + "icone_chargement.png") == false)
    {
        return EXIT_FAILURE;
    }
    
    // Chargement de la police.
    
    if(police.loadFromFile(resourcePath() + "GenR102.TTF") == false)
    {
        return EXIT_FAILURE;
    }
        
    mise_a_jour();
    
    // Début du programme.
    
    Event evenement;
    
    Curseur curseur;
    ChampTexte champ_texte;
    
    while(fenetre.isOpen())
    {
        while(fenetre.pollEvent(evenement))
        {
            // On ferme la fenêtre en pressant la croix ou en appuyant sur "ECHAP".
            
            if(evenement.type == Event::Closed || (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Escape))
            {
                fenetre.close();
            }
            
            // L'utilisateur fait un copié-collé dans la fenêtre.
            
            else if (evenement.type == Event::KeyPressed && evenement.key.system && evenement.key.code == Keyboard::V)
            {
                FILE* copier_coller = popen("pbpaste", "r");
                
                if (!copier_coller) return EXIT_FAILURE;
                
                char buffer[1000];
                
                while (feof(copier_coller) == false)
                {
                    if (fgets(buffer, 1000, copier_coller) != NULL)
                    {
                        texte_source += buffer;
                        
                        position_x += texte_source.size();
                    }
                }
                
                pclose(copier_coller);
            }
            
            else if (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Up)
            {
                curseur.set_calcul_position(position_x, 0, - 1, 0, -1, tableau_source);
                
                position_x = curseur.get_calcul_position();
            }
            
            else if (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Down)
            {
                curseur.set_calcul_position(position_x, 1, 0, (int) tableau_source.size() - 1, 1, tableau_source);
                
                position_x = curseur.get_calcul_position();
            }
            
            else if (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Left)
            {
                if(position_x > 0)
                {
                    position_x--;
                }
            }
            
            else if (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Right)
            {
                if(position_x < texte_source.size())
                {
                    position_x++;
                }
            }
            
            // L'utilisateur presse une touche du clavier.
            
            else if (evenement.type == Event::TextEntered)
            {
                // S'il s'agit de la touche "ENTREE", on effectue la traduction du texte.
                
                if(evenement.text.unicode == 10)
                {
                    if(!langue_source.empty())
                    {
                        clock_t debut = clock();
                        
                        Phrase bob_le_bricoleur;
                        
                        thread un_thread = thread(&Fenetre::chargement_du_texte, this, debut);
                        
                        tuple <string, vector <string>> resultat = bob_le_bricoleur.construction_du_texte(texte_source, langue_source, langue_sortie);
                        
                        stop = true;
                        
                        un_thread.join();
                        
                        texte_sortie = get <0> (resultat);
                        
                        structure = get <1> (resultat);
                        
                        break;
                    }
                }
                
                // S'il s'agit de la touche "BACKSPACE", on efface le dernier caractère.

                else if (evenement.text.unicode == 8)
                {
                    if (texte_source.size() > 0 && position_x > 0)
                    {
                        texte_source.erase(position_x - 1, 1);
                        
                        position_x--;
                    }
                }
                
                else
                {
                    texte_source.insert(position_x, 1, evenement.text.unicode);
                    
                    position_x++;
                }
            }
        }
        
        tableau_source = champ_texte.traitement_des_phrases(police, "source", texte_source, &texture_source, structure);
        
        tableau_sortie = champ_texte.traitement_des_phrases(police, "sortie", texte_sortie, &texture_sortie, structure);
        
        mise_a_jour();
        
        stop = false;
    }
    
    return EXIT_SUCCESS;
}
