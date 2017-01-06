//
//  presentGr1.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "presentGr1.hpp"

using namespace std;


string PresentGr1::terminaison_premier_groupe_present(int sujet, string langue)
{
    premier_groupe["terminaison_present_1_F"] = terminaison_present_1_F[sujet];
    premier_groupe["terminaison_present_1_A"] = terminaison_present_1_A[sujet];
        
    return premier_groupe["terminaison_present_1_" + langue];
}
