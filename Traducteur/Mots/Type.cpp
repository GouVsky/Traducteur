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




Type::Type(string classe, string categorie, string propriete)
{
    _classe = classe;

    _categorie = categorie;

    _propriete = propriete;
}




Type & Type::operator=(Type type)
{
    _classe = type._classe;
    
    _categorie = type._categorie;
    
    _propriete = type._propriete;
    
    return * this;
}
