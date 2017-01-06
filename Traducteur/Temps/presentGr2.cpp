//
//  presentGr2.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 09/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "presentGr2.hpp"

using namespace std;

string PresentGr2::terminaison_deuxieme_groupe_present(int sujet, string langue)
{
    second_groupe["terminaison_present_2_F"] = terminaison_present_2_F[sujet];
    second_groupe["terminaison_present_2_A"] = terminaison_present_2_A[sujet];
        
    return second_groupe["terminaison_present_2_" + langue];
}
