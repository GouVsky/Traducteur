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




Type::Type(vector <string> type)
{
    __type = type;
}




Type & Type::operator=(Type type)
{
    __type = type.__type;
    
    return * this;
}




string Type::type()
{
    // On gère le cas où il le mot n'a pas de propriété, car elle n'est pas obligatoire.
    
    string propriete = (__type.size() == 3) ? ("_" + __type[2]) : "";


    return __type[0] + "_" + __type[1] + propriete;
}
