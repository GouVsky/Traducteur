//
//  renduTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef renduTexte_hpp
#define renduTexte_hpp

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

#include "ZoneTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GTexteDeRendu : public GZoneDeTexte
{
    public :
    
    GTexteDeRendu();
    void afficher();
    void afficher(std::string texte);
    
    private :
    
    sf::RenderTexture texture;
};

#endif /* renduTexte_hpp */
