//
//  auxilliaire.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 26/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Auxiliaire.hpp"

using namespace std;


Auxiliaire::Auxiliaire()
{
    __auxiliaire_etre["A"] = "be";
    __auxiliaire_etre["F"] = "être";
    
    __auxiliaire_avoir["A"] = "have";
    __auxiliaire_avoir["F"] = "avoir";
}




// Détermine la traduction de l'auxilliaire.

void Auxiliaire::construction_auxiliaire(int sujet, string langue, string auxiliaire, string temps)
{
    if (auxiliaire == "être")
    {
        __conjugaison_auxiliaire["present_etre_A"] = __present_etre_A[sujet];
        __conjugaison_auxiliaire["present_etre_F"] = __present_etre_F[sujet];
        
        _auxiliaire = __conjugaison_auxiliaire[temps + "_etre_" + langue];
    }
    
    else if (auxiliaire == "avoir")
    {
        __conjugaison_auxiliaire["present_avoir_A"] = __present_avoir_A[sujet];
        __conjugaison_auxiliaire["present_avoir_F"] = __present_avoir_F[sujet];
        
        _auxiliaire = __conjugaison_auxiliaire[temps + "_avoir_" + langue];
    }
}
