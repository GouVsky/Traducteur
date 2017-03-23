//
//  zoneTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef zoneTexte_hpp
#define zoneTexte_hpp

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

#include "GTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GZoneDeTexte
{
    public :
    
    GZoneDeTexte();
    void setFont(sf::Font font);
    void setTextSize(int size);
    void setVisibleContours(bool choice = true);
    void setPosition(int x, int y);
    int getHeight() { return _height; };
    int getWidth() { return _width; };
    void setHeight(int height);
    void setWidth(int width);
    void setSize(int width, int height);
    
    protected :
    
    int _position_x,
        _position_y,
        _width,
        _height;
    
    GTexte _text;
    
    sf::Sprite sprite;
    
    sf::RenderTexture texture;
    
    sf::RectangleShape contours;
};

#endif /* zoneTexte_hpp */
