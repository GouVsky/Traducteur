//
//  champTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "GFenetre.hpp"
#include "GChampTexte.hpp"

using namespace sf;
using namespace std;


GChampDeTexte::GChampDeTexte() : GZoneDeTexte() {}




// Récupère ce qui est entré par l'utilisateur.

void GChampDeTexte::traitement()
{
    locale::global(locale(""));

    Event * evenement = GFenetre::getEvent();
    
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
                        texte.insert(_curseur.recuperer_position_x(), buffer);
                        
                        _curseur.modifier_position_x((int) texte.getSize() - 1);
                    }
                }
                
                texte.erase(_curseur.recuperer_position_x(), 1);
                
                pclose(copier_coller);
            }
            
            else if (evenement->key.code == Keyboard::Left)
            {
                if(_curseur.recuperer_position_x() > 0)
                {
                    _curseur.modifier_position_x(-1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Right)
            {
                if(_curseur.recuperer_position_x() < texte.getSize())
                {
                    _curseur.modifier_position_x(1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Up)
            {
                if(_curseur.recuperer_position_y() > 0)
                {
                    _curseur.modifier_position_y(-1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Down)
            {
                if(_curseur.recuperer_position_y() < _texte.recuperer_nombre_de_phrases() - 1)
                {
                    _curseur.modifier_position_y(1);
                }
            }
        }
        
        // L'utilisateur presse une touche du clavier.
        
        else if (evenement->type == Event::TextEntered)
        {
            // S'il s'agit de la touche "BACKSPACE", on efface le dernier caractère.
            
            if (evenement->text.unicode == 8)
            {
                if (texte.getSize() > 0 && _curseur.recuperer_position_x() > 0)
                {
                    texte.erase(_curseur.recuperer_position_x() - 1, 1);
                    
                    _curseur.modifier_position_x(-1);
                }
            }
            
            else
            {
                texte.insert(_curseur.recuperer_position_x(), static_cast <char> (evenement->text.unicode));
                
                _curseur.modifier_position_x(1);
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
 
    _curseur.modifier_position_x(0);
 
    _curseur.modifier_position_y(0);
}




// Affichage du champ de texte.

void GChampDeTexte::afficher()
{
    texture.clear(Color::White);
    
    traitement();
    
    _texte.afficher_texte(texture, texte_source);
    
    _curseur.afficher(&texture);
    
    texture.display();
        
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    GFenetre::getWindow()->draw(sprite);
    GFenetre::getWindow()->draw(contours);
}
