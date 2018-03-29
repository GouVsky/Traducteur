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

#include "Action.hpp"
#include "Propre.hpp"
#include "Commun.hpp"


class Type
{
    public :
    
    Type();
    Type(std::vector <std::string> type);
    Type & operator=(Type type);
    Type operator+(Type type);
    std::string type();
    std::string classe() const { return (__type.size() > 0) ? __type[0] : ""; };
    std::string categorie() const { return (__type.size() > 1) ? __type[1] : ""; };
    std::string propriete() { return (__type.size() > 2) ? __type[2] : ""; };
    
    struct __Types
    {
        Propre __nom_propre;
        Commun __nom_commun;
        VerbeAction __verbe_action;
        
    } __categories;
    
    private :
    
    /* Le tableau de chaînes de caractères permet de définir le type exacte de la famille,
       et de retrouver la classe grammaticale, la catégorie et les propriétés qui lui sont associées. */
    
    std::vector <std::string> __type;
};

#endif /* Type_hpp */
