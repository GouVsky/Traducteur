//
//  adjectif.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "adjectif.h"
#include "ResourcePath.hpp"

using namespace std;


Adjectif::Adjectif(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
}




// Détermine si le mot est adjectif.

tuple <string, string> Adjectif::le_mot_est_un_adjectif(string mot, ChampsLexicaux * champs_lexicaux)
{    
    ifstream fichier_adjectifs(resourcePath() + "adjectifs.txt");
    
    while (!fichier_adjectifs.eof())
    {
        fichier_adjectifs >> adjectif["A"] >> adjectif["F"] >> champ_lexical;
        
        if (adjectif[langue_source] == mot)
        {
            // On incrémente les champs lexicaux concernés.
            
            champs_lexicaux->incrementation_des_champs_lexicaux(champ_lexical);
            
            return make_tuple(adjectif[langue_sortie], champ_lexical);
        }
    }
    
    return make_tuple("MEM2!65oG", champ_lexical);
}
