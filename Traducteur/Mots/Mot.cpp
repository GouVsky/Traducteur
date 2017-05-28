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




void Mot::definir_les_differents_champs_lexicaux(ChampsLexicaux champs_lexicaux)
{
    __champs_lexicaux = __champs_lexicaux + champs_lexicaux;
}
