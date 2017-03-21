//
//  fenetre.hpp
//  Traducteur
//
//  Created by Grégoire on 05/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef fenetre_hpp
#define fenetre_hpp

#include <string>
#include <stdio.h>

#include "GBouton.hpp"
#include "GZoneTexte.hpp"
#include "GChampTexte.hpp"
#include "GRenduTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GFenetre
{
    public :
    
    GFenetre();
    static sf::Event * getEvent();
    static sf::RenderWindow * getWindow();
    void display();
    void close();
    bool pollEvent(sf::Event & event);
    bool isOpen();
    void clear();
    void create(int width, int height, std::string title = "", sf::Uint32 style = sf::Style::Close);
    
    private :
    
    sf::Texture texture;
    
    sf::Event evenement;
    
    static sf::RenderWindow fenetre;
    
    static std::vector <sf::Event> queue;
        
    static int element_dans_la_queue;
};

#endif /* fenetre_hpp */
