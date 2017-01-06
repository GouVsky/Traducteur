//
//  presentGr2.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 09/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef presentGr2_hpp
#define presentGr2_hpp

#include <map>
#include <string>
#include <stdio.h>

class PresentGr2
{
    public :
    
    std::string terminaison_deuxieme_groupe_present(int chaine, std::string langue);
    
    private :
    
    std::map <std::string, std::string> second_groupe;
    
    std::string terminaison_present_2_F[10] = {"is", "is", "it", "it", "it", "issons", "issez", "issent", "issent"};
    std::string terminaison_present_2_A[10] = {"", "", "s", "s", "s", "", "", "", ""};
};

#endif /* presentGr2_hpp */
