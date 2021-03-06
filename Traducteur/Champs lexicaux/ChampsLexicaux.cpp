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




ChampsLexicaux::ChampsLexicaux(vector <string> champs_lexicaux)
{
    for (int i = 0; i < champs_lexicaux.size(); i++)
    {
        incrementation_du_champ_lexical(champs_lexicaux[i]);
    }
}




ChampsLexicaux & ChampsLexicaux::operator=(ChampsLexicaux champs_lexicaux)
{    
    __liste_champs_lexicaux = champs_lexicaux.__liste_champs_lexicaux;
    
    __champ_lexical_dominant = champs_lexicaux.__champ_lexical_dominant;
   
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




void ChampsLexicaux::recuperation_plus_grand_champ_lexical_commun(ChampsLexicaux & champs_lexicaux)
{
    int max = -1;
    
    map <string, int>::iterator it;
    

    for (it = champs_lexicaux.__liste_champs_lexicaux.begin(); it != champs_lexicaux.__liste_champs_lexicaux.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
            
            champs_lexicaux.__champ_lexical_dominant = make_pair(it->first, __liste_champs_lexicaux[it->first]);
        }
    }
}




void ChampsLexicaux::incrementation_du_champ_lexical(string champ_lexical)
{
    if (champ_lexical != "-")
    {
        __liste_champs_lexicaux[champ_lexical]++;
    }
}
