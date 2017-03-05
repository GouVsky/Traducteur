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

class PronomPersonnel
{
    public :
    
    PronomPersonnel(std::string source, std::string sortie);
    bool pronom_existe() { return _pronom_existe; };
    std::string recuperer_pronom_personnel_generique() { return _pronom_personnel_generique; };
    std::string recuperer_pronom_personnel() { return _pronom_personnel_traduit; };
    void le_mot_est_un_pronom_personnel(std::string mot);
    
    private :
    
    bool _pronom_existe;
    
    std::string _langue_source,
                _langue_sortie,
                _pronom_personnel_traduit,
                _pronom_personnel_generique;
    
    std::vector <std::string> __pronoms_personnels_sujets_F,
                              __pronoms_personnels_sujets_A;
    
    std::map <std::string, std::vector <std::string>> __pronoms_personnels_sujets;
};

#endif /* PronomPersonnel_hpp */
