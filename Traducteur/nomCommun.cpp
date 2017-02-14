//
//  nomCommun.cpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "nomCommun.hpp"
#include "ResourcePath.hpp"

using namespace std;


NomCommun::NomCommun(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
}




// Détermine si le mot est un nom masculin ou féminin (nom commun ou prénom).

tuple <vector <string>, vector <vector <string>>, vector <string>, string> NomCommun::le_mot_est_un_nom_commun(string mot, ChampsLexicaux * champs_lexicaux)
{
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    string nombre = "singulier";
    
    vector <string> tableau_mots, tableau_genre;
    vector <vector <string>> tableau_champs_lexicaux;
    
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
                        // On ajoute les mots correspondants.
                        
                        tableau_genre.push_back(genre[i]);
                        
                        tableau_mots.push_back(mot_sortie);
                        
                        // On récupère chaque champ lexical.

                        tableau_champs_lexicaux.push_back(vector <string> ());
                        
                        istringstream iss_champ_lexical(les_champs_lexicaux);
                        
                        while (getline(iss_champ_lexical, un_des_champs_lexicaux, '|'))
                        {
                            // On incrémente le champ lexical concerné.
                            
                            champs_lexicaux->incrementation_des_champs_lexicaux(un_des_champs_lexicaux);
                            
                            tableau_champs_lexicaux[tableau_champs_lexicaux.size() - 1].push_back(un_des_champs_lexicaux);
                        }
                    }
                    
                    // Le mot est au pluriel.
                    
                    if (mot[mot.size() - 1] == 's')
                    {
                        nombre = "pluriel";
                        
                        // On ajoute un 's' à chaque sens s'il n'y en a pas déjà un.
                        
                        for (int i = 0; i < tableau_mots.size(); i++)
                        {
                            if (tableau_mots[i][tableau_mots[i].size() - 1] != 's')
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
    }
    
    return make_tuple(tableau_mots, tableau_champs_lexicaux, tableau_genre, nombre);
}
