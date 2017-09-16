//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Parseur.hpp"

using namespace std;


Parseur::Parseur(string langue_source, string langue_sortie)
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
    
    _fichier = "./Resources/Dictionnaire/mots.txt";
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
        
        Type nouveau_type(types[0], types[1], types[2]);
        
        __types.push_back(nouveau_type);
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
        
        vector <Mot> sens;
        
        
        // On récupère chaque sens qu'un mot peut avoir.
        
        while (getline(flux_sortie, mot, '/'))
        {
            Mot nouveau_mot(mot);
            
            sens.push_back(nouveau_mot);
        }
        
        __mots.push_back(sens);
    }
}




bool Parseur::parser(string mot_a_trouver)
{
    string mot,
           ligne;
    
    bool mot_trouve = false;
    
    
    ifstream fichier(_fichier);
    
    
    while (!fichier.eof() && !mot_trouve)
    {
        fichier >> __mots_fichier["A"] >> __mots_fichier["F"] >> _types >> _champs_lexicaux;
        
        
        string champs_lexicaux;
        
        
        // On récupère l'ensemble des mots sources.
        
        istringstream flux_source(__mots_fichier[_langue_source]);
        
        while (getline(flux_source, mot, '/'))
        {
            // Si le mot entré par l'utilisateur est trouvé dans le fichier.
            
            if (mot == mot_a_trouver)
            {
                parser_mots(__mots_fichier[_langue_sortie]);
                
                parser_types(_types);
                
                parser_champs_lexicaux(_champs_lexicaux);
                
                mot_trouve = true;
                
                break;
            }
        }
    }
    
    fichier.close();
    
    return mot_trouve;
}
