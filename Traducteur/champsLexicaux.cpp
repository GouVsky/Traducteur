//
//  champsLexicaux.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 27/04/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "champsLexicaux.hpp"

using namespace std;

int ChampsLexicaux::tableau_des_champs_lexicaux[] = {0};


// Initialisation des champs lexicaux.

void ChampsLexicaux::initialisation()
{
    fill(tableau_des_champs_lexicaux, tableau_des_champs_lexicaux + liste_champs_lexicaux.size(), 0);
}




// Incrémentation des différents champs lexicaux.

void ChampsLexicaux::incrementation_des_champs_lexicaux(string champ_lexical)
{
    tableau_des_champs_lexicaux[liste_champs_lexicaux[champ_lexical]]++;
}




// Récupération de la valeur des champs lexicaux.

int ChampsLexicaux::recuperation_tableau(string champ_lexical)
{
    return tableau_des_champs_lexicaux[liste_champs_lexicaux[champ_lexical]];
}
