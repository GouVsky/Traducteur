//
//  champsLexicaux.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 27/04/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "ChampsLexicaux.hpp"

using namespace std;


// Initialisation des champs lexicaux.

ChampsLexicaux::ChampsLexicaux()
{
    tableau_des_champs_lexicaux.resize(liste_champs_lexicaux.size(), 0);
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
