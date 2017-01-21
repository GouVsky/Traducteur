//
//  sujet.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "sujet.hpp"
#include "motInvariable.h"

using namespace std;


// Simplification du sujet en pronom personnel.

int Sujet::transforme_groupe_nominal_sujet_en_pronom(vector <string> tableau)
{
    int nb_masculin = 0, nb_feminin = 0;
        
    for (int i = 0; i < tableau.size(); i++)
    {
        // Le sujet est un pronom personnel.
        
        for (int j = 8; j--;)
        {
            if (tableau[i] == "pronom_" + pp[j] + "_1")
            {
                return j;
            }
        }
        
        // Le sujet est un groupe nominal.
        
        if (tableau[i].find("feminin_pluriel") != -1)
        {
            nb_feminin += 2;
        }
        
        else if (tableau[i].find("feminin_singulier") != -1)
        {
            nb_feminin++;
        }
        
        else if (tableau[i].find("masculin_pluriel") != -1)
        {
            nb_masculin += 2;
        }
        
        else if (tableau[i].find("masculin_singulier") != -1)
        {
            nb_masculin++;
        }
    }
    
    if (nb_masculin == 0 && nb_feminin == 1) return 3; // Un nom feminin.
    
    else if (nb_masculin == 0 && nb_feminin > 1) return 8; // Au moins deux noms féminins et aucun nom masculin.
    
    else if (nb_masculin == 1 && nb_feminin == 0) return 2; // Un nom masculin.
    
    else if ((nb_masculin > 0 && nb_feminin > 0) || (nb_masculin > 1 && nb_feminin == 0)) return 7; // Au moins un nom masculin et un nom féminin
                                                                                                   // OU Au moins deux noms masculins.
    else return 4;
}




// Création du sujet.

int Sujet::creation_du_sujet(vector <string> structure_de_la_phrase, string l_source, string l_sortie)
{
    langue_source = l_source;
    langue_sortie = l_sortie;
    
    vector <string> t_sujet;
    bool presence_verbe = false;
    
    
    // S'il s'agit d'une phrase composée, le sujet est compris entre la fin de la phrase précédente et le verbe (non inclus).
    // Sinon, il est compris entre le début et le verbe (non inclus).
        
    for (int i = debut; i < structure_de_la_phrase.size(); i++)
    {
        // On recherche s'il y a la présence d'un verbe.
        
        if (structure_de_la_phrase[i].find("verbe") != -1)
        {
            presence_verbe = true;
        }
        
        // S'il existe la conjonction "et", il peut s'agir soit de deux phrases distinctes, soit d'une seule.
        
        if (structure_de_la_phrase[i].find("conjonction_et") != -1)
        {
            debut += i + 1;
            
            // S'il y a un verbe dans la phrase, à gauche du "et", alors il s'agit de deux phrases distinctes.
            // Le sujet de la première phrase n'est pas pris en compte puisqu'il a déjà été traduit.
            
            if (presence_verbe == true)
            {
                for (int j = i; j < structure_de_la_phrase.size(); j++)
                {
                    t_sujet.push_back(structure_de_la_phrase[j]);
                }
            }
            
            // Il n'y a pas de verbe à gauche du "et". Il s'agit donc d'une phrase avec un sujet composé de plusieurs noms.
            
            else
            {
                for (int j=0; j<structure_de_la_phrase.size(); j++)
                {
                    t_sujet.push_back(structure_de_la_phrase[j]);
                }
            }
            
            return transforme_groupe_nominal_sujet_en_pronom(t_sujet);
        }
    }
    
    // Soit il n'y a pas de conjonction "et" dans la phrase, soit on arrive à la fin de "structure_de_la_phrase".
    
    return transforme_groupe_nominal_sujet_en_pronom(structure_de_la_phrase);
}
