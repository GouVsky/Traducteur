//
//  ParseurFormeVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 16/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurFormeVerbe.hpp"

using namespace std;


ParseurFormeVerbe::ParseurFormeVerbe(string langue_source, string langue_sortie, string fichier)
{
    _fichier = fichier;
    
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




vector <string> ParseurFormeVerbe::recuperer_composants_forme(string forme)
{
    string composant_distinct,
           structure_du_composant;
    
    vector <string> forme_decoupee;
    
    
    istringstream forme_verbe(forme);
    
    // On récupère chaque composant distinct du verbe.
    // Il s'agit de tous les mots séparés par un espace.
    
    while (getline(forme_verbe, composant_distinct, '+'))
    {
        // On récupère la structure de chaque composant.
        // Ces différentes structures sont composées des radicaux, des terminaisons, etc.
        
        istringstream structure(composant_distinct);
        
        while (getline(structure, structure_du_composant, '-'))
        {
            forme_decoupee.push_back(structure_du_composant);
        }
        
        forme_decoupee.push_back(" ");
    }
    
    // On supprime le dernier espace ajouté.
    
    if (forme_decoupee[forme_decoupee.size() - 1] == " ")
    {
        forme_decoupee.pop_back();
    }
    
    return forme_decoupee;
}




void ParseurFormeVerbe::parser()
{
    ifstream fichier_formes(_fichier);
    
    
    map <string, string> temps,
                         forme;
    
    
    while (!fichier_formes.eof())
    {
        fichier_formes >> temps[_langue_source] >> temps[_langue_sortie] >> forme[_langue_source] >> forme[_langue_sortie];
        
        
        __temps[_langue_source].push_back(temps[_langue_source]);
        
        __formes_decoupees[_langue_source].push_back(recuperer_composants_forme(forme[_langue_source]));

        
        __temps[_langue_sortie].push_back(temps[_langue_sortie]);

        __formes_decoupees[_langue_sortie].push_back(recuperer_composants_forme(forme[_langue_sortie]));
    }
    
    fichier_formes.close();
}
