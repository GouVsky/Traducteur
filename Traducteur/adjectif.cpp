//
//  adjectif.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "adjectif.h"
#include "ResourcePath.hpp"
#include "champsLexicaux.hpp"

using namespace std;



// Détermine si le mot est adjectif.

tuple <string, string> Adjectif::le_mot_est_un_adjectif(string mot, string l_source, string l_sortie)
{
    ChampsLexicaux chp_lex;
    
    langue_source = l_source;
    langue_sortie = l_sortie;
    
    ifstream fichier_adjectifs(resourcePath() + "adjectifs.txt");
    
    while(!fichier_adjectifs.eof())
    {
        fichier_adjectifs >> adjectif["A"] >> adjectif["F"] >> champ_lexical;
        
        if(adjectif[langue_source] == mot)
        {
            // On incrémente les champs lexicaux concernés.
            
            chp_lex.incrementation_des_champs_lexicaux(champ_lexical);
            
            return make_tuple(adjectif[langue_sortie], champ_lexical);
        }
    }
    
    fichier_adjectifs.close();

    return make_tuple("MEM2!65oG", "-");
}
