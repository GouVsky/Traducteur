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

#include "Groupe.hpp"

class Sujet
{
    public :
    
    Sujet(std::string source, std::string sortie);
    int recuperer_valeur() const { return _valeur; };
    void rechercher_le_sujet(std::vector <Groupe> & groupes);
    
    private :
    
    void transformer_le_sujet(int masculin, int feminin);

    
    int _valeur;
    
    std::string _langue_source,
                _langue_sortie;
    
    std::vector <std::string> __structure_sujet;
    
    enum Pronom{JE, TU, IL, ELLE, NEUTRE, NOUS, VOUS, ILS, ELLES};
};

#endif /* sujet_hpp */
