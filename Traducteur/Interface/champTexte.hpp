//
//  champTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef champTexte_hpp
#define champTexte_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class ChampTexte
{
    public :
    
    void easter_egg(sf::RenderTexture * texture, sf::Text texte, std::string mot, int indice_ligne);
    void affichage_des_phrases(sf::RenderTexture &texture,std::vector <std::string> t_justification, int indice_ligne);
    std::vector <std::string> justification_du_texte(std::string phrase, int indice);
    void texte_multilignes(char caractere);
    std::vector <std::string> traitement_des_phrases(sf::Font police_texte, std::string type, std::string texte, sf::RenderTexture * texture, std::vector <std::string> structure);
    
    private :
    
    sf::Text texte;
    sf::Font police;
    
    double numero_couleur = 0.5;
    std::string type_texte, ligne;
    std::vector <std::string> tableau, structure;
    int compteur, compteur_structure, taille, taille_phrase;

    std::map <int, sf::Color> couleur;
};

#endif /* champTexte_hpp */
