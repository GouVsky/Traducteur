//
//  Texte.hpp
//  Traducteur
//
//  Created by Grégoire on 22/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Texte_hpp
#define Texte_hpp

#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define DEBUT_TEXTE 30
#define FIN_TEXTE 1000 - 50

class GTexte
{
    public :
    
    GTexte();
    //void easter_egg();
    void affichage_des_phrases();
    void justification_du_texte();
    void texte_multilignes();
    void afficher_texte(sf::RenderTexture * texture, std::string texte);
    
    private :
    
    sf::Text _texte;
    sf::Font _police;
    sf::RenderTexture * _texture;
    
    int _nombre_de_phrases;
    
    std::string _texte_source;
    
    std::vector <std::string> __phrases;
    
    std::vector <std::vector <std::string>> __phrases_justifiees;
};

#endif /* Texte_hpp */
