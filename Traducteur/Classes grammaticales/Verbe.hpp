//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "Terminaison.hpp"


class Verbe
{
    public :
    
    Verbe();
    size_t calculer_taille(std::string verbe);
    bool comparer_taille(std::string verbe_compare, std::string verbe_comparant);
    std::string construire_verbe(std::string langue, std::string verbe, std::vector <std::string> & formes, std::string temps, int sujet);
    
    private :
    
    Terminaison __terminaison;
};

#endif /* verbe_hpp */
