//
//  motInvariable.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 13/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "motInvariable.h"
#include "ResourcePath.hpp"

using namespace std;

// Détermine si le mot est un mot invariable (déterminant, adverbe...).

string Invariable::le_mot_est_invariable(string mot, string l_source, string l_sortie)
{
    langue_source = l_source;
    langue_sortie = l_sortie;

    ifstream fichier_invariables(resourcePath() + "Dictionnaire/invariables.txt");
        
    // Est-ce un mot invariable ?
    
    while(!fichier_invariables.eof())
    {
        fichier_invariables >> invariable["A"] >> invariable["F"];
        
        if(invariable[langue_source] == mot)
        {
            return invariable[langue_sortie];
        }
    }
    
    fichier_invariables.close();
    
    return "MEM2!65oG"; // Si le mot n'est pas invariable.
}
