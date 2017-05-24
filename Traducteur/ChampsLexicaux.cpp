//
//  champsLexicaux.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 27/04/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "ChampsLexicaux.hpp"

using namespace std;


ChampsLexicaux::ChampsLexicaux() {}




int ChampsLexicaux::recuperation_valeur_champ_lexical(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        return __liste_champs_lexicaux[champ_lexical];
    }
    
    else
    {
        return 0;
    }
};




void ChampsLexicaux::incrementation_des_champs_lexicaux(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        __liste_champs_lexicaux[champ_lexical]++;
    }
}
