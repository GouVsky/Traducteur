//
//  champTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "Fenetre.hpp"
#include "ChampTexte.hpp"

using namespace sf;
using namespace std;


GChampDeTexte::GChampDeTexte() : GZoneDeTexte()
{
    position_x_curseur = 0;
    
    position_y_curseur = 0;
    
    parametres_curseur.resize(4, 0);
}




// Récupère le texte entré dans le champ de texte.

string GChampDeTexte::recuperer_texte()
{
    return texte_source + '\0';
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
            // S'il s'agit de la touche "BACKSPACE", on efface le dernier caractère.
            
            if (evenement->text.unicode == 8)
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
    
    texture.clear(Color::White);
    
    traitement();
    
    _texte.afficher_texte(&texture, texte_source);
    
    texture.display();
        
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contours);
}
