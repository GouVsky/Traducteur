//
//  adjectif.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "Adjectif.h"
#include "ResourcePath.hpp"

using namespace std;


Adjectif::Adjectif() : Mot() {}




Adjectif::Adjectif(string source, string sortie) : Mot()
{
    _langue_source = source;
    _langue_sortie = sortie;
}




// Accorde l'adjectif au pluriel.

string Adjectif::accorder_pluriel(string adjectif)
{
    if (_langue_sortie == "F")
    {
        adjectif += 's';
    }
    
    return adjectif;
}




// Accorde l'adjectif s'il est féminin.

string Adjectif::accorder_feminin(string adjectif)
{
    if (_langue_sortie == "F")
    {
        if (adjectif[adjectif.size() - 1] != 'e')
        {
            adjectif += 'e';
        }
    }
    
    return adjectif;
}




// Détermine si le mot est adjectif.

void Adjectif::le_mot_est_un_adjectif(string mot)
{
    string mot_source;
    
    ifstream fichier_adjectifs(resourcePath() + "adjectifs.txt");
    
    while (!fichier_adjectifs.eof())
    {
        fichier_adjectifs >> __adjectif["A"] >> __adjectif["F"] >> _champs_lexicaux;
        
        // Si le mot possède plusieurs sens, on regarde lequel correspond.
        
        istringstream iss_langue_source(__adjectif[_langue_source]);
        
        while (getline(iss_langue_source, mot_source, '/'))
        {
            if (__adjectif[_langue_source] == mot)
            {
                definir_les_differents_sens_sortie(__adjectif[_langue_sortie]);
                
                definir_les_differents_champs_lexicaux(_champs_lexicaux);
                
                break;
            }
        }
    }
}
