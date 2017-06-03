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




vector <vector <ChampsLexicaux>> & ParseurChampsLexicaux::parser(string champs_lexicaux)
{
    string sens,
           famille,
           champ_lexical;
    
    __champs_lexicaux.clear();
    

    istringstream flux_famille(champs_lexicaux);
    
    // On récupère les champs lexicaux de chaque famille.
    
    while (getline(flux_famille, famille, '|'))
    {
        istringstream flux_sens(famille);
        
        vector <ChampsLexicaux> champs_lexicaux_par_famille;

        
        // On récupère les champs lexicaux de chaque sens.
        
        while (getline(flux_sens, sens, '/'))
        {
            istringstream flux_champ_lexical(sens);
            
            ChampsLexicaux champs_lexicaux_par_sens;
            
            
            // On récupère chaque champ lexical.

            while(getline(flux_champ_lexical, champ_lexical, ','))
            {
                champs_lexicaux_par_sens.incrementation_du_champ_lexical(champ_lexical);
            }
            
            champs_lexicaux_par_famille.push_back(champs_lexicaux_par_sens);
        }
        
        __champs_lexicaux.push_back(champs_lexicaux_par_famille);
    }
    
    return __champs_lexicaux;
}
