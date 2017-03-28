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

class PronomPersonnel : public Mot
{
    public :
    
    PronomPersonnel(std::string source, std::string sortie);
    bool est_un_pronom_generique(std::string mot);
    bool existe() const { return _pronom_existe; };
    int recuperer_valeur() const { return _valeur; };
    std::string recuperer_forme_generique() const { return _pronom_personnel_generique; };
    void le_mot_est_un_pronom_personnel(std::string mot);
    
    private :
    
    int _valeur;
    
    bool _pronom_existe;
    
    std::string _langue_source,
                _langue_sortie,
                _pronom_personnel_generique;
    
    std::vector <std::string> __pronoms_personnels_sujets_F,
                              __pronoms_personnels_sujets_A,
                              __pronoms_personnels_generiques;
    
    std::map <std::string, std::vector <std::string>> __pronoms_personnels_sujets;
};

#endif /* PronomPersonnel_hpp */
