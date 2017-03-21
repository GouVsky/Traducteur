//
//  curseur.hpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef curseur_hpp
#define curseur_hpp

#include <string>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GCurseur
{
    public :
    
    GCurseur();
    int recuperer_position_y() { return _position_y; };
    int recuperer_position_x() { return _position_x; };
    void modifier_position_y(int y);
    void modifier_position_x(int x);
    void definir_position();
    void definir_couleur();
    void definir_taille();
    void afficher(sf::RenderTexture * texture);
    
    private :

    int _largeur,
        _hauteur,
        _position_x,
        _position_y;
    
    sf::Color _couleur;
    
    sf::RectangleShape _curseur;
};

#endif /* curseur_hpp */
