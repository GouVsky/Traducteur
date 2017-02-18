//
//  Mot.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Mot.hpp"

using namespace std;


Mot::Mot()
{
    _nombre_de_mots = 0;
}




Mot::Mot(ChampsLexicaux * champ_lexical)
{
    _nombre_de_mots = 0;
    
    _champ_lexical = champ_lexical;
}




// Retourne le nombre de champs lexicaux associés au mot demandé.

int Mot::recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(int numero_du_mot)
{
    return _nombre_de_champs_lexicaux[numero_du_mot];
}




int Mot::recuperer_nombre_de_mots()
{
    return _nombre_de_mots;
}




// Retourne un des différents champs lexicaux associés au mot demandé.

vector <vector <string>> Mot::recuperer_champs_lexicaux()
{
    return _tableau_champs_lexicaux;
}




// Retourne le mot demandé.

string Mot::recuperer_mot(int numero_du_mot)
{
    return _tableau_mots[numero_du_mot];
}




void Mot::ajouter_champs_lexicaux(string champs_lexicaux)
{
    string champ_lexical_du_flux,
           nieme_champ_lexical;
    
    istringstream flux(champs_lexicaux);
    
    while (getline(flux, champ_lexical_du_flux, '/'))
    {
        _tableau_champs_lexicaux.push_back(vector <string> ());
        
        _nombre_de_champs_lexicaux.push_back(0);
        
        istringstream isoler_champs_lexicaux(champ_lexical_du_flux);

        while (getline(isoler_champs_lexicaux, nieme_champ_lexical, '|'))
        {
            // On incrémente le champ lexical concerné.
            
            _champ_lexical->incrementation_des_champs_lexicaux(nieme_champ_lexical);
            
            _tableau_champs_lexicaux[_tableau_champs_lexicaux.size() - 1].push_back(nieme_champ_lexical);
            
            _nombre_de_champs_lexicaux[_nombre_de_champs_lexicaux.size() - 1]++;
        }
    }
}




void Mot::ajouter_mot(string mot)
{
    string mot_du_flux;
    
    istringstream flux(mot);
    
    while (getline(flux, mot_du_flux, '/'))
    {
        _nombre_de_mots++;
        
        // On ajoute le mot correspondant.
        
        _tableau_mots.push_back(mot_du_flux);
    }
}

