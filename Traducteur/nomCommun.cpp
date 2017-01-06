//
//  nomCommun.cpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "nomCommun.hpp"
#include "ResourcePath.hpp"
#include "champsLexicaux.hpp"

using namespace std;


// Détermine si le mot est un nom masculin ou féminin (nom commun ou prénom).

tuple <vector <string>, vector <string>, vector <string>, string> NomCommun::le_mot_est_un_nom_commun(string mot, string l_source, string l_sortie)
{
    ChampsLexicaux chp_lex;
    
    langue_source = l_source;
    langue_sortie = l_sortie;
    
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    string nombre = "singulier";
    
    vector <string> tableau_mots, tableau_champs_lexicaux, tableau_genre;
    
    for (int i = 0; i < 2; i++)
    {
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
                        // On récupère chaque champ lexical.
                        
                        istringstream iss_champ_lexical(les_champs_lexicaux);
                        
                        while (getline(iss_champ_lexical, un_des_champs_lexicaux, '|'))
                        {
                            // On incrémente le champ lexical concerné.
                            
                            chp_lex.incrementation_des_champs_lexicaux(un_des_champs_lexicaux);
                            
                            tableau_champs_lexicaux.push_back(un_des_champs_lexicaux);
                            
                            // On ajoute les mots correspondants.
                            
                            tableau_genre.push_back(genre[i]);
                            
                            tableau_mots.push_back(mot_sortie);
                        }
                    }
                    
                    // Le mot est au pluriel.
                    
                    if (mot[mot.size()-1] == 's')
                    {
                        nombre = "pluriel";
                        
                        // On ajoute un 's' à chaque sens s'il n'y en a pas déjà un.
                        
                        for (int i = 0; i < tableau_mots.size(); i++)
                        {
                            if (tableau_mots[i][tableau_mots[i].size()-1] != 's')
                            {
                                tableau_mots[i] += 's';
                            }
                        }
                    }
                    
                    break;
                }
            }
        }
        
        fichier_noms_communs.close();
        
        if (tableau_mots.empty())
        {
            ifstream fichier_prenoms(resourcePath() + "prenoms_" + genre[i] + "s.txt");

            // Est-ce un prénom ?
            
            while (!fichier_prenoms.eof())
            {
                fichier_prenoms >> prenom;
                
                if (prenom == mot)
                {
                    tableau_genre.push_back(genre[i]);
                    
                    prenom[0] = toupper(prenom[0]);
                    
                    tableau_mots.push_back(prenom);
                    tableau_champs_lexicaux.push_back("-");
                    
                    break;
                }
            }
            
            fichier_prenoms.close();
        }
    }
    
    return make_tuple(tableau_mots, tableau_champs_lexicaux, tableau_genre, nombre);
}
