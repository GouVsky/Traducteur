//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Parseur.hpp"

using namespace std;


Parseur::Parseur(string fichier) : __testeur_verbe()
{
    _fichier = fichier;
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
        
        __donnees_mot.ajouter_champs_lexicaux(champs_lexicaux_par_famille);
    }
}




void Parseur::parser_types(string types, int langue)
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
        
        __donnees_mot.ajouter_type(types);
    }
}




void Parseur::parser_mots(string mots, int langue)
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
        
        __donnees_mot.ajouter_famille(sens, langue);
    }
}


#include <iostream>

bool Parseur::parser(string mot_a_trouver, vector <Groupe> & groupes)
{
    bool trouve = false;
    
    int langue_source = config::langue_source;
    int langue_sortie = config::langue_sortie;
    
    ifstream fichier(_fichier);
    

    while (!fichier.eof() && !trouve)
    {
        __donnees_mot.reinitialisation();

        
        fichier >> __mots_fichier[config::ANGLAIS] >> __mots_fichier[config::FRANCAIS] >> _types >> _champs_lexicaux;
        

        parser_mots(__mots_fichier[langue_source], langue_source);
        
        parser_mots(__mots_fichier[langue_sortie], langue_sortie);
        
        parser_types(_types, langue_source);
        
        parser_types(_types, langue_sortie);


        // Si le mot du fichier correspond au mot du texte, on récupère les traductions.
        // Les champs lexicaux et les types ne sont récupérés que maintenant car ils n'étaient pas utiles pour la reconnaissance du mot.

        if ((trouve = __testeur_mot.tester_mot(mot_a_trouver, langue_source, __donnees_mot))
            || (trouve = __testeur_verbe.tester_verbe(mot_a_trouver, groupes, __donnees_mot)))
        {
            parser_champs_lexicaux(_champs_lexicaux);
        }
    }
    
    fichier.close();
    
    return trouve;
}
