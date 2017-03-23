//
//  zoneTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "GZoneTexte.hpp"

using namespace sf;
using namespace std;


GZoneDeTexte::GZoneDeTexte()
{    
    _width = 0;
    _height = 0;
    
    _position_x = 0;
    _position_y = 0;
}




void GZoneDeTexte::setFont(Font font)
{
    _text.setFont(font);
}




void GZoneDeTexte::setTextSize(int size)
{
    _text.setSize(size);
}




// Définie le contour de la zone de texte.

void GZoneDeTexte::setVisibleContours(bool choice)
{
    if (choice)
    {
        contours.setSize(Vector2f(_width, _height));
        contours.setPosition(_position_x, _position_y);
        contours.setOutlineColor(Color::Black);
        contours.setOutlineThickness(2);
        contours.setFillColor(Color(255, 255, 255, 0));
    }
}




// Définie la position de la zone de texte.

void GZoneDeTexte::setPosition(int x, int y)
{
    _position_x = x;
    
    _position_y = y;
}




void GZoneDeTexte::setHeight(int height)
{
    _height = height;
}




void GZoneDeTexte::setWidth(int width)
{
    _width = width;
}




// Définie la taille de la zone de texte.

void GZoneDeTexte::setSize(int width, int height)
{
    _width = width;
    
    _height = height;
    
    texture.create(_width, _height);
}
