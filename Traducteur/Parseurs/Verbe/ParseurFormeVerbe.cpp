//
//  ParseurFormeVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 16/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurFormeVerbe.hpp"

using namespace std;


ParseurFormeVerbe::ParseurFormeVerbe(string fichier)
{
    _fichier = fichier;
}




ParseurFormeVerbe::~ParseurFormeVerbe()
{
}




vector <string> ParseurFormeVerbe::parser_forme(string forme)
{
    string composant_distinct,
           structure_du_composant;
    
    vector <string> forme_decoupee;
    
    
    // On récupère chaque composant distinct du verbe.
    // Il s'agit de tous les mots séparés par un espace.
    
    istringstream forme_verbe(forme);
    
    while (getline(forme_verbe, composant_distinct, '+'))
    {
        // On récupère la structure de chaque composant.
        // Ces différentes structures sont composées des radicaux, des terminaisons, etc.
        
        istringstream structure_moins(composant_distinct);
        
        while (getline(structure_moins, structure_du_composant, '-'))
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




DonneesFormeVerbe ParseurFormeVerbe::parser()
{
    map <int, string> temps,
                      forme;
    
    int langue_source = config::langue_source;
    int langue_sortie = config::langue_sortie;
    
    DonneesFormeVerbe donnees;
    
    ifstream fichier_formes(_fichier);

    
    while (!fichier_formes.eof())
    {
        fichier_formes >> temps[config::ANGLAIS] >> temps[config::FRANCAIS] >> forme[config::ANGLAIS] >> forme[config::FRANCAIS];
        
        
        donnees.ajouter_temps(temps[langue_source], langue_source);
        
        donnees.ajouter_forme(parser_forme(forme[langue_source]), langue_source);
        
        
        donnees.ajouter_temps(temps[langue_sortie], langue_sortie);
        
        donnees.ajouter_forme(parser_forme(forme[langue_sortie]), langue_sortie);
    }
    
    fichier_formes.close();
    
    return donnees;
}
