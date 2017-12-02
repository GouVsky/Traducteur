//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Parseur.hpp"

using namespace std;


Parseur::Parseur(string langue_source, string langue_sortie, string fichier)
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
    
    _fichier = fichier;
}




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
    string type_par_famille,
           type;
    
    __types.clear();
    
    
    // On récupère le type de chaque sens.
    
    istringstream flux_type_par_famille(types);
    
    while (getline(flux_type_par_famille, type_par_famille, '|'))
    {
        istringstream flux_type(type_par_famille);
        
        vector <string> types;
        
        
        // On récupère la classe, la catégorie ainsi que les propriétés.
        
        while (getline(flux_type, type, '_'))
        {
            types.push_back(type);
        }
        
        Type nouveau_type(types);
        
        __types.push_back(nouveau_type);
    }
}




void Parseur::parser_mots(string mots, vector <vector <Mot>> & tableau)
{
    string mot,
           famille;
    
    tableau.clear();
    
    
    // On commence par récupérer chaque famille.
    
    istringstream flux_famille(mots);
    
    while (getline(flux_famille, famille, '|'))
    {
        istringstream flux_sortie(famille);
        
        vector <Mot> sens;
        
        
        // On récupère ensuite chaque mot de chaque famille.
        
        while (getline(flux_sortie, mot, '/'))
        {
            Mot nouveau_mot(mot);
            
            sens.push_back(nouveau_mot);
        }
        
        tableau.push_back(sens);
    }
}




bool Parseur::parser(string mot_a_trouver, vector <Groupe> & groupes)
{
    string mot;
    
    bool trouve = false;
    
    ifstream fichier(_fichier);
    

    while (!fichier.eof() && !trouve)
    {
        fichier >> __mots_fichier["A"] >> __mots_fichier["F"] >> _types >> _champs_lexicaux;
        

        // On récupère l'ensemble des mots sources.

        parser_mots(__mots_fichier[_langue_source], __mots_sources);
        
        size_t nombre_familles = __mots_sources.size();

        
        // On récupère les différents types.
        
        parser_types(_types);
        
        size_t nombre_types = __types.size();
        

        for (int i = 0; i < nombre_types && !trouve; i++)
        {
            for (int j = 0; j < nombre_familles; j++)
            {
                for (int k = 0; k < __mots_sources[j].size(); k++)
                {
                    // Dans le cas où le mot est un verbe,
                    // on le conjugue pour vérifier s'il s'agit de celui de la phrase.
                    
                    if (__types[i].classe() == "VERBE")
                    {
                        parser_mots(__mots_fichier[_langue_sortie], __mots_sorties);
                        
                        
                        ParseurVerbe parseur_verbe(_langue_source, _langue_sortie, __types[i]);
                        
                        
                        if (parseur_verbe.parser(mot_a_trouver, __mots_sources[j], groupes, __mots_sorties))
                        {
                            parser_champs_lexicaux(_champs_lexicaux);
                            
                            
                            trouve = true;
                            
                            break;
                        }
                    }
                    
                    else if (__mots_sources[j][k].recuperer_mot() == mot_a_trouver)
                    {
                        parser_mots(__mots_fichier[_langue_sortie], __mots_sorties);
                        
                        parser_champs_lexicaux(_champs_lexicaux);
                        
                        
                        trouve = true;
                        
                        break;
                    }
                }
            }
        }
    }
    
    fichier.close();
    
    return trouve;
}
