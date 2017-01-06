//
//  terminaison.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef terminaison_hpp
#define terminaison_hpp

#include <string>
#include <stdio.h>

class Terminaison
{
    public :
    
    std::string construction_de_la_terminaison(int groupe_verbe, std::string temps, int sujet, std::string langue, std::string verbe);
    
    private :
    
    std::string terminaison;
};

#endif /* terminaison_hpp */
