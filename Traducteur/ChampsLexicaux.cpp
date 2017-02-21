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
    __tableau_des_champs_lexicaux.resize(__liste_champs_lexicaux.size(), 0);
}




// Récupération de la valeur des champs lexicaux.

int ChampsLexicaux::recuperation_valeur_champ_lexical(string champ_lexical)
{
    return __tableau_des_champs_lexicaux[__liste_champs_lexicaux[champ_lexical]];
}




// Incrémentation des différents champs lexicaux.

void ChampsLexicaux::incrementation_des_champs_lexicaux(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        __tableau_des_champs_lexicaux[__liste_champs_lexicaux[champ_lexical]]++;
    }
}
