//
//  renduTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "GRenduTexte.hpp"


using namespace sf;
using namespace std;


GTexteDeRendu::GTexteDeRendu() : GZoneDeTexte() {}




// Affichage de la zone de rendu.

void GTexteDeRendu::display()
{
    texture.create(getWidth(), getHeight());
    
    texture.clear(Color::White);
            
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(_position_x, _position_y);
    
    GFenetre::getWindow()->draw(sprite);
    GFenetre::getWindow()->draw(contours);
}




// Affichage dans texte dans la zone de rendu.

void GTexteDeRendu::display(string texte)
{    
    texture.clear(Color::White);
    
    _text.displayText(texture, texte);
        
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(_position_x, _position_y);
    
    GFenetre::getWindow()->draw(sprite);
    GFenetre::getWindow()->draw(contours);
}
