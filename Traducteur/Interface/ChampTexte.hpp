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

#include "Curseur.hpp"
#include "ZoneTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GChampDeTexte : public GZoneDeTexte
{
    public :
    
    GChampDeTexte();
    std::string recuperer_texte() { return texte_source + '\0'; };
    void traitement();
    void effacer_contenu();
    void afficher();
    
    private :
    
    GCurseur _curseur;
    
    sf::String texte;
    
    std::string texte_source;
};

#endif /* champTexte_hpp */
