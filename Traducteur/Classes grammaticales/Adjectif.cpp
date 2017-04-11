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


Adjectif::Adjectif() {}




// Accorde l'adjectif au pluriel.

string Adjectif::accorder_pluriel(string adjectif, string langue)
{
    if (langue == "F")
    {
        adjectif += 's';
    }
    
    return adjectif;
}




// Accorde l'adjectif s'il est féminin.

string Adjectif::accorder_feminin(string adjectif, string langue)
{
    if (langue == "F")
    {
        if (adjectif[adjectif.size() - 1] != 'e')
        {
            adjectif += 'e';
        }
    }
    
    return adjectif;
}
