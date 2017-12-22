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




vector <string> ParseurFormeVerbe::parser_forme(string forme)
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
    map <string, string> temps,
                         forme;
    
    
    ifstream fichier_formes(_fichier);

    
    while (!fichier_formes.eof())
    {
        fichier_formes >> temps["A"] >> temps["F"] >> forme["A"] >> forme["F"];
        
        
        __donnees.ajouter_temps(temps[_langue_source], _langue_source);
        
        __donnees.ajouter_forme(parser_forme(forme[_langue_source]), _langue_source);
        
        
        __donnees.ajouter_temps(temps[_langue_sortie], _langue_sortie);
        
        __donnees.ajouter_forme(parser_forme(forme[_langue_sortie]), _langue_sortie);
    }
    
    fichier_formes.close();
}