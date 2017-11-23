//
//  auxilliaire.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 26/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef auxilliaire_hpp
#define auxilliaire_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

class Auxiliaire
{
    public :
    
    Auxiliaire(std::string langue_source, std::string langue_sortie);
    std::string recuperer_auxiliaire_conjugue(std::string langue, std::string temps, int sujet) { return (__conjugaison[langue][temps])[sujet]; };
    
    protected :
    
    std::string _langue_source,
                _langue_sortie;
        
    std::map <std::string, std::map <std::string, std::vector <std::string>>> __conjugaison;
};

#endif /* auxilliaire_hpp */
