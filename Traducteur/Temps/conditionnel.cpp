//
//  conditionnel.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 21/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "conditionnel.hpp"

using namespace std;


string Conditionnel::terminaison_conditionnel(int sujet, string langue)
{
    conditionnel["terminaison_conditionnel_F"] = terminaison_conditionnel_F[sujet];
    
    return conditionnel["terminaison_conditionnel_" + langue];
}
