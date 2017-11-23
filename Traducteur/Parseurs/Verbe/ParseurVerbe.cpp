//
//  ParseurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurVerbe.hpp"

using namespace std;


ParseurVerbe::ParseurVerbe(string langue_source, string langue_sortie, string fichier_formes, Type type) : __etre(langue_source, langue_sortie), __avoir(langue_source, langue_sortie)
{
    _fichier_formes = fichier_formes;
    
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
    
    
    // On récupère les groupes des verbes dans chaque langue.
    
    __groupe["A"] = atoi(&type.propriete()[0]);
    __groupe["F"] = atoi(&type.propriete()[1]);
}




string ParseurVerbe::construire_verbe(string langue, string verbe)
{
    string construction_verbe,
           sauvegarde = verbe;
    
    
    __parseur_forme.parser(__forme[langue]);
    

    string temps = __temps[langue];

    vector <string> forme = __parseur_forme.recuperer_forme();
    

    // On récupère chaque partie qui compose la forme du verbe.

    for (int i = 0; i < forme.size(); i++)
    {
        string partie_forme = forme[i];
        
        
        if (partie_forme == "verbe")
        {
            construction_verbe += verbe;
        }
        
        else if (partie_forme == "radical")
        {
            __terminaison.determiner_ancienne_terminaison(langue, verbe, __groupe[langue]);
            
            sauvegarde.erase(sauvegarde.size() - __terminaison.recuperer_ancienne_terminaison().size());
            
            construction_verbe += sauvegarde;
        }
        
        else if (partie_forme == "terminaison")
        {
            __terminaison.determiner_nouvelle_terminaison(langue, temps, __sujet.recuperer_valeur(), __groupe[langue]);

            construction_verbe += __terminaison.recuperer_nouvelle_terminaison();
        }
        
        else if (partie_forme == "être")
        {
            construction_verbe += __etre.recuperer_auxiliaire_conjugue(langue, "PRE", __sujet.recuperer_valeur());
        }
        
        else if (partie_forme == "avoir")
        {
            construction_verbe += __avoir.recuperer_auxiliaire_conjugue(langue, "PRE", __sujet.recuperer_valeur());
        }
        
        else
        {
            construction_verbe += partie_forme;
        }
    }

    return construction_verbe;
}




bool ParseurVerbe::parser(string mot, vector <Mot> & verbes, vector <Groupe> & groupes, vector <vector <Mot>> & verbes_sorties)
{
    // On détermine le sujet.
    
    __sujet.rechercher_le_sujet(groupes);

    
    bool trouve = false;
    
    size_t nombre_groupes = groupes.size();
    
    size_t nombre_verbes = verbes.size();
    
    
    ifstream fichier_formes(_fichier_formes);
    
    
    while (!fichier_formes.eof() && !trouve)
    {
        fichier_formes >> __temps[_langue_source] >> __temps[_langue_sortie] >> __forme[_langue_source] >> __forme[_langue_sortie];
        
        
        // Pour tous les sens possibles, on teste lequel correspond à celui de la phrase.
        
        for (int i = 0; i < nombre_verbes; i++)
        {
            string verbe_dans_phrase;
            
            string verbe = construire_verbe(_langue_source, verbes[i].recuperer_mot());
            
            size_t taille = count(verbe.begin(), verbe.end(), ' ') + 1;
            
            
            // Comparaison du verbe avec celui de la phrase.
            // On construit le verbe avec les mots précédents et le mot actuel.
            
            size_t indice = nombre_groupes - taille + 1;
            
            
            for (size_t i = indice; i < nombre_groupes; i++)
            {
                verbe_dans_phrase += groupes[i].recuperer_mot_source() + ' ';
            }
            
            verbe_dans_phrase += mot;
            

            if (verbe_dans_phrase == verbe)
            {
                // On supprime les groupes de mots qui font en fait partis du verbe.
                
                groupes.erase(groupes.begin() + indice, groupes.end());
                
                
                size_t nombre_verbes_sorties = verbes_sorties.size();
                
                
                // On conjugue tous les sens du verbe source.
                
                for (int j = 0; j < nombre_verbes_sorties; j++)
                {
                    for (int k = 0; k < verbes_sorties[j].size(); k++)
                    {
                        verbes_sorties[j][k].recuperer_mot() = construire_verbe(_langue_sortie, verbes_sorties[j][k].recuperer_mot());
                    }
                }
                
                trouve = true;
                
                break;
            }
        }
    }
    
    fichier_formes.close();
    
    return trouve;
}
