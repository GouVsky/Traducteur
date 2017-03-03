//
//  Mot.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Mot.hpp"

using namespace std;


Mot::Mot()
{
    _nombre_de_mots = 0;
}




// Ajoute tous les champs lexicaux qu'un mot peut posséder.

void Mot::ajouter_champs_lexicaux(string champs_lexicaux)
{
    string champ_lexical_du_flux,
           nieme_champ_lexical;
    
    istringstream flux(champs_lexicaux);
    
    while (getline(flux, champ_lexical_du_flux, '/'))
    {
        __tableau_champs_lexicaux.push_back(vector <string> ());
        
        __nombre_de_champs_lexicaux.push_back(0);
        
        istringstream isoler_champs_lexicaux(champ_lexical_du_flux);

        while (getline(isoler_champs_lexicaux, nieme_champ_lexical, '|'))
        {            
            __tableau_champs_lexicaux[__tableau_champs_lexicaux.size() - 1].push_back(nieme_champ_lexical);
            
            __nombre_de_champs_lexicaux[__nombre_de_champs_lexicaux.size() - 1]++;
        }
    }
}




// Ajoute tous les sens d'un mot.

void Mot::ajouter_mot(string mots)
{
    string mot_du_flux;
    
    istringstream flux(mots);
    
    while (getline(flux, mot_du_flux, '/'))
    {
        _nombre_de_mots++;
        
        // On ajoute le mot correspondant.
        
        __tableau_mots.push_back(mot_du_flux);
    }
}

