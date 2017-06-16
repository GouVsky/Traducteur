//
//  Type.cpp
//  Traducteur
//
//  Created by Grégoire on 16/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Type.hpp"

using namespace std;


Type::Type() {}




void Type::definir_classe(string classe)
{
    _classe = classe;
}




void Type::definir_categorie(string categorie)
{
    _categorie = categorie;
}




void Type::definir_propriete(string propriete)
{
    _propriete = propriete;
}
