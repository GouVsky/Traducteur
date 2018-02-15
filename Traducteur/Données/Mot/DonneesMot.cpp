//
//  DonneesMot.cpp
//  Traducteur
//
//  Created by Grégoire on 07/12/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "DonneesMot.hpp"

using namespace std;


DonneesMot::DonneesMot() {}




void DonneesMot::ajouter_type(vector <string> types)
{
    Type type(types);
    
    __types.push_back(type);
}




void DonneesMot::ajouter_famille(vector <string> mots, string langue)
{
    Famille famille(mots);
    
    __famille[langue].push_back(famille);
}




void DonneesMot::ajouter_champs_lexicaux(vector <vector <string>> champs_lexicaux)
{
    vector <ChampsLexicaux> champs_lexicaux_par_famille;
    
    
    for (int i = 0; i < champs_lexicaux.size(); i++)
    {
        ChampsLexicaux champs_lexicaux_du_sens(champs_lexicaux[i]);
        
        champs_lexicaux_par_famille.push_back(champs_lexicaux_du_sens);
    }
    
    __champs_lexicaux.push_back(champs_lexicaux_par_famille);
}




void DonneesMot::reinitialisation()
{
    __types.clear();
    
    __famille.clear();

    __champs_lexicaux.clear();
}
