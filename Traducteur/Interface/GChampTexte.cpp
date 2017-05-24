//
//  champTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "GChampTexte.hpp"

using namespace sf;
using namespace std;


GChampDeTexte::GChampDeTexte() : GZoneDeTexte() {}




// Récupère ce qui est entré par l'utilisateur.

void GChampDeTexte::treatment()
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
                        texte.insert(_curseur.getPositionX(), buffer);
                        
                        _curseur.setPositionX((int) texte.getSize() - 1);
                    }
                }
                
                texte.erase(_curseur.getPositionX(), 1);
                
                pclose(copier_coller);
            }
            
            else if (evenement->key.code == Keyboard::Left)
            {
                if(_curseur.getPositionX() > 0)
                {
                    _curseur.setPositionX(-1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Right)
            {
                if(_curseur.getPositionX() < texte.getSize())
                {
                    _curseur.setPositionX(1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Up)
            {
                if(_curseur.getPostionY() > 0)
                {
                    _curseur.setPositionY(-1);
                }
            }
            
            else if (evenement->key.code == Keyboard::Down)
            {
                if(_curseur.getPostionY() < _text.getNumberOfSentences() - 1)
                {
                    _curseur.setPositionY(1);
                }
            }
        }
        
        // L'utilisateur presse une touche du clavier.
        
        else if (evenement->type == Event::TextEntered)
        {
            // S'il s'agit de la touche "BACKSPACE", on efface le dernier caractère.
            
            if (evenement->text.unicode == 8)
            {
                if (texte.getSize() > 0 && _curseur.getPositionX() > 0)
                {
                    texte.erase(_curseur.getPositionX() - 1, 1);
                    
                    _curseur.setPositionX(-1);
                }
            }
            
            else
            {
                texte.insert(_curseur.getPositionX(), static_cast <char> (evenement->text.unicode));
                
                _curseur.setPositionX(1);
            }
        }
    }
    
    texte_source = "";
    
    Utf32::toUtf8(texte.begin(), texte.end(), back_inserter(texte_source));
}




// Efface le contenu du champ de texte.

void GChampDeTexte::deleteContent()
{
    texte_source = "";
 
    _curseur.setPositionX(0);
 
    _curseur.setPositionY(0);
}




// Affichage du champ de texte.

void GChampDeTexte::display()
{
    texture.clear(Color::White);
    
    treatment();
    
    _text.displayText(texture, texte_source);
    
    _curseur.display(&texture);
    
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(_position_x, _position_y);
    
    GFenetre::getWindow()->draw(sprite);
    GFenetre::getWindow()->draw(contours);
}
