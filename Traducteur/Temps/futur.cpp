//
//  futur.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 21/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "futur.hpp"

using namespace std;

string Futur::terminaison_futur(int sujet, string langue)
{
    futur["terminaison_futur_F"] = terminaison_futur_F[sujet];
    
    return futur["terminaison_futur_" + langue];
}
