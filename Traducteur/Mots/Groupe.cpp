//
//  Groupe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Groupe.hpp"

using namespace std;



Groupe::Groupe(string mot_source)
{    
    _mot_source = mot_source;
}




void Groupe::ajouter_famille(Famille famille)
{
    __familles.push_back(famille);
}
