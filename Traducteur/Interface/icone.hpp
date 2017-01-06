//
//  icone.hpp
//  Traducteur
//
//  Created by Grégoire on 27/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef icone_hpp
#define icone_hpp

#include <stdio.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Icone
{
    public :
    
    void creation_bouton_sortie(sf::Sprite * bouton_sortie);
    void selection_du_bouton(sf::Sprite * bouton_source, sf::Sprite * bouton_sortie, std::string source, std::string sortie);
    std::tuple <std::string, std::string> creation_des_boutons(sf::RenderWindow * fenetre, sf::Texture langues, std::string source, std::string sortie);
    
    private :
    
    std::string langue_source, langue_sortie;
    
    sf::Sprite bouton_A, bouton_F, bouton_actif, bouton_actif_sortie, affichage_langue_sortie;
};

#endif /* icone_hpp */
