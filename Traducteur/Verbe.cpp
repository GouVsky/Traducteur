//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"
#include "Sujet.hpp"
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
        fichier_verbes_irreguliers >> __irregulier["infinitif"] >> __irregulier["passe_simple"] >> __verbe["participe_passe"];

        if (__irregulier["infinitif"] == verbe)
        {
            irregularite = __irregulier[_temps_verbe];
            
            break;
        }
    }
    
    fichier_verbes_irreguliers.close();
    
    return irregularite;
}




// Construction du verbe en fonction du sujet, du temps et du groupe du verbe, et des caractéristiques propres à chaque langue.

string Verbe::construction(string langue, string verbe, int compteur)
{
    string terminaison,
           construction_verbe,
           copie_verbe = verbe,
           mot_constituant_le_verbe;
    
    istringstream iss(__conjugaison[langue]);
    
    // Construction du verbe.
    
    while (getline(iss, mot_constituant_le_verbe, '+'))
    {
        istringstream iss_bis(mot_constituant_le_verbe);
        
        while (getline(iss_bis, terminaison, '-'))
        {
            if (terminaison == "verbe_et_terminaison")
            {
                if (__irregulier_ou_non[langue] == "oui")
                {
                    construction_verbe += le_verbe_est_irregulier(verbe, langue);
                }
                
                else
                {
                    _terminaison.determiner_nouvelle_terminaison(langue, verbe, _temps_verbe, _sujet, _groupe_verbe);
                    
                    construction_verbe += verbe + _terminaison.recuperer_nouvelle_terminaison();
                }
            }
            
            else if (terminaison == "ing")
            {
                construction_verbe += terminaison;
            }
            
            else if (terminaison == "verbe")
            {
                construction_verbe += verbe;
            }
            
            else if (terminaison == "radical")
            {
                _terminaison.determiner_ancienne_terminaison(langue, verbe, _groupe_verbe);
                
                copie_verbe.erase(copie_verbe.size() - _terminaison.recuperer_ancienne_terminaison().size());

                construction_verbe += copie_verbe;
            }
            
            else if (terminaison == "terminaison")
            {
                _terminaison.determiner_nouvelle_terminaison(langue, verbe, _temps_verbe, _sujet, _groupe_verbe);
                
                construction_verbe += _terminaison.recuperer_nouvelle_terminaison();
            }
            
            else if (terminaison == "avoir" || terminaison == "etre" || terminaison == "aller")
            {
                _auxilliaire.construction_auxilliaire(_sujet, langue, terminaison, _temps_verbe);
                
                construction_verbe += _auxilliaire.recuperer_auxilliaire();
            }
            
            else
            {
                construction_verbe += terminaison; // To, will, would...
            }
        }
        
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
    
    bool verbe_trouve = false;
            
    ifstream fichier_caracteristique(resourcePath() + "caracteristique_langue.txt");

    while (!fichier_caracteristique.eof() && verbe_trouve == false)
    {
        fichier_caracteristique >> _temps_verbe >> __conjugaison["A"] >> __conjugaison["F"];
        
        // On teste les verbes de chaque groupe.
        
        for (_groupe_verbe = 1; _groupe_verbe <= 3; _groupe_verbe++)
        {
            ifstream fichier_verbes(resourcePath() + "verbes_" + to_string(_groupe_verbe) + ".txt");
            
            while (!fichier_verbes.eof() && verbe_trouve == false)
            {
                fichier_verbes >> __verbe["A"] >> __verbe["F"] >> __irregulier_ou_non["A"] >> __irregulier_ou_non["F"] >> _champs_lexicaux;
                
                // Construction du verbe.
                
                istringstream iss_langue_source(__verbe[_langue_source]);
                
                // On vérifie si le verbe possède plusieurs sens.
                
                while (getline(iss_langue_source, mot_source, '/'))
                {
                    _forme_verbe_source = construction(_langue_source, mot_source, compteur);
                    
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
                        
                        istringstream iss_langue_source(__verbe[_langue_sortie]);
                        
                        while (getline(iss_langue_source, mot_source, '/'))
                        {
                            _forme_verbe_sortie = construction(_langue_sortie, mot_source, compteur);
                            
                            _taille_verbe_sortie = (int) count(_forme_verbe_sortie.begin(), _forme_verbe_sortie.end(), ' ') + 1;
                            
                            ajouter_mot(_forme_verbe_sortie);
                            
                            verbe_trouve = true;
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
