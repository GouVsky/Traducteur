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

#include "config.hpp"
#include "Groupe.hpp"


class Sujet
{
    public :
    
    int static recuperer_valeur_sujet(std::vector <Groupe> & groupes);
    
    private :
    
    int static transformer_le_sujet(int masculin, int feminin);

    
    enum __pronoms {JE, TU, IL, ELLE, NEUTRE, NOUS, VOUS, ILS, ELLES};
};

#endif /* sujet_hpp */
