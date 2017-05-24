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

#include "GFenetre.hpp"

#include "ResourcePath.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GImage
{
    public :
    
    GImage();
    GImage(std::string nom_image);
    void display();
    void setRotation(float angle);
    void setOrigin(int x, int y);
    void resize(float c_x, float c_y);
    void setROI(int x, int y, int l, int h);
    void setSize(int l, int h);
    void setPosition(int x, int y);
    
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
