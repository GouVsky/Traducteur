//
//  image.hpp
//  Traducteur
//
//  Created by Grégoire on 07/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef image_hpp
#define image_hpp

#include <string>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GImage
{
    public :
    
    GImage();
    GImage(std::string nom_image);
    void afficher();
    void modifier_rotation(float angle);
    void definir_origine(int x, int y);
    void redimensionner(float c_x, float c_y);
    void rogner_image(int x, int y, int l, int h);
    void definir_taille(int l, int h);
    void definir_position(int x, int y);
    
    protected :
    
    int position_x,
        position_y,
        position_x_rognage,
        position_y_rognage,
        origine_x,
        origine_y,
        largeur,
        hauteur,
        angle_de_rotation;
    
    float coefficient_x,
          coefficient_y;
    
    sf::Sprite image;
    sf::Texture texture;
};

#endif /* image_hpp */
