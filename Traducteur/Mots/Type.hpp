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

#include "Commun.hpp"
#include "Propre.hpp"
#include "Action.hpp"
#include "Pronom.hpp"
#include "Adjectif.hpp"
#include "Invariable.hpp"


/* Cette structure permet de définir le type exacte de la famille,
   et de retrouver la classe grammaticale, la catégorie et les propriétés qui lui sont associées.
 
   - niveau 0 : classe
   - niveau 1 : catégorie
   - niveau 2 : propriété
 
   Une classe est associée à chaque niveau. Chacun hérite du niveau qui le précède dans la hiérarchie.
   Si un niveau n'existe pas, on remonte d'un niveau d'abstraction. */

struct __Types
{
    Commun * commun = nullptr;
    Propre * propre = nullptr;
    VerbeAction * action = nullptr;
    Pronom * pronom = nullptr;
    Adjectif * adjectif = nullptr;
    Invariable * invariable = nullptr;
};


class Type
{
    public :
    
    Type();
    Type(std::vector <std::string> type);
    Type operator+(Type type);
    void definir_classe(std::string classe);
    void definir_categorie(std::string categorie);
    void definir_propriete(std::string propriete);
    std::string recuperer_classe() const { return _classe; }
    std::string recuperer_categorie() const { return _categorie; }
    std::string recuperer_propriete() { return _propriete; }
    std::string recuperer_type() const { return _classe + '_' + _categorie + '_' + _propriete; }
    __Types & recuperer_structure_types() { return __types; }
    
    private :
    
    __Types __types;
    
    std::string _classe,
                _categorie,
                _propriete;
};

#endif /* Type_hpp */
