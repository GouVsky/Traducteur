//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "verbe.hpp"
#include "sujet.hpp"
#include "terminaison.hpp"
#include "auxilliaire.hpp"
#include "ResourcePath.hpp"

using namespace std;


Verbe::Verbe(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
}




// Cherche le passé et le participe passé du verbe irrégulier.

string Verbe::le_verbe_est_irregulier(string verbe, string temps, string langue)
{
    string irregularite;
    
    ifstream fichier_verbes_irreguliers(resourcePath() + "verbes_irreguliers_" + langue + ".txt");
    
    while (!fichier_verbes_irreguliers.eof())
    {
        fichier_verbes_irreguliers >> verbe_irregulier["infinitif"] >> verbe_irregulier["passe_simple"] >> verbe_irregulier["participe_passe"];

        if (verbe_irregulier["infinitif"] == verbe)
        {
            irregularite = verbe_irregulier[temps];
            
            break;
        }
    }
    
    fichier_verbes_irreguliers.close();
    
    return irregularite;
}




// Construction du verbe en fonction du sujet, du temps et du groupe du verbe, et des caractéristiques propres à chaque langue.

string Verbe::construction(string caracteristique, string langue, string temps, int sujet, int groupe_verbe, string le_verbe, string marque_vb_si_irr, vector <string> * tableau, int compteur)
{
    Auxilliaire auxilliaire;
    Terminaison la_terminaison;
    
    int position = 0;
        
    string copie_verbe = le_verbe,
           construction_verbe,
           mot_bis;
    
    tuple <string, string> terminaisons;
    
    istringstream iss(caracteristique);
    
    // Construction du verbe.
    
    while (getline(iss, mot, '+'))
    {
        istringstream iss_bis(mot);
        
        while (getline(iss_bis, mot_bis, '-'))
        {
            if (mot_bis == "verbe_et_terminaison")
            {
                if (marque_vb_si_irr == "oui")
                {
                    construction_verbe += le_verbe_est_irregulier(le_verbe, temps, langue);
                }
                
                else
                {
                    terminaisons = la_terminaison.construction(groupe_verbe, temps, sujet, langue, le_verbe);
                    
                    construction_verbe += le_verbe + get <1> (terminaisons);
                }
            }
            
            else if (mot_bis == "pronom")
            {
                // On enregistre combien de mots précèdent le pronom.
                // On associe ensuite la langue et le pronom pour déterminer le pronom dans l'autre langue.
                
                position_pronom[langue] = position;
                
                if (compteur + position_pronom[langue_source] < tableau->size())
                {
                    construction_verbe += association[make_pair(langue, pronom[(* tableau)[compteur + position_pronom[langue_source]]])];
                }
            }
            
            else if (mot_bis == "ing")
            {
                construction_verbe += mot_bis;
            }
            
            else if (mot_bis == "verbe")
            {
                construction_verbe += le_verbe;
            }
            
            else if (mot_bis == "radical")
            {
                // On calcule la terminaison puisque le radical est déterminé en fonction de celle-ci.
                // Elle est différente pour les verbes français du troisième groupe.
                
                terminaisons = la_terminaison.construction(groupe_verbe, temps, sujet, langue, le_verbe);
                
                copie_verbe.erase(copie_verbe.size() - (get <0> (terminaisons).size()));
                
                construction_verbe += copie_verbe;
            }
            
            else if (mot_bis == "terminaison")
            {
                terminaisons = la_terminaison.construction(groupe_verbe, temps, sujet, langue, le_verbe);
                
                construction_verbe += get <1> (terminaisons);
            }
            
            else if (mot_bis == "avoir" || mot_bis == "etre" || mot_bis == "aller")
            {
                construction_verbe += auxilliaire.construction_auxilliaire(sujet, langue, mot_bis, temps);
            }
            
            else
            {
                construction_verbe += mot_bis; // To, will, would...
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

tuple <string, string, int, int> Verbe::determine_si_existe_un_verbe_dans_la_phrase(int compteur, vector <string> tableau, vector <vector <string>> structure_de_la_phrase, ChampsLexicaux * champs_lexicaux)
{
    // Création du sujet.

    Sujet sujet(langue_source, langue_sortie);

    vector <string> structure;
    
    // On récupère le type des mots qui précèdent le verbe.
    
    for (int i = 0; i < structure_de_la_phrase.size(); i++)
    {
        for (int j = 0; j < structure_de_la_phrase[i].size(); j++)
        {
            structure.push_back(structure_de_la_phrase[i][j]);
        }
    }
    
    int le_sujet = sujet.creation_du_sujet(&structure);
    

    
    // Recherche du verbe.
    
    int taille = 0;
    string champ_lexical_final;
    
    forme_verbe_sortie = "MEM2!65oG";
        
    ifstream fichier_caracteristique(resourcePath() + "caracteristique_langue.txt");

    while (!fichier_caracteristique.eof())
    {
        fichier_caracteristique >> temps_verbe >> caracteristique["A"] >> caracteristique["F"];
        
        // On teste les verbes de chaque groupe.
        
        for (int groupe_verbe = 1; groupe_verbe <= 3; groupe_verbe++)
        {
            ifstream fichier_verbes(resourcePath() + "verbes_" + to_string(groupe_verbe) + ".txt");
            
            while (!fichier_verbes.eof())
            {
                fichier_verbes >> verbe["A"] >> verbe["F"] >> marque_vb_irr["A"] >> marque_vb_irr["F"] >> champ_lexical;
                
                position_pronom["A"] = 0;
                position_pronom["F"] = 0;
                
                // Construction du verbe.
                
                string forme_verbe_source = construction(caracteristique[langue_source], langue_source, temps_verbe, le_sujet, groupe_verbe, verbe[langue_source], marque_vb_irr[langue_source], &tableau, compteur);
                                
                // On récupère la taille du verbe.
                
                taille = (int) count(forme_verbe_source.begin(), forme_verbe_source.end(), ' ') + 1;
                
                // On récupère le verbe de la phrase entrée par l'utilisateur.
                
                for (int i = 0; i < min(taille, (int) tableau.size() - compteur); i++)
                {
                    phrase += tableau[compteur + i] + ' ';
                }
                
                phrase.erase(phrase.size() - 1);
                
                // Si le verbe construit est identique à celui de la phrase, on construit le verbe dans la langue demandée.
                // On vérifie également qu'il s'agit du plus grand verbe identifiable.

                if (phrase == forme_verbe_source && taille > taille_verbe_source)
                {
                    taille_verbe_source = taille;
                    
                    champs_lexicaux->incrementation_des_champs_lexicaux(champ_lexical);
                    
                    champ_lexical_final = champ_lexical;
                    
                    forme_verbe_sortie = construction(caracteristique[langue_sortie], langue_sortie, temps_verbe, le_sujet, groupe_verbe, verbe[langue_sortie], marque_vb_irr[langue_sortie], &tableau, compteur);
                    
                    taille_verbe_sortie = (int) count(forme_verbe_sortie.begin(), forme_verbe_sortie.end(), ' ') + 1;
                }
                
                // Réinitialisation.
                
                phrase = "";
            }
            
            fichier_verbes.close();
        }
    }
    
    fichier_caracteristique.close();
    
    return make_tuple(forme_verbe_sortie, champ_lexical_final, taille_verbe_source, taille_verbe_sortie);
}
