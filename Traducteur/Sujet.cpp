//
//  sujet.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Sujet.hpp"

using namespace std;


Sujet::Sujet(vector <vector <string>> structure)
{
    _valeur = 4;
    
    for (int i = 0; i < structure.size(); i++)
    {
        for (int j = 0; j < structure[i].size(); j++)
        {
            __structure_phrase.push_back(structure[i][j]);
        }
    }
}




// Retourne le chiffre associé au sujet du verbe.

int Sujet::recuperer_valeur()
{
    return _valeur;
}




// Associe le sujet du verbe à un chiffre.

void Sujet::definir_valeur(int valeur)
{
    _valeur = valeur;
}




// Simplification du sujet en pronom personnel.

void Sujet::transforme_groupe_nominal_sujet_en_pronom(vector <string> tableau)
{
    int nb_masculin = 0,
        nb_feminin = 0;
    
    bool presence_pronom = false;
    
    string pp[9] = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
        
    for (int i = 0; i < tableau.size(); i++)
    {
        // Le sujet est un pronom personnel.
        
        for (int j = 8; j--;)
        {
            if (tableau[i] == "pronom_" + pp[j] + "_1")
            {
                definir_valeur(j);
                
                presence_pronom = true;
                
                break;
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
    
    if (presence_pronom == false)
    {
        // Un nom feminin.
        
        if (nb_masculin == 0 && nb_feminin == 1)
        {
            definir_valeur(3);
        }
        
        // Au moins deux noms féminins.
        
        else if (nb_masculin == 0 && nb_feminin > 1)
        {
            definir_valeur(8);
        }
        
        // Un nom masculin.
        
        else if (nb_masculin == 1 && nb_feminin == 0)
        {
            definir_valeur(2);
        }
        
        // Au moins un nom masculin et un nom féminin ou au moins deux noms masculins.
        
        else if ((nb_masculin > 0 && nb_feminin > 0) || (nb_masculin > 1 && nb_feminin == 0))
        {
            definir_valeur(7);
        }
    }
}




// Création du sujet.

void Sujet::creation_du_sujet()
{
    bool presence_verbe = false;
    
    
    // S'il s'agit d'une phrase composée, le sujet est compris entre la fin de la phrase précédente et le verbe (non inclus).
    // Sinon, il est compris entre le début et le verbe (non inclus).
        
    for (int i = 0; i < __structure_phrase.size(); i++)
    {
        // On recherche s'il y a la présence d'un verbe.
        
        if (__structure_phrase[i].find("verbe") != -1)
        {
            presence_verbe = true;
        }
        
        // S'il existe la conjonction "et", il peut s'agir soit de deux phrases distinctes, soit d'une seule.
        
        if (__structure_phrase[i].find("conjonction_et") != -1)
        {
            i++;
            
            // S'il y a un verbe dans la phrase, à gauche du "et", alors il s'agit de deux phrases distinctes.
            // Le sujet de la première phrase n'est pas pris en compte puisqu'il a déjà été traduit.
            
            if (presence_verbe == true)
            {
                for (int j = i; j < __structure_phrase.size(); j++)
                {
                    __structure_sujet.push_back(__structure_phrase[j]);
                }
            }
            
            // Il n'y a pas de verbe à gauche du "et". Il s'agit donc d'une phrase avec un sujet composé de plusieurs noms.
            
            else
            {
                for (int j = 0; j < __structure_phrase.size(); j++)
                {
                    __structure_sujet.push_back(__structure_phrase[j]);
                }
            }
            
            transforme_groupe_nominal_sujet_en_pronom(__structure_sujet);
        }
    }
    
    // Soit il n'y a pas de conjonction "et" dans la phrase, soit on arrive à la fin de "structure_de_la_phrase".
    
    transforme_groupe_nominal_sujet_en_pronom(__structure_phrase);
}
