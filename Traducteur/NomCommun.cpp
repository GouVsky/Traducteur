//
//  nomCommun.cpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "NomCommun.hpp"
#include "ResourcePath.hpp"

using namespace std;


NomCommun::NomCommun(string source, string sortie, ChampsLexicaux * champ_lexical) : Mot(champ_lexical)
{
    _langue_source = source;
    _langue_sortie = sortie;
        
    _nombre = "singulier";
    
    __genre[0] = "masculin";
    __genre[1] = "feminin";
}




// Retourne le nombre du mot du mot demandé.

string NomCommun::recuperer_nombre()
{
    return _nombre;
}




// Retourne le genre du mot demandé.

string NomCommun::recuperer_genre()
{
    return _genre;
}




// Détermine si le mot est un nom commun masculin ou féminin.

void NomCommun::le_mot_est_un_nom_commun(string mot, int genre)
{
    string mot_source;
    
    ifstream fichier_noms_communs(resourcePath() + "noms_" + __genre[genre] + "s.txt");
    
    // Est-ce un nom commun ?
    
    while (!fichier_noms_communs.eof())
    {
        fichier_noms_communs >> _nom_commun["A"] >> _nom_commun["F"] >> _champs_lexicaux;
        
        // Si le mot possède plusieurs sens, on regarde lequel correspond.
        
        istringstream iss_langue_source(_nom_commun[_langue_source]);
        
        while (getline(iss_langue_source, mot_source, '/'))
        {
            if (mot_source == mot || mot_source + 's' == mot)
            {
                if (mot_source + 's' == mot)
                {
                    _nombre = "pluriel";
                    
                    _nom_commun[_langue_sortie] += 's';
                }
                
                ajouter_mot(_nom_commun[_langue_sortie]);
                
                _genre = __genre[genre];
                
                ajouter_champs_lexicaux(_champs_lexicaux);
                
                break;
            }
        }
    }
    
    fichier_noms_communs.close();
}
