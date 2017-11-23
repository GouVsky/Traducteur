//
//  Etre.cpp
//  Traducteur
//
//  Created by Grégoire on 22/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Etre.hpp"

using namespace std;


Etre::Etre(string langue_source, string langue_sortie) : Auxiliaire(langue_source, langue_sortie)
{
    // Présent.
    
    __conjugaison["A"]["PRE"] = {"am", "are", "is", "is", "is", "are", "are", "are", "are"};
    __conjugaison["A"]["ING"] = __conjugaison["A"]["PRE"];
    
    __conjugaison["F"]["PRE"] = {"suis", "es", "est", "est", "est", "sommes", "êtes", "sont", "sont"};
}
