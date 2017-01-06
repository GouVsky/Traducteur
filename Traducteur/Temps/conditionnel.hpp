//
//  conditionnel.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 21/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef conditionnel_hpp
#define conditionnel_hpp

#include <map>
#include <string>
#include <stdio.h>

class Conditionnel
{
    public :
    
    std::string terminaison_conditionnel(int chaine, std::string langue);
    
    private :
    
    std::map <std::string, std::string> conditionnel;
    
    std::string terminaison_conditionnel_F[10] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
};

#endif /* conditionnel_hpp */
