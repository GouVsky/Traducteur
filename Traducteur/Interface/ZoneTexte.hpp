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


class GZoneDeTexte
{
    public :
    
    GZoneDeTexte();
    void easter_egg(sf::Text texte, std::string mot, int indice_ligne);
    void affichage_des_phrases(int indice_ligne);
    void justification_du_texte(std::string phrase, int indice);
    void texte_multilignes(char caractere);
    void traitement_des_phrases(std::string texte, sf::RenderTexture * t);
    void effacer_contenu();
    void definir_contours();
    void definir_police(sf::Font police_texte);
    void definir_position(int x, int y);
    void definir_taille(int l, int h);
    
    protected :
    
    sf::Text texte;
    sf::Font police;
    sf::Sprite sprite;
    sf::RectangleShape contour;
    sf::RenderTexture * texture;
    
    int position_x,
        position_y,
        largeur,
        hauteur,
        compteur,
        compteur_structure,
        taille,
        taille_phrase;
    
    std::string ligne,
                texte_source,
                langue_source,
                langue_sortie;
    
    double numero_couleur;
    
    std::map <int, sf::Color> couleur;
    
    std::vector <std::string> tableau, t_justification;
};

#endif /* zoneTexte_hpp */
