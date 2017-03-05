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


Affinage::Affinage(string sortie, vector <vector <string>> & phrases, vector <vector <string>> & structure)
{
    _langue_sortie = sortie;
    
    __phrases = phrases;
    
    __structure = structure;
}




// Accord des mots en fonction du genre et du nombre.

void Affinage::accord_des_mots()
{
    NomCommun nom_commun;
    
    for (int i = 0; i < __phrases.size(); i++)
    {
        for (int j = 0; j < __phrases[i].size(); j++)
        {
            if (__structure[i][j].find("masculin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(__phrases[i][j], _langue_sortie);
            }
            
            else if (__structure[i][j].find("feminin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(__phrases[i][j], _langue_sortie);
            }
        }
    }
}




// Réorganise la phrase pour respecter la grammaire de la langue.

void Affinage::nouvelle_organisation()
{
    if (_langue_sortie == "F")
    {
        //
    }
}




// On affine la phrase pour qu'elle soit le plus correcte grammaticalement.

void Affinage::affiner_phrases()
{
    nouvelle_organisation();
    
    accord_des_mots();
}
