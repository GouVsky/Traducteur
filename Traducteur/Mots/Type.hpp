//
//  Type.hpp
//  Traducteur
//
//  Created by Grégoire on 16/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include <string>
#include <vector>
#include <stdio.h>


class Type
{
    public :
    
    Type();
    Type(std::vector <std::string> type);
    Type & operator=(Type type);
    Type operator+(Type type);
    std::string type();
    std::string classe() const { return __type[0]; };
    std::string categorie() const { return __type[1]; };
    std::string propriete() { return (__type.size() == 3) ? __type[2] : ""; };
    
    private :
    
    /* Le tableau de chaînes de caractères permet de définir le type exacte de la famille,
       et de retrouver la classe grammaticale, la catégorie et les propriétés qui lui sont associées. */
    
    std::vector <std::string> __type;
};

#endif /* Type_hpp */
