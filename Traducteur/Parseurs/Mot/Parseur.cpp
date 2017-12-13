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
    
    __donnees = new DonneesMot(_langue_source, _langue_sortie);
}




Parseur::~Parseur()
{
    delete __donnees;
}




bool Parseur::tester_mot(string mot)
{
    bool trouve = false;
    
    size_t nombre_familles = __donnees->recuperer_nombre_familles(_langue_source);
    
    
    for (int famille = 0; famille < nombre_familles && !trouve; famille++)
    {
        size_t nombre_sens = __donnees->recuperer_nombre_sens(_langue_source, famille);
        

        for (int sens = 0; sens < nombre_sens; sens++)
        {
            if (__donnees->recuperer_type(famille).classe() == "VERBE")
            {
                //
            }
            
            else if (__donnees->recuperer_famille(_langue_source, famille).recuperer_mots()[sens].recuperer_mot() == mot)
            {
                trouve = true;
                
                break;
            }
        }
    }
    
    return trouve;
}




void Parseur::parser_champs_lexicaux(string champs_lexicaux)
{
    string sens,
           famille,
           champ_lexical;
    
    
    istringstream flux_famille(champs_lexicaux);
    
    // On récupère les champs lexicaux de chaque famille.
    
    while (getline(flux_famille, famille, '|'))
    {
        istringstream flux_sens(famille);
        
        vector <vector <string>> champs_lexicaux_par_famille;
        
        
        // On récupère les champs lexicaux de chaque sens.
        
        while (getline(flux_sens, sens, '/'))
        {
            istringstream flux_champ_lexical(sens);
            
            vector <string> champs_lexicaux_par_sens;
            
            
            // On récupère chaque champ lexical.
            
            while (getline(flux_champ_lexical, champ_lexical, ','))
            {
                champs_lexicaux_par_sens.push_back(champ_lexical);
            }
            
            champs_lexicaux_par_famille.push_back(champs_lexicaux_par_sens);
        }
        
        __donnees->ajouter_champs_lexicaux(champs_lexicaux_par_famille);
    }
}




void Parseur::parser_types(string types, string langue)
{
    string type_par_famille,
           type;
    
    
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
        
        __donnees->ajouter_type(types);
    }
}




void Parseur::parser_mots(string mots, string langue)
{
    string mot,
           famille;
    
    
    // On commence par récupérer chaque famille.
    
    istringstream flux_famille(mots);
    
    while (getline(flux_famille, famille, '|'))
    {
        istringstream flux_sortie(famille);
        
        vector <string> sens;
        
        
        // On récupère ensuite chaque mot de chaque famille.
        
        while (getline(flux_sortie, mot, '/'))
        {
            sens.push_back(mot);
        }
        
        __donnees->ajouter_famille(sens, langue);
    }
}




bool Parseur::parser(string mot_a_trouver, vector <Groupe> & groupes)
{
    bool trouve = false;
    
    ifstream fichier(_fichier);
    

    while (!fichier.eof() && !trouve)
    {
        fichier >> __mots_fichier["A"] >> __mots_fichier["F"] >> _types >> _champs_lexicaux;
        

        parser_mots(__mots_fichier[_langue_source], _langue_source);

        parser_types(_types, _langue_source);

        
        if ((trouve = tester_mot(mot_a_trouver)))
        {
            parser_mots(__mots_fichier[_langue_sortie], _langue_sortie);
            
            parser_types(_types, _langue_sortie);
            
            parser_champs_lexicaux(_champs_lexicaux);
        }
        
        else
        {
            __donnees->~DonneesMot();
            
            __donnees = new DonneesMot(_langue_source, _langue_sortie);
        }
    }
    
    fichier.close();
    
    return trouve;
}
