//
//  futur.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 21/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef futur_hpp
#define futur_hpp

#include <map>
#include <string>
#include <stdio.h>

class Futur
{
    public :
    
    std::string terminaison_futur(int chaine, std::string langue);
    
    private :
    
    std::map <std::string, std::string> futur;
    
    std::string terminaison_futur_F[10] = {"ai", "as", "a", "a", "a", "ons", "ez", "ont", "ont"};
};

#endif /* futur_hpp */
