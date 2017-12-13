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
    
    Sujet();
    int recuperer_valeur() { return _valeur; };
    void rechercher_le_sujet(std::vector <Groupe> & groupes);
    
    private :
    
    void transformer_le_sujet(int masculin, int feminin);

    
    int _valeur;
        
    enum Pronom {JE, TU, IL, ELLE, NEUTRE, NOUS, VOUS, ILS, ELLES};
};

#endif /* sujet_hpp */
