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
    __liste_champs_lexicaux["MER"] = 0;
    __liste_champs_lexicaux["NOM"] = 0;
    __liste_champs_lexicaux["CORPS"] = 0;
    __liste_champs_lexicaux["NATURE"] = 0;
    __liste_champs_lexicaux["RESEAU"] = 0;
    __liste_champs_lexicaux["MUSIQUE"] = 0;
    __liste_champs_lexicaux["MOBILIER"] = 0;
    __liste_champs_lexicaux["DISTANCE"] = 0;
    __liste_champs_lexicaux["PRINTEMPS"] = 0;
    __liste_champs_lexicaux["FOURNITURE"] = 0;
    __liste_champs_lexicaux["TU_ES_UN_SORCIER_HARRY"] = 0;
}




// Récupération de la valeur des champs lexicaux.

int ChampsLexicaux::recuperation_valeur_champ_lexical(string champ_lexical)
{
    return __liste_champs_lexicaux[champ_lexical];
}




// Incrémentation des différents champs lexicaux.

void ChampsLexicaux::incrementation_des_champs_lexicaux(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        __liste_champs_lexicaux[champ_lexical]++;
    }
}
