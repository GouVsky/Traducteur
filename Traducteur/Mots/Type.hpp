//
//  Type.hpp
//  Traducteur
//
//  Created by Grégoire on 05/06/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "config.hpp"


class Type
{
    public :
    
    Type();
    Type(std::vector <std::string> types);
    Type operator+(Type type);
    std::string classe() { return _classe; };
    std::string categorie() { return _categorie; };
    std::string propriete() { return _propriete; };
    std::string type_complet() { return _type_complet; };
    
    private :
    
    std::string _classe,
                _categorie,
                _propriete,
                _type_complet;
};

#endif /* Type_hpp */
