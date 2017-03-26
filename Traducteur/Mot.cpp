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
    _nombre_de_sens_source = 0;
    _nombre_de_sens_sortie = 0;
}





// Ajoute tous les champs lexicaux qu'un mot peut posséder.

void Mot::definir_les_differents_champs_lexicaux(string ensemble_champ_lexicaux)
{
    string champ_lexical_du_flux,
    nieme_champ_lexical;
    
    istringstream flux(ensemble_champ_lexicaux);
    
    while (getline(flux, champ_lexical_du_flux, '/'))
    {
        __nombre_de_champs_lexicaux.push_back(0);
        
        __champs_lexicaux.push_back(vector <string> ());
        
        istringstream isoler_champs_lexicaux(champ_lexical_du_flux);
        
        while (getline(isoler_champs_lexicaux, nieme_champ_lexical, '|'))
        {
            __champs_lexicaux[__champs_lexicaux.size() - 1].push_back(nieme_champ_lexical);
            
            __nombre_de_champs_lexicaux[__nombre_de_champs_lexicaux.size() - 1]++;
        }
    }
}




void Mot::definir_les_differents_sens_sortie(string ensemble_mots)
{
    string mot;
    
    istringstream sens(ensemble_mots);
    
    while (getline(sens, mot, '/'))
    {
        _nombre_de_sens_sortie++;
        
        __sens_sortie.push_back(mot);
    }
}




void Mot::definir_les_differents_sens_source(string ensemble_mots)
{
    string mot;
    
    __sens_source.clear();
    
    _nombre_de_sens_source = 0;
    
    istringstream sens(ensemble_mots);
    
    while (getline(sens, mot, '/'))
    {
        _nombre_de_sens_source++;
        
        __sens_source.push_back(mot);
    }
}
