//
//  sujet.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef sujet_hpp
#define sujet_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>

#include "Mot.hpp"

class Sujet
{
    public :
    
    Sujet(std::string source, std::string sortie, std::vector <Mot> & mots);
    int recuperer_valeur() const { return _valeur; };
    void transforme_groupe_nominal_sujet_en_pronom();
    void creation_du_sujet();
    
    private :
    
    int _valeur;
    
    std::string _langue_source,
                _langue_sortie;
    
    std::vector <Mot> __mots;
    
    std::vector <std::string> __structure_sujet;
};

#endif /* sujet_hpp */
