//
//  champTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "fenetre.hpp"
#include "champTexte.hpp"

using namespace sf;
using namespace std;


GChampDeTexte::GChampDeTexte() : GZoneDeTexte()
{
    position_x_curseur = 0;
    
    position_y_curseur = 0;
    
    parametres_curseur.resize(4, 0);
}




// Récupère la taille du texte entré dans le champ de texte.

int GChampDeTexte::recuperer_taille_texte()
{
    Text texte;
    
    texte.setString(texte_source);
    texte.setFont(police);
    
    return texte.getLocalBounds().width;
}




// Récupère le texte entré dans le champ de texte.

string GChampDeTexte::recuperer_texte()
{
    return texte_source + '\0';
}




// Création d'un curseur.

void GChampDeTexte::creer_curseur()
{
    curseur.definir_taille(3, 50);
    curseur.definir_couleur(Color::Black);
    curseur.definir_position(position_x_curseur, position_y_curseur, tableau, parametres_curseur);
    curseur.afficher(&texture);
}




// Récupère ce qui est entré par l'utilisateur.

void GChampDeTexte::traitement()
{
    Fenetre fenetre;

    Event * evenement = fenetre.recuperer_evenement();
    
    if (evenement != nullptr)
    {
        if (evenement->type == Event::KeyPressed)
        {
            if (evenement->key.system && evenement->key.code == Keyboard::V)
            {
                FILE * copier_coller = popen("pbpaste", "r");
                
                char buffer[1000] = {0};
                
                while (feof(copier_coller) == false)
                {
                    if (fgets(buffer, 1000, copier_coller) != NULL)
                    {
                        texte_source.insert(position_x_curseur, buffer);
                        
                        position_x_curseur = (int) texte_source.size();
                    }
                }
                
                texte_source.erase(position_x_curseur - 1, 1);
                
                position_x_curseur--;
                
                pclose(copier_coller);
            }
            
            else if (evenement->key.code == Keyboard::Up)
            {
                parametres_curseur[0] = 0;
                parametres_curseur[1] = -1;
                parametres_curseur[2] = 0;
                parametres_curseur[3] = -1;
                
                if (position_y_curseur > 0)
                {
                    position_y_curseur--;
                }
            }
            
            else if (evenement->key.code == Keyboard::Down)
            {
                parametres_curseur[0] = 1;
                parametres_curseur[1] = 0;
                parametres_curseur[2] = (int) tableau.size() - 1;
                parametres_curseur[3] = 1;
                
                if (position_y_curseur < tableau.size() - 1)
                {
                    position_y_curseur++;
                }
            }
            
            else if (evenement->key.code == Keyboard::Left)
            {
                if(position_x_curseur > 0)
                {
                    position_x_curseur--;
                }
            }
            
            else if (evenement->key.code == Keyboard::Right)
            {
                if(position_x_curseur < texte_source.size())
                {
                    position_x_curseur++;
                }
            }
        }
        
        // L'utilisateur presse une touche du clavier.
        
        else if (evenement->type == Event::TextEntered)
        {
            // S'il s'agit de la touche "ENTREE", on effectue la traduction du texte.
            
            if(evenement->text.unicode == 10)
            {
                
            }
            
            // S'il s'agit de la touche "BACKSPACE", on efface le dernier caractère.
            
            else if (evenement->text.unicode == 8)
            {
                if (texte_source.size() > 0 && position_x_curseur > 0)
                {
                    texte_source.erase(position_x_curseur - 1, 1);
                    
                    position_x_curseur--;
                }
            }
            
            else
            {
                texte_source.insert(position_x_curseur, 1, static_cast <char> (evenement->text.unicode));
                
                position_x_curseur++;
            }
        }
    }
    
    traitement_des_phrases(texte_source, &texture);
}




// Efface le contenu du champ de texte.

void GChampDeTexte::effacer_contenu()
{
    texte_source = "";
    
    position_x_curseur = 0;
    
    position_y_curseur = 0;
}




// Affichage du champ de texte.

void GChampDeTexte::afficher()
{
    Fenetre fenetre;
    
    texture.create(largeur, hauteur);
    
    texture.clear(Color::White);
    
    traitement();
    
    definir_contours();
    
    creer_curseur();
    
    texture.display();
        
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contour);
}
