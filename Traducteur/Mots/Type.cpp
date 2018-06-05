//
//  Type.cpp
//  Traducteur
//
//  Created by Grégoire on 05/06/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "Type.hpp"

using namespace std;


Type::Type() {}




Type::Type(vector <string> types)
{
    _classe = types[0];
    
    if (types.size() > 1)
    {
        _categorie = types[1];
        
        if (types.size() > 2)
        {
            _propriete = types[2];
        }
    }
    
    _type_complet = _classe + '_' + _categorie + '_' + _propriete;
}




Type Type::operator+(Type type)
{
    _classe += '/' + type._classe;
    
    _categorie += '/' + type._categorie;
    
    _propriete += '/' + type._propriete;
    
    _type_complet += '/' + type._type_complet;
    
    return * this;
}
