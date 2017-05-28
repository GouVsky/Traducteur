//
//  ParseurChampsLexicaux.cpp
//  Traducteur
//
//  Created by Grégoire on 28/05/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurChampsLexicaux.hpp"

using namespace std;


ParseurChampsLexicaux::ParseurChampsLexicaux() {}




vector <ChampsLexicaux> ParseurChampsLexicaux::parser(string champs_lexicaux)
{
    string champ_lexical;
    
    __champs_lexicaux.clear();
    

    istringstream flux_champs_lexicaux(champs_lexicaux);
    
    // On récupère les champs lexicaux de chaque sens.

    while (getline(flux_champs_lexicaux, champs_lexicaux, '/'))
    {
        istringstream flux(champs_lexicaux);
        
        ChampsLexicaux champs_lexicaux_par_sens;
        
        // On récupère chaque champ lexical de chaque sens.
        
        while (getline(flux, champ_lexical, '|'))
        {
            champs_lexicaux_par_sens.incrementation_du_champ_lexical(champ_lexical);
        }
        
        __champs_lexicaux.push_back(champs_lexicaux_par_sens);
    }
    
    return __champs_lexicaux;
}
