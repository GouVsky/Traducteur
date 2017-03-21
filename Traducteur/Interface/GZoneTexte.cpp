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
    largeur = 0;
    hauteur = 0;
    
    position_x = 0;
    position_y = 0;
}




// Définie le contour de la zone de texte.

void GZoneDeTexte::setVisibleContours(bool choice)
{
    if (choice)
    {
        contours.setSize(Vector2f(largeur, hauteur));
        contours.setPosition(position_x, position_y);
        contours.setOutlineColor(Color::Black);
        contours.setOutlineThickness(2);
        contours.setFillColor(Color(255, 255, 255, 0));
    }
}




// Définie la position de la zone de texte.

void GZoneDeTexte::setPosition(int x, int y)
{
    position_x = x;
    
    position_y = y;
}




// Définie la taille de la zone de texte.

void GZoneDeTexte::setSize(int l, int h)
{
    largeur = l;
    
    hauteur = h;
    
    texture.create(largeur, hauteur);
}
