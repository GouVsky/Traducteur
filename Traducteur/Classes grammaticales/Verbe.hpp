//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

#include "config.hpp"
#include "Terminaison.hpp"


class Verbe
{
    public :
    
    Verbe();
    Verbe(std::string propriete);
    size_t calculer_taille(std::string verbe);
    bool comparer_taille(std::string verbe_compare, std::string verbe_comparant);
    std::vector <std::string> construire_verbe(int langue, std::string verbe, std::vector <std::string> & formes, std::string temps, int groupe,int sujet);
    int recuperer_groupe(int langue) { return __groupe[langue]; }

    private :
    
    std::map <int, int> __groupe;
};

#endif /* verbe_hpp */
