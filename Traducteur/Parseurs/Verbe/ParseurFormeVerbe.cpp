//
//  ParseurFormeVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 16/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurFormeVerbe.hpp"

using namespace std;


ParseurFormeVerbe::ParseurFormeVerbe() {}




void ParseurFormeVerbe::parser(string forme_verbe)
{
    __forme_decoupee.clear();
    
    string composant_distinct,
           structure_du_composant;
    
    
    istringstream forme(forme_verbe);
    
    // On récupère chaque composant distinct du verbe.
    // Il s'agit de tous les mots séparés par un espace.
    
    while (getline(forme, composant_distinct, '+'))
    {
        // On récupère la structure de chaque composant.
        // Ces différentes structures sont composées des radicaux, des terminaisons, etc.
        
        istringstream structure(composant_distinct);
        
        while (getline(structure, structure_du_composant, '-'))
        {
            __forme_decoupee.push_back(structure_du_composant);
        }
        
        __forme_decoupee.push_back(" ");
    }
    
    // On supprime le dernier espace ajouté.
    
    if (__forme_decoupee[__forme_decoupee.size() - 1] == " ")
    {
        __forme_decoupee.pop_back();
    }
}
