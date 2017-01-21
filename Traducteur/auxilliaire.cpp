//
//  auxilliaire.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 26/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "auxilliaire.hpp"

using namespace std;


string Auxilliaire::construction_auxilliaire(int sujet, string langue, string auxilliaire, string temps)
{
    // Verbe "Aller".
    
    conjugaison_auxilliaire["tableau_aller_present_F"] = tableau_aller_present_F[sujet];
    
    // Auxillaire "Avoir".

    conjugaison_auxilliaire["tableau_avoir_present_F"] = tableau_avoir_present_F[sujet];
    conjugaison_auxilliaire["tableau_avoir_present_A"] = tableau_avoir_present_A[sujet];
    
    conjugaison_auxilliaire["tableau_avoir_plus_que_parfait_F"] = tableau_avoir_plus_que_parfait_F[sujet];
    conjugaison_auxilliaire["tableau_avoir_plus_que_parfait_A"] = tableau_avoir_plus_que_parfait_A[sujet];

    // Auxillaire "Etre".

    conjugaison_auxilliaire["tableau_etre_present_F"] = tableau_etre_present_F[sujet];
    conjugaison_auxilliaire["tableau_etre_present_A"] = tableau_etre_present_A[sujet];
    
    return conjugaison_auxilliaire["tableau_" + auxilliaire + "_" + temps + "_" + langue];
}
