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


Adjectif::Adjectif(string source, string sortie, ChampsLexicaux * champs_lexicaux) : Mot(champs_lexicaux)
{
    _langue_source = source;
    _langue_sortie = sortie;
}




// Détermine si le mot est adjectif.

void Adjectif::le_mot_est_un_adjectif(string mot)
{
    string mot_source;
    
    ifstream fichier_adjectifs(resourcePath() + "adjectifs.txt");
    
    while (!fichier_adjectifs.eof())
    {
        fichier_adjectifs >> adjectif["A"] >> adjectif["F"] >> _champs_lexicaux;
        
        // Si le mot possède plusieurs sens, on regarde lequel correspond.
        
        istringstream iss_langue_source(adjectif[_langue_source]);
        
        while (getline(iss_langue_source, mot_source, '/'))
        {
            if (adjectif[_langue_source] == mot)
            {
                ajouter_mot(adjectif[_langue_sortie]);
                
                ajouter_champs_lexicaux(_champs_lexicaux);
                
                break;
            }
        }
    }
}
