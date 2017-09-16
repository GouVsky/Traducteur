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
#include <stdio.h>


class Type
{
    public :
    
    Type();
    Type(std::string classe, std::string categorie, std::string propriete);
    Type & operator=(Type type);
    std::string recuperer_type() const { return _classe + "_" + _categorie + "_" + _propriete; };
    std::string recuperer_classe() const { return _classe; };
    std::string recuperer_categorie() const { return _categorie; };
    std::string recuperer_propriete() const { return _propriete; };
    
    private :
    
    /* Les chaîne de caractères permettent de définir le type exacte de la famille,
       et de retrouver la classe grammaticale, la catégorie et les propriétés qui lui sont associées. */
    
    std::string _classe,
                _categorie,
                _propriete;
};

#endif /* Type_hpp */
