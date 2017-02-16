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


Invariable::Invariable(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
    
    nombre_de_mots = 0;
}




int Invariable::recuperer_nombre_de_mots()
{
    return nombre_de_mots;
}




string Invariable::recuperer_mot()
{
    return invariable[langue_sortie];
}




// Détermine si le mot est un mot invariable (déterminant, adverbe...).

void Invariable::le_mot_est_invariable(string mot)
{
    nombre_de_mots = 0;
    
    ifstream fichier_invariables(resourcePath() + "invariables.txt");
        
    // Est-ce un mot invariable ?
    
    while (!fichier_invariables.eof())
    {
        fichier_invariables >> invariable["A"] >> invariable["F"];
        
        if (invariable[langue_source] == mot)
        {
            nombre_de_mots++;
            
            break;
        }
    }
    
    fichier_invariables.close();
}
