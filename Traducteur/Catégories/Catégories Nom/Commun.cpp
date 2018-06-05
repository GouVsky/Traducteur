//
//  Commun.cpp
//  Traducteur
//
//  Created by Grégoire on 15/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Commun.hpp"

using namespace std;


Commun::Commun() : Nom() {}




void Commun::ajouter_pluriel(string & nom_commun)
{
    nom_commun += 's';
}
