//
//  imparfait.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 08/01/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef imparfait_hpp
#define imparfait_hpp

#include <map>
#include <string>
#include <stdio.h>

class Imparfait
{
    public :
    
    std::string terminaison_imparfait(int chaine, std::string langue);
    
    private :
    
    std::map <std::string, std::string> imparfait;
    
    std::string terminaison_imparfait_F[10] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
};

#endif /* imparfait_hpp */
