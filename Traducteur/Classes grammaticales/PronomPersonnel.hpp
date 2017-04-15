//
//  PronomPersonnel.hpp
//  Traducteur
//
//  Created by Grégoire on 05/03/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef PronomPersonnel_hpp
#define PronomPersonnel_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

#include "Mot.hpp"

class PronomPersonnel
{
    public :
    
    PronomPersonnel(std::string source, std::string sortie);
    std::string recuperer_pronom_personnel() const { return _pronom_personnel; };
    bool le_mot_est_un_pronom_personnel(std::string mot);
    
    private :
        
    std::string _langue_source,
                _langue_sortie,
                _pronom_personnel;
    
    std::vector <std::string> __pronoms_personnels_sujets_F,
                              __pronoms_personnels_sujets_A;
    
    std::map <std::string, std::vector <std::string>> __pronoms_personnels_sujets;
};

#endif /* PronomPersonnel_hpp */
