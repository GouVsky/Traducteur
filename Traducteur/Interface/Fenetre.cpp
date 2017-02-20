//
//  fenetre.cpp
//  Traducteur
//
//  Created by Grégoire on 05/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//


#include "Image.hpp"
#include "Fenetre.hpp"
#include "ResourcePath.hpp"
#include "ConstructionTexte.hpp"
#include "ConstructionPhrase.hpp"

using namespace sf;
using namespace std;


RenderWindow Fenetre::fenetre;

vector <Event> Fenetre::queue;

int Fenetre::element_dans_la_queue = 0;


// Initialisation des différents éléments.

Fenetre::Fenetre()
{
    langue_source = "";
    langue_sortie = "";
}




// On récupère les évènements stockés dans une queue.

Event * Fenetre::recuperer_evenement()
{
    if (queue.size() > element_dans_la_queue)
    {
        element_dans_la_queue++;
        
        return &queue[element_dans_la_queue - 1];
    }
    
    return nullptr;
}




RenderWindow * Fenetre::recuperer_fenetre()
{
    return &fenetre;
}




void Fenetre::affichage_des_elements()
{
    champ_texte_source.afficher();

    rendu.afficher(texte_traduit);
    
    bouton_F.definir_couleur(Color(255, 255, 255, alpha_F));
    bouton_A.definir_couleur(Color(255, 255, 255, alpha_A));
        
    langue_de_traduction.definir_couleur(Color(255, 255, 255, alpha_langue_traduction));
    
    traduire.afficher();
    bouton_F.afficher();
    bouton_A.afficher();
    langue_de_traduction.afficher();
    
    fenetre.draw(chargement);
}




// Affichage de l'icône de chargement du texte traduit.

/*void Fenetre::chargement_du_texte()
{
    clock_t debut = clock();
    
    clock_t fin = clock();
    
    while (!arret_du_chargement)
    {
        // Si le temps de traduction du texte est supérieur à 1,2 secondes,
        // on affiche l'icône de chargement.
        
        if ((fin - debut) / (float) CLOCKS_PER_SEC > 1.2)
        {
            for (int i = 0; i <= 360; i += 30)
            {
                if (arret_du_chargement)
                {
                    break;
                }
                
                //chargement.setRotation(i);
                
                affichage_des_elements();
                
                fenetre.display();
                
                sleep(seconds(0.09));
                
                if (i == 360)
                {
                    i = 0;
                }
            }
        }
        
        else
        {
            fin = clock();
        }
    }
}*/




void Fenetre::gestion_des_boutons()
{
    // La langue choisie est le français.
    
    if (bouton_F.est_presse())
    {
        alpha_F = 255;
        alpha_A = 100;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.rogner_image(219, 0, 216, 146);
        
        langue_source = "F";
        langue_sortie = "A";
    }
    
    // La langue choisie est l'anglais.
    
    else if (bouton_A.est_presse())
    {
        alpha_F = 100;
        alpha_A = 255;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.rogner_image(0, 0, 219, 146);
        
        langue_source = "A";
        langue_sortie = "F";
    }
    
    if (traduire.est_presse())
    {
        Texte bob_le_bricoleur(langue_source, langue_sortie);
        
        bob_le_bricoleur.construction_du_texte(champ_texte_source.recuperer_texte());
        
        texte_traduit = bob_le_bricoleur.recuperer_texte_traduit();
    }
}




// Création de la fenêtre.

int Fenetre::creation_de_la_fenetre()
{
    fenetre.create(VideoMode(2080, 1060, 32), "", Style::Close);
        
    if(police.loadFromFile(resourcePath() + "GenR102.TTF") == false)
    {
        return EXIT_FAILURE;
    }
        
    champ_texte_source.definir_taille(1005, 760);
    champ_texte_source.definir_position(20, 200);
    champ_texte_source.definir_police(police);
    
    rendu.definir_taille(1005, 760);
    rendu.definir_position(1055, 200);
    rendu.definir_police(police);
    
    bouton_F.definir_image("selection_langue.png");
    bouton_F.definir_position(600, 50);
    bouton_F.redimensionner(0.6, 0.6);
    bouton_F.rogner_image(0, 0, 219, 146);
    
    bouton_A.definir_image("selection_langue.png");
    bouton_A.definir_position(300, 50);
    bouton_A.redimensionner(0.6, 0.6);
    bouton_A.rogner_image(219, 0, 216, 146);
    
    langue_de_traduction.definir_image("selection_langue.png");
    langue_de_traduction.definir_position(1480, 50);
    langue_de_traduction.redimensionner(0.6, 0.6);
    
    traduire.definir_image("traduire.png");
    traduire.definir_position(503, 990);
    traduire.redimensionner(0.06, 0.06);
        
    while (fenetre.isOpen())
    {
        fenetre.clear(Color::White);

        while (fenetre.pollEvent(evenement))
        {
            // On ferme la fenêtre en pressant la croix ou en appuyant sur "ECHAP".
            
            if(evenement.type == Event::Closed || (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Escape))
            {
                fenetre.close();
            }
            
            // Le stockage des évènements permettra de gérer certains cas dans des champs de texte.
            
            else
            {
                queue.push_back(evenement);
            }
        }
        
        affichage_des_elements();
        
        gestion_des_boutons();
        
        fenetre.display();
    }
    
    return EXIT_SUCCESS;
}
