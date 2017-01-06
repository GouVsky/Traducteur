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

class Curseur
{
    public :
    
    int get_calcul_position();
    void set_calcul_position(int position_dans_texte, int debut, int fin, int erreur, int coefficient, std::vector <std::string> tableau);
    
    void coloration(sf::Color couleur);
    void set_position(std::string texte_source, int position_dans_phrase, int y);
    void taille(int largeur, int hauteur);
    void creation_curseur(sf::Color couleur, int y, int largeur, int hauteur, std::string texte, int position_dans_phrase);
    sf::RectangleShape affichage(sf::Font police_texte, int position_dans_phrase, std::vector <std::string> tableau);
    
    private :

    int position;
    
    sf::Text texte;
    sf::Font police;
    sf::RectangleShape curseur;
};

#endif /* curseur_hpp */
