//
//  presentGr1.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef presentGr1_hpp
#define presentGr1_hpp

#include <map>
#include <string>
#include <stdio.h>

class PresentGr1
{
    public :
    
    std::string terminaison_premier_groupe_present(int chaine, std::string langue);
    
    private :
    
    std::map <std::string, std::string> premier_groupe;
    
    std::string terminaison_present_1_F[10] = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    std::string terminaison_present_1_A[10] = {"", "", "s", "s", "s", "", "", "", ""};
};

#endif /* presentGr1_hpp */
