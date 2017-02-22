//
//  zoneTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef zoneTexte_hpp
#define zoneTexte_hpp

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Texte.hpp"


class GZoneDeTexte
{
    public :
    
    GZoneDeTexte();
    void definir_contours_visibles();
    void definir_position(int x, int y);
    void definir_taille(int l, int h);
    
    protected :
    
    GTexte _texte;
    
    sf::Sprite sprite;
    sf::RectangleShape contours;
    sf::RenderTexture texture;
    
    int position_x,
        position_y,
        largeur,
        hauteur;
};

#endif /* zoneTexte_hpp */
