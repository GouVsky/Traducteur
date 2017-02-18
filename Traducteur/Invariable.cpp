//
//  motInvariable.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 13/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "Invariable.h"
#include "ResourcePath.hpp"

using namespace std;


Invariable::Invariable(string source, string sortie, ChampsLexicaux * champs_lexicaux) : Mot(champs_lexicaux)
{
    _langue_source = source;
    _langue_sortie = sortie;
}




// Détermine si le mot est un mot invariable (déterminant, adverbe...).

void Invariable::le_mot_est_invariable(string mot)
{
    string mot_source;
    
    ifstream fichier_invariables(resourcePath() + "invariables.txt");
        
    // Est-ce un mot invariable ?
    
    while (!fichier_invariables.eof())
    {
        fichier_invariables >> invariable["A"] >> invariable["F"];
        
        istringstream iss_langue_source(invariable[_langue_source]);
        
        while (getline(iss_langue_source, mot_source, '/'))
        {
            if (invariable[_langue_source] == mot)
            {
                ajouter_mot(invariable[_langue_sortie]);
                
                break;
            }
        }
    }
    
    fichier_invariables.close();
}