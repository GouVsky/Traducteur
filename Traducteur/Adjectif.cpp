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


Adjectif::Adjectif(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
    
    nombre_de_adjectifs = 0;
}




int Adjectif::recuperer_nombre_de_adjectifs()
{
    return nombre_de_adjectifs;
}




string Adjectif::recuperer_champ_lexical()
{
    return champ_lexical;
}




string Adjectif::recuperer_adjectif()
{
    return adjectif[langue_sortie];
}



// Détermine si le mot est adjectif.

void Adjectif::le_mot_est_un_adjectif(string mot, ChampsLexicaux * champs_lexicaux)
{
    nombre_de_adjectifs = 0;
    
    ifstream fichier_adjectifs(resourcePath() + "adjectifs.txt");
    
    while (!fichier_adjectifs.eof())
    {
        fichier_adjectifs >> adjectif["A"] >> adjectif["F"] >> champ_lexical;
        
        if (adjectif[langue_source] == mot)
        {
            nombre_de_adjectifs++;
            
            // On incrémente les champs lexicaux concernés.
            
            champs_lexicaux->incrementation_des_champs_lexicaux(champ_lexical);
            
            break;
        }
    }
}
