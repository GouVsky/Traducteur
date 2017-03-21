//
//  image.cpp
//  Traducteur
//
//  Created by Grégoire on 07/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "GImage.hpp"
#include "GFenetre.hpp"
#include "ResourcePath.hpp"

using namespace sf;
using namespace std;


GImage::GImage()
{
    position_x = 0;
    position_y = 0;
    
    position_x_rognage = 0;
    position_y_rognage = 0;
    
    origine_x = 0;
    origine_y = 0;
    
    largeur = 0;
    hauteur = 0;
    
    angle_de_rotation = 0;
    
    coefficient_x = 1;
    coefficient_y = 1;
}




GImage::GImage(string nom_fichier)
{
    texture.loadFromFile(resourcePath() + nom_fichier);
    
    image.setTexture(texture);
    
    position_x = 0;
    position_y = 0;
    
    position_x_rognage = 0;
    position_y_rognage = 0;
    
    origine_x = 0;
    origine_y = 0;
    
    largeur = 0;
    hauteur = 0;
    
    angle_de_rotation = 0;
    
    coefficient_x = 1;
    coefficient_y = 1;
}




// Affiche l'image.

void GImage::afficher()
{
    (GFenetre::getWindow())->draw(image);
}




// Modifie la rotation de l'image.

void GImage::modifier_rotation(float angle)
{
    angle_de_rotation = angle;
    
    image.setRotation(angle_de_rotation);
}




// Définie l'origine de l'image.

void GImage::definir_origine(int x, int y)
{
    origine_x = x;
    
    origine_y = y;
    
    image.setOrigin(origine_x, origine_y);
}




// Redimensionne l'image.

void GImage::redimensionner(float c_x, float c_y)
{
    coefficient_x = c_x;
    
    coefficient_y = c_y;
    
    image.setScale(coefficient_x, coefficient_y);
}




// Rogne l'image.

void GImage::rogner_image(int x, int y, int l, int h)
{
    position_x_rognage = x;
    
    position_y_rognage = y;
    
    largeur = l;
    
    hauteur = h;
    
    image.setTextureRect(IntRect(position_x_rognage, position_y_rognage, largeur, hauteur));
}




// Définie la taille de l'image.

void GImage::definir_taille(int l, int h)
{
    largeur = l;
    
    hauteur = h;
    
    image.setScale(largeur / image.getGlobalBounds().width, hauteur / image.getGlobalBounds().height);
}




// Définie la position de l'image.

void GImage::definir_position(int x, int y)
{
    position_x = x;
    
    position_y = y;
    
    image.setPosition(position_x, position_y);
}

