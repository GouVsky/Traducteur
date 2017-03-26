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


Invariable::Invariable(string source, string sortie) : Mot()
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
        fichier_invariables >> __invariable["A"] >> __invariable["F"] >> _champs_lexicaux;
        
        istringstream iss_langue_source(__invariable[_langue_source]);
        
        while (getline(iss_langue_source, mot_source, '/'))
        {
            if (__invariable[_langue_source] == mot)
            {
                //ajouter_mot(__invariable[_langue_sortie]);
                
                //ajouter_champs_lexicaux(_champs_lexicaux);
                
                break;
            }
        }
    }
    
    fichier_invariables.close();
}
