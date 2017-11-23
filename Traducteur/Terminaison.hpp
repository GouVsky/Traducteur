//
//  terminaison.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef terminaison_hpp
#define terminaison_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>


class Terminaison
{
    public :
    
    Terminaison();
    std::string recuperer_ancienne_terminaison() const { return _ancienne_terminaison; };
    std::string recuperer_nouvelle_terminaison() const { return _nouvelle_terminaison; };
    void determiner_nouvelle_terminaison(std::string langue, std::string temps, int sujet, int groupe);
    void ancienne_terminaison_troisieme_groupe(std::string verbe);
    void determiner_ancienne_terminaison(std::string langue, std::string verbe, int groupe_verbe);
    
    private :
    
    std::string _nouvelle_terminaison,
                _ancienne_terminaison;
    
    std::map <std::string, std::map <std::string, std::vector <std::string>>> __terminaisons;
};

#endif /* terminaison_hpp */
