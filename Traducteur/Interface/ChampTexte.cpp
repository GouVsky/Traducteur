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




// Récupère ce qui est entré par l'utilisateur.

void GChampDeTexte::traitement()
{
    locale::global(locale(""));

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
                        texte.insert(position_x_curseur, buffer);
                        
                        position_x_curseur = (int) texte.getSize();
                    }
                }
                
                texte.erase(position_x_curseur - 1, 1);
                
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
                if(position_x_curseur < texte.getSize())
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
                if (texte.getSize() > 0 && position_x_curseur > 0)
                {
                    texte.erase(position_x_curseur - 1, 1);
                    
                    position_x_curseur--;
                }
            }
            
            else
            {
                texte.insert(position_x_curseur, static_cast <char> (evenement->text.unicode));
                
                position_x_curseur++;
            }
        }
    }
    
    texte_source = "";
    
    Utf32::toUtf8(texte.begin(), texte.end(), back_inserter(texte_source));
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
    texture.clear(Color::White);
    
    traitement();
    
    _texte.afficher_texte(&texture, texte_source);
    
    texture.display();
        
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    Fenetre::recuperer_fenetre()->draw(sprite);
    Fenetre::recuperer_fenetre()->draw(contours);
}
