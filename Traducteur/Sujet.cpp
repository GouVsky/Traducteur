//
//  sujet.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Sujet.hpp"
#include "PronomPersonnel.hpp"

using namespace std;


Sujet::Sujet(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _valeur = 4;
}




// Simplification du sujet en pronom personnel.

/*void Sujet::transforme_groupe_nominal_sujet_en_pronom(vector <string> tableau)
{
    int nb_masculin = 0,
        nb_feminin = 0;
    
    for (int i = 0; i < tableau.size(); i++)
    {
        // Le sujet est un pronom personnel.
                
        if (pronom.est_un_pronom_generique(tableau[i]))
        {
            _valeur = pronom.recuperer_valeur();
        }
        
        
        if (tableau[i] == "Nom_commun_feminin_pluriel")
        {
            nb_feminin += 2;
        }
        
        else if (tableau[i] == "Nom_commun_feminin_singulier")
        {
            nb_feminin++;
        }
        
        else if (tableau[i] == "Nom_commun_masculin_pluriel")
        {
            nb_masculin += 2;
        }
        
        else if (tableau[i] == "Nom_commun_masculin_singulier")
        {
            nb_masculin++;
        }
    }
    
    // Un nom feminin.
    
    if (nb_masculin == 0 && nb_feminin == 1)
    {
        _valeur = 3;
    }
    
    // Au moins deux noms féminins.
    
    else if (nb_masculin == 0 && nb_feminin > 1)
    {
        _valeur = 8;
    }
    
    // Un nom masculin.
    
    else if (nb_masculin == 1 && nb_feminin == 0)
    {
        _valeur = 2;
    }
    
    // Au moins un nom masculin et un nom féminin ou au moins deux noms masculins.
    
    else if ((nb_masculin > 0 && nb_feminin > 0) || (nb_masculin > 1 && nb_feminin == 0))
    {
        _valeur = 7;
    }
}




// Création du sujet.

void Sujet::creation_du_sujet(vector <Mot> & mots)
{
    bool presence_verbe = false;
    
    // S'il s'agit d'une phrase composée, le sujet est compris entre la fin de la phrase précédente et le verbe (non inclus).
    // Sinon, il est compris entre le début et le verbe (non inclus).
        
    for (int i = 0; i < mots.size(); i++)
    {
        // On recherche s'il y a la présence d'un verbe.
        
        if (mots[i].recuperer_type() == "Verbe")
        {
            presence_verbe = true;
        }
        
        // S'il existe la conjonction "et", il peut s'agir soit de deux phrases distinctes, soit d'une seule.
        
        //else if (__structure_phrase[i].find("conjonction_et") != -1)
        else
        {
            // S'il y a un verbe à gauche du "et", alors il s'agit de deux phrases distinctes.
            // Le sujet de la première phrase n'est pas pris en compte puisqu'il a déjà été traduit.
            
            if (presence_verbe == true)
            {
                for (int j = i + 1; j < mots.size(); j++)
                {
                    __structure_sujet.push_back(mots[i].recuperer_type());
                }
            }
            
            // Il n'y a pas de verbe à gauche du "et". Il s'agit donc d'une phrase avec un sujet composé de plusieurs noms.
            
            else
            {
                for (int j = 0; j < mots.size(); j++)
                {
                    __structure_sujet.push_back(mots[j].recuperer_type());
                }
            }
            
            transforme_groupe_nominal_sujet_en_pronom(__structure_sujet);
            
            break;
        }
    }
}*/
