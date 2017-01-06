//
//  passeSimple.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 15/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef passeSimple_hpp
#define passeSimple_hpp

#include <map>
#include <string>
#include <stdio.h>

class PasseSimple
{
    public :
    
    std::string terminaison_passe_simple(int chaine, std::string langue, std::string verbe);
    
    private :
    
    std::map <std::string, std::string> passe_simple;
    
    std::string terminaison_passe_simple_F[10] = {"ais", "as", "a", "a", "a", "ions", "iez", "èrent", "èrent"};
};

#endif /* passeSimple_hpp */
