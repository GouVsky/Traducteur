//
//  Mot.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Mot.hpp"

using namespace std;


Mot::Mot(string mot)
{
    _mot = mot;
}




// Ajoute tous les champs lexicaux qu'un mot peut posséder.

void Mot::definir_les_differents_champs_lexicaux(string ensemble_champ_lexicaux)
{
    string champ_lexical;
    
    istringstream flux(ensemble_champ_lexicaux);
    
    while (getline(flux, champ_lexical, '|'))
    {
        __champs_lexicaux.incrementation_du_champ_lexical(champ_lexical);
    }
}
