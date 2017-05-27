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




ChampsLexicaux & ChampsLexicaux::operator=(ChampsLexicaux champs_lexicaux)
{
    __liste_champs_lexicaux = champs_lexicaux.__liste_champs_lexicaux;
   
    return * this;
}




ChampsLexicaux ChampsLexicaux::operator+(ChampsLexicaux champs_lexicaux)
{
    map <string, int>::iterator it;
    
    
    for (it = champs_lexicaux.__liste_champs_lexicaux.begin(); it != champs_lexicaux.__liste_champs_lexicaux.end(); it++)
    {
        __liste_champs_lexicaux[it->first] += it->second;
    }

    return * this;
}




pair <int, string> ChampsLexicaux::recuperation_plus_grand_champ_lexical_commun(ChampsLexicaux champs_lexicaux)
{
    int max_comparant = 0,
        max_compare = 0;
    
    string champ_lexical;
    
    map <string, int>::iterator it;
    

    for (it = champs_lexicaux.__liste_champs_lexicaux.begin(); it != champs_lexicaux.__liste_champs_lexicaux.end(); it++)
    {
        if (it->second > max_comparant)
        {
            max_comparant = it->second;
            
            max_compare = __liste_champs_lexicaux[it->first];
            
            champ_lexical = it->second;
        }
    }
    
    return make_pair(max_compare, champ_lexical);
}




void ChampsLexicaux::incrementation_du_champ_lexical(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        __liste_champs_lexicaux[champ_lexical]++;
    }
}
