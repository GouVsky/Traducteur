//
//  passeSimple.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 15/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "passeSimple.hpp"

using namespace std;

string PasseSimple::terminaison_passe_simple(int sujet, string langue, string verbe)
{
    passe_simple["terminaison_passe_simple_F"] = terminaison_passe_simple_F[sujet];

    if(verbe[verbe.size()-1] == 'e')
    {
        passe_simple["terminaison_passe_simple_A"] = 'd';
    }
    
    else passe_simple["terminaison_passe_simple_A"] = "ed";
    
    return passe_simple["terminaison_passe_simple_" + langue];
}
