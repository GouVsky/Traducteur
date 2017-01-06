//
//  Fenetre.hpp
//  Traducteur
//
//  Created by Grégoire on 27/06/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef Fenetre_hpp
#define Fenetre_hpp

#include <map>
#include <ctime>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <locale>
#include <codecvt>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Fenetre
{
    public :
    
    Fenetre();
    void creation_des_boutons();
    void mise_a_jour();
    void chargement_du_texte(std::clock_t debut);
    int creation_de_la_fenetre();
    
    private :

    sf::Font police;
    sf::Image image;
    sf::RenderWindow fenetre;
    sf::Texture langues, icone;
    sf::RenderTexture texture_source, texture_sortie;
    sf::Sprite sprite_source, sprite_sortie, chargement;
    
    bool stop = false;
    int position_a, position_f, position_x = 0, position_y = 0;
    std::vector <std::string> tableau_source, tableau_sortie, structure;
    std::string texte_source, texte_sortie, langue_source, langue_sortie;
};

#endif /* Fenetre_hpp */
