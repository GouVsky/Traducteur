//
//  AffinagePhrase.cpp
//  Traducteur
//
//  Created by Grégoire on 20/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "NomCommun.hpp"
#include "AffinagePhrase.hpp"

using namespace std;


Affinage::Affinage(string sortie, vector <vector <string>> * phrases, vector <vector <string>> * structure)
{
    _langue_sortie = sortie;
    
    __phrases = phrases;
    
    __structure = structure;
}




void Affinage::accorder_les_mots()
{
    NomCommun nom_commun;
    
    for (int i = 0; i < __phrases->size(); i++)
    {
        for (int j = 0; j < (* __phrases)[i].size(); j++)
        {
            if ((* __structure)[i][j].find("masculin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(&(*__phrases)[i][j], _langue_sortie);
            }
            
            else if ((* __structure)[i][j].find("feminin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(&(* __phrases)[i][j], _langue_sortie);
            }
        }
    }
}




void Affinage::affiner_phrases()
{
    accorder_les_mots();
}
