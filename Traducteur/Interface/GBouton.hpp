//
//  bouton.hpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef bouton_hpp
#define bouton_hpp

#include <string>
#include <stdio.h>

#include "GImage.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GBouton : public GImage
{
    public :
    
    GBouton();
    GBouton(std::string);
    void setImage(std::string);
    bool isHovered();
    bool isPressed();
    void setColor(sf::Color c);
    
    private :
    
    sf::Color couleur;
};

#endif /* bouton_hpp */
