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

#include "image.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GBouton : public GImage
{
    public :
    
    GBouton();
    GBouton(std::string);
    void definir_image(std::string);
    bool est_survole();
    bool est_presse();
    void definir_couleur(sf::Color c);
    
    private :
    
    sf::Color couleur;
};

#endif /* bouton_hpp */
