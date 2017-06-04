//
//  ParseurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurVerbe.hpp"

using namespace std;


ParseurVerbe::ParseurVerbe(string langue_source, string langue_sortie) : Parseur(), __sujet(langue_source, langue_sortie)
{
    _verbe_trouve = false;

    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




string ParseurVerbe::recuperer_forme_irreguliere(string langue, string verbe)
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
            if (mot == "verbe_et_terminaison")
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
            
            else if (mot == "ing")
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




bool ParseurVerbe::chercher_verbe(string mot, vector <Groupe> & groupes)
{
    string verbe,
           champ_lexical;
    
    
    ifstream fichier(_fichier_forme_verbe);
    
    while (!fichier.eof() && !_verbe_trouve)
    {
        fichier >> _temps_verbe >> __conjugaison["A"] >> __conjugaison["F"];
        
        
        ifstream fichier_verbes(__fichier_verbes);
        
        while (!fichier_verbes.eof() && !_verbe_trouve)
        {
            fichier_verbes >> __verbe["A"] >> __verbe["F"] >> __irregulier["A"] >> __irregulier["F"] >> _type >> _champs_lexicaux >> _groupe;
            
            
            // On récupère l'ensemble des verbes source.
            
            istringstream flux_source(__verbe[_langue_source]);
            
            while (getline(flux_source, verbe, '/'))
            {
                _forme_verbe_source = construire_verbe(_langue_source, verbe);
                
                
                int taille_verbe = (int) count(_forme_verbe_source.begin(), _forme_verbe_source.end(), ' ') + 1;
                
                size_t nombre_groupe = groupes.size();
                
                string verbe_de_la_phrase = "";
                
                // Comparaison du verbe avec celui de la phrase.
                
                // On construit le verbe avec les mots précédents.
                // On ne prend pas en compte le mot en cours.
                
                size_t indice = nombre_groupe - taille_verbe + 1;
                
                for (size_t i = indice; i < nombre_groupe; i++)
                {
                    verbe_de_la_phrase += groupes[i].recuperer_mot_source() + ' ';
                }
                
                verbe_de_la_phrase += mot;
                
                
                // Le verbe construit est identique à celui entré par l'utilisateur.
                
                if (verbe_de_la_phrase == _forme_verbe_source)
                {
                    // On supprime les groupes de mots qui font en fait partis du verbe.
                    
                    groupes.erase(groupes.begin() + indice, groupes.end());
                    
                    
                    parser_mots(__verbe[_langue_sortie]);
                    
                    for (int i = 0; i < recuperer_mots().size(); i++)
                    {
                        for (int j = 0; j < recuperer_mots()[i].size(); j++)
                        {
                            recuperer_mots()[i][j] = construire_verbe(_langue_sortie, recuperer_mots()[i][j]);
                        }
                    }
                    
                    parser_types(_type);
                    
                    parser_champs_lexicaux(_champs_lexicaux);
                    
                    _verbe_trouve = true;
                    
                    break;
                }
            }
        }
        
        fichier_verbes.close();
    }

    fichier.close();
    
    return _verbe_trouve;
}
