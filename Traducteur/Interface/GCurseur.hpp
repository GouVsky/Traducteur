//
//  curseur.hpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef curseur_hpp
#define curseur_hpp

#include <string>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GCurseur
{
    public :
    
    GCurseur();
    int getPostionY() { return _position_y; };
    int getPositionX() { return _position_x; };
    void setPositionY(int y);
    void setPositionX(int x);
    void setPosition();
    void setColor();
    void setSize();
    void display(sf::RenderTexture * texture);
    
    private :

    int _largeur,
        _hauteur,
        _position_x,
        _position_y;
    
    sf::Color _couleur;
    
    sf::RectangleShape _curseur;
};

#endif /* curseur_hpp */
