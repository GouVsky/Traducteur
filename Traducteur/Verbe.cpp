//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"
#include "Sujet.hpp"
#include "Terminaison.hpp"
#include "Auxilliaire.hpp"
#include "ResourcePath.hpp"

using namespace std;


Verbe::Verbe(string source, string sortie, ChampsLexicaux * champ_lexical) : Mot(champ_lexical)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _taille_verbe_source = 0;
    _taille_verbe_sortie = 0;
}




// Retourne la taille du verbe traduit.

int Verbe::recuperer_taille_verbe_sortie()
{
    return _taille_verbe_sortie;
}




// Retourne la taille du verbe source.

int Verbe::recuperer_taille_verbe_source()
{
    return _taille_verbe_source;
}




// Cherche le passé et le participe passé du verbe irrégulier.

string Verbe::le_verbe_est_irregulier(string verbe, string langue)
{
    string irregularite;
    
    ifstream fichier_verbes_irreguliers(resourcePath() + "verbes_irreguliers_" + langue + ".txt");
    
    while (!fichier_verbes_irreguliers.eof())
    {
        fichier_verbes_irreguliers >> _verbe_irregulier["infinitif"] >> _verbe_irregulier["passe_simple"] >> _verbe_irregulier["participe_passe"];

        if (_verbe_irregulier["infinitif"] == verbe)
        {
            irregularite = _verbe_irregulier[_temps_verbe];
            
            break;
        }
    }
    
    fichier_verbes_irreguliers.close();
    
    return irregularite;
}




// Construction du verbe en fonction du sujet, du temps et du groupe du verbe, et des caractéristiques propres à chaque langue.

string Verbe::construction(string langue, string le_verbe, vector <string> * tableau, int compteur)
{
    Auxilliaire auxilliaire;
    Terminaison la_terminaison;
    
    int position = 0;
        
    string terminaison,
           construction_verbe,
           copie_verbe = le_verbe,
           mot_constituant_le_verbe;
    
    tuple <string, string> terminaisons;
    
    istringstream iss(_conjugaison[langue]);
    
    // Construction du verbe.
    
    while (getline(iss, mot_constituant_le_verbe, '+'))
    {
        istringstream iss_bis(mot_constituant_le_verbe);
        
        while (getline(iss_bis, terminaison, '-'))
        {
            if (terminaison == "verbe_et_terminaison")
            {
                if (_irregulier_ou_non[langue] == "oui")
                {
                    construction_verbe += le_verbe_est_irregulier(le_verbe, langue);
                }
                
                else
                {
                    terminaisons = la_terminaison.construction(_groupe_verbe, _temps_verbe, _sujet, langue, le_verbe);
                    
                    construction_verbe += le_verbe + get <1> (terminaisons);
                }
            }
            
            else if (terminaison == "ing")
            {
                construction_verbe += terminaison;
            }
            
            else if (terminaison == "verbe")
            {
                construction_verbe += le_verbe;
            }
            
            else if (terminaison == "radical")
            {
                // On calcule la terminaison puisque le radical est déterminé en fonction de celle-ci.
                // Elle est différente pour les verbes français du troisième groupe.
                
                terminaisons = la_terminaison.construction(_groupe_verbe, _temps_verbe, _sujet, langue, le_verbe);
                
                copie_verbe.erase(copie_verbe.size() - (get <0> (terminaisons).size()));
                
                construction_verbe += copie_verbe;
            }
            
            else if (terminaison == "terminaison")
            {
                terminaisons = la_terminaison.construction(_groupe_verbe, _temps_verbe, _sujet, langue, le_verbe);
                
                construction_verbe += get <1> (terminaisons);
            }
            
            else if (terminaison == "avoir" || terminaison == "etre" || terminaison == "aller")
            {
                construction_verbe += auxilliaire.construction_auxilliaire(_sujet, langue, terminaison, _temps_verbe);
            }
            
            else
            {
                construction_verbe += terminaison; // To, will, would...
            }
            
            get <0> (terminaisons).clear();
            get <1> (terminaisons).clear();
        }
        
        position++;
        
        construction_verbe += ' ';
    }
    
    construction_verbe.erase(construction_verbe.size() - 1);
    
    return construction_verbe;
}




// Détermine le verbe de la phrase.

void Verbe::determine_si_existe_un_verbe_dans_la_phrase(int compteur, vector <string> tableau, vector <vector <string>> structure_de_la_phrase)
{
    // Création du sujet.

    Sujet sujet(structure_de_la_phrase);
    
    sujet.creation_du_sujet();
    
    _sujet = sujet.recuperer_valeur();
    
    
    string mot_source,
           forme_verbe_tmp;
            
    ifstream fichier_caracteristique(resourcePath() + "caracteristique_langue.txt");

    while (!fichier_caracteristique.eof())
    {
        fichier_caracteristique >> _temps_verbe >> _conjugaison["A"] >> _conjugaison["F"];
        
        // On teste les verbes de chaque groupe.
        
        for (_groupe_verbe = 1; _groupe_verbe <= 3; _groupe_verbe++)
        {
            ifstream fichier_verbes(resourcePath() + "verbes_" + to_string(_groupe_verbe) + ".txt");
            
            while (!fichier_verbes.eof())
            {
                fichier_verbes >> _verbe["A"] >> _verbe["F"] >> _irregulier_ou_non["A"] >> _irregulier_ou_non["F"] >> _champs_lexicaux;
                
                // Construction du verbe.
                
                istringstream iss_langue_source(_verbe[_langue_source]);
                
                // On vérifie si le verbe possède plusieurs sens.
                
                while (getline(iss_langue_source, mot_source, '/'))
                {
                    _forme_verbe_source = construction(_langue_source, mot_source, &tableau, compteur);
                    
                    // On récupère la taille du verbe.
                    
                    _taille_verbe_source = (int) count(_forme_verbe_source.begin(), _forme_verbe_source.end(), ' ') + 1;
                    
                    // On récupère le verbe de la phrase entrée par l'utilisateur.
                    
                    forme_verbe_tmp = "";
                    
                    for (int i = 0; i < min(_taille_verbe_source, (int) tableau.size() - compteur); i++)
                    {
                        forme_verbe_tmp += tableau[compteur + i] + ' ';
                    }
                    
                    forme_verbe_tmp.erase(forme_verbe_tmp.size() - 1);
                    
                    // On traduit le verbe s'il est identique à celui de la phrase.
                    
                    if (forme_verbe_tmp == _forme_verbe_source)
                    {
                        // On stocke tous les sens possibles du verbe une fois celui-ci traduit.
                        
                        istringstream iss_langue_source(_verbe[_langue_sortie]);
                        
                        while (getline(iss_langue_source, mot_source, '/'))
                        {
                            _forme_verbe_sortie = construction(_langue_sortie, mot_source, &tableau, compteur);
                            
                            _taille_verbe_sortie = (int) count(_forme_verbe_sortie.begin(), _forme_verbe_sortie.end(), ' ') + 1;
                            
                            ajouter_mot(_forme_verbe_sortie);
                        }
                        
                        ajouter_champs_lexicaux(_champs_lexicaux);
                        
                        break;
                    }
                }
            }
            
            fichier_verbes.close();
        }
    }
    
    fichier_caracteristique.close();
}
