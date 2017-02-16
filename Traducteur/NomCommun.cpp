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


NomCommun::NomCommun(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
    
    nombre_de_mots = 0;
    
    nombre = "singulier";
}




// Retourne le nombre de champs lexicaux associés au mot demandé.

int NomCommun::recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(int numero_du_mot)
{
    return nombre_de_champs_lexicaux[numero_du_mot];
}




// Retourne le nombre de significations d'un mot.

int NomCommun::recuperer_nombre_de_significations()
{
    return nombre_de_mots;
}




// Retourne un des différents champs lexicaux associés au mot demandé.

string NomCommun::recuperer_champ_lexical(int numero_du_nombre, int numero_du_champ_lexical)
{
    return tableau_champs_lexicaux[numero_du_nombre][numero_du_champ_lexical];
}




// Retourne le nombre du mot du mot demandé.

string NomCommun::recuperer_nombre(int numero_du_nombre)
{
    return nombre;
}




// Retourne le genre du mot demandé.

string NomCommun::recuperer_genre(int numero_du_mot)
{
    return tableau_genre[numero_du_mot];
}




// Retourne le mot demandé.

string NomCommun::recuperer_mot(int numero_du_mot)
{
    return tableau_mots[numero_du_mot];
}




// Détermine si le mot est un nom masculin ou féminin (nom commun ou prénom).

void NomCommun::le_mot_est_un_nom_commun(string mot, ChampsLexicaux * champs_lexicaux)
{
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    nombre_de_mots = 0;
    
    tableau_mots.clear();
    tableau_genre.clear();
    tableau_champs_lexicaux.clear();
    
    nombre_de_champs_lexicaux.clear();
    
    for (int i = 0; i < 2; i++)
    {
        nombre = "singulier";
        
        ifstream fichier_noms_communs(resourcePath() + "noms_" + genre[i] + "s.txt");
        
        // Est-ce un nom commun ?
        
        while (!fichier_noms_communs.eof())
        {
            fichier_noms_communs >> nom["A"] >> nom["F"] >> champ_lexical;
            
            // Si le mot possède plusieurs sens, on regarde lequel correspond.

            istringstream iss_langue_source(nom[langue_source]);
            
            while (getline(iss_langue_source, mot_source, '/'))
            {
                if (mot_source == mot || mot_source + 's' == mot)
                {
                    // On isole le(s) champ(s) lexical(ux) propres à chaque mot et chaque traduction.
                    
                    istringstream iss_champs_lexicaux(champ_lexical);
                    istringstream iss_langue_sortie(nom[langue_sortie]);
                    
                    while (getline(iss_champs_lexicaux, les_champs_lexicaux, '/') && getline(iss_langue_sortie, mot_sortie, '/'))
                    {
                        nombre_de_mots++;

                        // On ajoute le mot correspondant.
                        
                        tableau_genre.push_back(genre[i]);
                        
                        tableau_mots.push_back(mot_sortie);
                        
                        // On récupère son (ses) champ(s) lexical(ux) associé(s).

                        tableau_champs_lexicaux.push_back(vector <string> ());
                        
                        nombre_de_champs_lexicaux.push_back(0);
                        
                        istringstream iss_champ_lexical(les_champs_lexicaux);
                        
                        while (getline(iss_champ_lexical, un_des_champs_lexicaux, '|'))
                        {
                            // On incrémente le champ lexical concerné.
                            
                            champs_lexicaux->incrementation_des_champs_lexicaux(un_des_champs_lexicaux);
                            
                            tableau_champs_lexicaux[tableau_champs_lexicaux.size() - 1].push_back(un_des_champs_lexicaux);
                            
                            nombre_de_champs_lexicaux[nombre_de_champs_lexicaux.size() - 1]++;
                        }
                    }
                }
            }
        }
        
        fichier_noms_communs.close();
    }
}
