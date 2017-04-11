//
//  PronomPersonnel.cpp
//  Traducteur
//
//  Created by Grégoire on 05/03/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "PronomPersonnel.hpp"

using namespace std;


PronomPersonnel::PronomPersonnel()
{
    _pronom_existe = false;
    
    __pronoms_personnels_sujets_A = {"i", "you", "he", "she", "it", "we", "you", "they", "they"};
    __pronoms_personnels_sujets_F = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
    
    __pronoms_personnels_generiques = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
}




PronomPersonnel::PronomPersonnel(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _pronom_existe = false;
    
    __pronoms_personnels_sujets_A = {"i", "you", "he", "she", "it", "we", "you", "they", "they"};
    __pronoms_personnels_sujets_F = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
    
    __pronoms_personnels_generiques = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
}




bool PronomPersonnel::est_un_pronom_generique(string mot)
{
    for (int i = 0; i < __pronoms_personnels_generiques.size(); i++)
    {
        if (__pronoms_personnels_generiques[i] == mot)
        {
            _valeur = i;
            
            return true;
        }
    }
    
    return false;
}




// Détermine si le mot est un pronom personnel.

/*void PronomPersonnel::le_mot_est_un_pronom_personnel(string mot)
{
    __pronoms_personnels_sujets["A"] = __pronoms_personnels_sujets_A;
    __pronoms_personnels_sujets["F"] = __pronoms_personnels_sujets_F;
    
    for (int i = 0; i < __pronoms_personnels_sujets[_langue_source].size(); i++)
    {
        if (__pronoms_personnels_sujets[_langue_source][i] == mot)
        {
            _valeur = i;
            
            _pronom_existe = true;
            
            definir_les_differents_sens_sortie(__pronoms_personnels_sujets[_langue_sortie][i]);
            
            _pronom_personnel_generique = __pronoms_personnels_generiques[i];
            
            break;
        }
    }
}*/
