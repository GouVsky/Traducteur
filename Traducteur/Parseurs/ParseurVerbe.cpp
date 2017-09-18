//
//  ParseurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurVerbe.hpp"

using namespace std;


ParseurVerbe::ParseurVerbe(string langue_source, string langue_sortie, string fichier_formes) : __sujet(langue_source, langue_sortie)
{
    _fichier_formes = fichier_formes;
    
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




/*string ParseurVerbe::recuperer_forme_irreguliere(string langue, string verbe)
{
    string irregularite;
    
    ifstream fichier_verbes_irreguliers(_fichier_verbes_irreguliers + langue + ".txt");
    
    while (!fichier_verbes_irreguliers.eof())
    {
        fichier_verbes_irreguliers >> __irregularite["infinitif"] >> __irregularite["passe_simple"] >> __irregularite["participe_passe"];
        
        if (__irregularite["infinitif"] == verbe)
        {
            irregularite = __irregularite[_temps_verbe];
            
            break;
        }
    }
    
    fichier_verbes_irreguliers.close();
    
    return irregularite;
}
*/




string ParseurVerbe::construire_verbe(string langue, string verbe)
{
    string mot,
           construction_verbe,
           copie_verbe = verbe,
           mot_constituant_le_verbe;
    
    istringstream iss(__conjugaison[langue]);
    
    // Construction du verbe.
    
    while (getline(iss, mot_constituant_le_verbe, '+'))
    {
        istringstream iss_bis(mot_constituant_le_verbe);
        
        while (getline(iss_bis, mot, '-'))
        {
            /*if (mot == "verbe_et_terminaison")
            {
                if (__irregularite[langue] == "o")
                {
                    construction_verbe += recuperer_forme_irreguliere(langue, verbe);
                }
                
                else
                {
                    __terminaison.determiner_nouvelle_terminaison(langue, verbe, _temps_verbe, __sujet.recuperer_valeur(), _groupe);
                    
                    construction_verbe += verbe + __terminaison.recuperer_nouvelle_terminaison();
                }
            }
            
            else*/ if (mot == "ing")
            {
                construction_verbe += mot;
            }
            
            else if (mot == "verbe")
            {
                construction_verbe += verbe;
            }
            
            else if (mot == "radical")
            {
                __terminaison.determiner_ancienne_terminaison(langue, verbe, _groupe);
                
                copie_verbe.erase(copie_verbe.size() - __terminaison.recuperer_ancienne_terminaison().size());
                
                construction_verbe += copie_verbe;
            }
            
            else if (mot == "terminaison")
            {
                __terminaison.determiner_nouvelle_terminaison(langue, verbe, _temps_verbe, __sujet.recuperer_valeur(), _groupe);
                
                construction_verbe += __terminaison.recuperer_nouvelle_terminaison();
            }
            
            else if (mot == "avoir" || mot == "être" || mot == "aller")
            {
                __auxiliaire.construction_auxiliaire(__sujet.recuperer_valeur(), langue, mot, _temps_verbe);
                
                construction_verbe += __auxiliaire.recuperer_auxiliaire();
            }
            
            // To, will, would...
            
            else
            {
                construction_verbe += mot;
            }
        }
        
        construction_verbe += ' ';
    }
    
    construction_verbe.erase(construction_verbe.size() - 1);
    
    return construction_verbe;
}




bool ParseurVerbe::parser(string mot, vector <Mot> & verbes, vector <Groupe> & groupes, vector <vector <Mot>> & verbes_sorties)
{
    // On détermine le sujet.
    
    __sujet.rechercher_le_sujet(groupes);

    
    bool trouve = false;
    
    size_t nombre_groupes = groupes.size();
    
    ifstream fichier(_fichier_formes);
    
    
    while (!fichier.eof() && !trouve)
    {
        fichier >> _temps_verbe >> __conjugaison["A"] >> __conjugaison["F"];
        
        
        size_t nombre_verbes = verbes.size();
        
        
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
    
    return trouve;
}
