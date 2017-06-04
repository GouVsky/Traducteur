//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Parseur.hpp"

using namespace std;


Parseur::Parseur() {}




void Parseur::parser_champs_lexicaux(string champs_lexicaux)
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
}



void Parseur::parser_types(string types)
{
    string type;
    
    
    // On récupère le type de chaque sens.
    
    istringstream flux_type(types);
    
    while (getline(flux_type, type, '|'))
    {
        __types.push_back(type);
    }
}



void Parseur::parser_mots(string mots)
{
    string mot,
           famille;
    
    
    // On récupère l'ensemble des mots traduits.
    // On commence par récupérer chaque famille.
    
    istringstream flux_famille(mots);
    
    while (getline(flux_famille, famille, '|'))
    {
        istringstream flux_sortie(famille);
        
        vector <string> sens;
        
        
        // On récupère chaque sens qu'un mot peut avoir.
        
        while (getline(flux_sortie, mot, '/'))
        {
            sens.push_back(mot);
        }
        
        __mots.push_back(sens);
    }
}
