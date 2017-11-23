//
//  Avoir.cpp
//  Traducteur
//
//  Created by Grégoire on 23/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Avoir.hpp"

using namespace std;


Avoir::Avoir(string langue_source, string langue_sortie) : Auxiliaire(langue_source, langue_sortie)
{
    // Présent.
    
    __conjugaison["A"]["PRE"] = {"have", "have", "has", "has", "has", "have", "have", "have", "have"};
    
    __conjugaison["F"]["PRE"] = {"ai", "as", "a", "a", "a", "avons", "avez", "ont", "ont"};
}
