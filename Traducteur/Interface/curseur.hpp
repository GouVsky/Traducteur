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
    void calcul_de_la_position(std::vector <std::string> tableau, std::vector <int> parametres);
    int recuperer_position_y();
    int recuperer_position_x();
    void definir_position(int x, int y, std::vector <std::string> tableau, std::vector <int> parametres);
    void definir_couleur(sf::Color c);
    void definir_taille(int l, int h);
    void afficher(sf::RenderTexture * texture);
    
    private :

    int position_x,
        position_y,
        largeur,
        hauteur;
    
    sf::Color couleur;
    sf::RectangleShape curseur;
};

#endif /* curseur_hpp */
