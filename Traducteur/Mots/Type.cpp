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
