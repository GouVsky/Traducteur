//
//  ParseurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurVerbe.hpp"

using namespace std;


ParseurVerbe::ParseurVerbe(string langue_source, string langue_sortie, Type type) : __parseur_forme(langue_source, langue_sortie, "./Resources/Dictionnaire/Verbes/formes.txt"), __etre(langue_source, langue_sortie), __avoir(langue_source, langue_sortie)
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
    
    
    // On récupère les groupes des verbes dans chaque langue.
    
    __groupe["A"] = atoi(&type.propriete()[0]);
    __groupe["F"] = atoi(&type.propriete()[1]);
}




string ParseurVerbe::construire_verbe(string langue, string verbe, vector <string> & formes, string temps)
{
    string construction_verbe,
           sauvegarde = verbe;
    

    // On récupère chaque partie qui compose la forme du verbe.

    for (int i = 0; i < formes.size(); i++)
    {
        string partie_forme = formes[i];
        
        
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

    
    string sauvegarde_temps;
    
    vector <string> sauvegarde_forme;

    bool trouve = false;
    
    size_t taille_max = 0,
           indice_final = 0;
    
    size_t nombre_groupes = groupes.size();
    
    size_t nombre_verbes = verbes.size();
    
    
    __parseur_forme.parser();
    

    size_t nombre_formes = __parseur_forme.recuperer_formes(_langue_source).size();
    
    
    // Pour tous les sens possibles, on teste lequel correspond à celui de la phrase.
    
    for (int i = 0; i < nombre_verbes; i++)
    {
        for (int j = 0; j < nombre_formes; j++)
        {
            string verbe_dans_phrase;
            
            string verbe = construire_verbe(_langue_source, verbes[i].recuperer_mot(), __parseur_forme.recuperer_formes(_langue_source)[j], __parseur_forme.recuperer_temps(_langue_source)[j]);
            
            size_t taille = count(verbe.begin(), verbe.end(), ' ') + 1;
            
            
            // Comparaison du verbe avec celui de la phrase.
            // On construit le verbe avec les mots précédents et le mot actuel.
            
            size_t indice = nombre_groupes - taille + 1;
            
            
            for (size_t k = indice; k < nombre_groupes; k++)
            {
                verbe_dans_phrase += groupes[k].recuperer_mot_source() + ' ';
            }
            
            verbe_dans_phrase += mot;
            
            
            // On récupère toujours la forme du verbe la plus grande.
            
            if (verbe_dans_phrase == verbe && taille > taille_max)
            {
                taille_max = taille;
                
                indice_final = indice;
                
                sauvegarde_forme = __parseur_forme.recuperer_formes(_langue_sortie)[j];
                
                sauvegarde_temps = __parseur_forme.recuperer_temps(_langue_sortie)[j];
                
                trouve = true;
            }
        }
    }
    
    if (trouve)
    {
        // On supprime les groupes de mots qui font en fait partis du verbe.
        
        groupes.erase(groupes.begin() + indice_final, groupes.end());
        
        
        // On conjugue tous les sens du verbe source.
        
        for (int j = 0; j < verbes_sorties.size(); j++)
        {
            for (int k = 0; k < verbes_sorties[j].size(); k++)
            {
                verbes_sorties[j][k].recuperer_mot() = construire_verbe(_langue_sortie, verbes_sorties[j][k].recuperer_mot(), sauvegarde_forme, sauvegarde_temps);
            }
        }
    }
    
    return trouve;
}
