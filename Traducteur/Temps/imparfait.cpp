//
//  imparfait.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 08/01/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "imparfait.hpp"

using namespace std;

string Imparfait::terminaison_imparfait(int sujet, string langue)
{
    imparfait["terminaison_imparfait_F"] = terminaison_imparfait_F[sujet];
        
    return imparfait["terminaison_imparfait_" + langue];
}
