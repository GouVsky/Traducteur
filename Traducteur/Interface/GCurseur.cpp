//
//  curseur.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "GCurseur.hpp"

using namespace sf;
using namespace std;


GCurseur::GCurseur()
{
    _largeur = 3;
    _hauteur = 50;
    
    _position_x = 0;
    _position_y = 0;
    
    _couleur = Color::Black;
}




// Modifie l'ordonnée du curseur.

void GCurseur::modifier_position_y(int y)
{
    _position_y += y;
}




// Modifie l'abscisse du curseur.

void GCurseur::modifier_position_x(int x)
{
    _position_x += x;
}




// Définie la position du curseur selon où l'on se situe dans la phrase.

void GCurseur::definir_position()
{
    _curseur.setPosition(Vector2f(_position_x + 30, _position_y * 45 + 20));
}




// Définie la couleur du curseur.

void GCurseur::definir_couleur()
{
    _curseur.setFillColor(_couleur);
}




// Définie la taille du curseur.

void GCurseur::definir_taille()
{
    _curseur.setSize(Vector2f(_largeur, _hauteur));
}




// Affichage du curseur.

void GCurseur::afficher(RenderTexture * texture)
{
    definir_taille();
    definir_couleur();
    definir_position();
    
    texture->draw(_curseur);
}
