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
    
    genre[0] = "masculin";
    genre[1] = "feminin";
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




// Stocke le nombre du mot.

void NomCommun::definir_nombre(string nombre)
{
    _nombre = nombre;
}




// Stocke le genre du mot.

void NomCommun::definir_genre(string genre)
{
    _genre = genre;
}




// Détermine si le mot est un nom masculin ou féminin (nom commun ou prénom).

void NomCommun::le_mot_est_un_nom_commun(string mot)
{
    string mot_source;
    
    for (int i = 0; i < 2; i++)
    {
        ifstream fichier_noms_communs(resourcePath() + "noms_" + genre[i] + "s.txt");
        
        // Est-ce un nom commun ?
        
        while (!fichier_noms_communs.eof())
        {
            fichier_noms_communs >> nom["A"] >> nom["F"] >> _champs_lexicaux;
            
            // Si le mot possède plusieurs sens, on regarde lequel correspond.

            istringstream iss_langue_source(nom[_langue_source]);
            
            while (getline(iss_langue_source, mot_source, '/'))
            {
                if (mot_source == mot || mot_source + 's' == mot)
                {
                    ajouter_mot(nom[_langue_sortie]);
                    
                    definir_genre(genre[i]);
                    
                    definir_nombre(_nombre);
                    
                    ajouter_champs_lexicaux(_champs_lexicaux);
                    
                    break;
                }
            }
        }
        
        fichier_noms_communs.close();
    }
}
