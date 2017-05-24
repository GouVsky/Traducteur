//
//  champTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef champTexte_hpp
#define champTexte_hpp

#include <string>
#include <vector>
#include <locale>
#include <stdio.h>

#include "GFenetre.hpp"
#include "GCurseur.hpp"
#include "GZoneTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GChampDeTexte : public GZoneDeTexte
{
    public :
    
    GChampDeTexte();
    std::string getText() { return texte_source + '\0'; };
    void deleteContent();
    void display();
    
    private :
    
    void treatment();
        
    GCurseur _curseur;
    
    sf::String texte;
    
    std::string texte_source;
};

#endif /* champTexte_hpp */
