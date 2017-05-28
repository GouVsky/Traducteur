//
//  expression.h
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#ifndef __Traducteur_universel__expression__
#define __Traducteur_universel__expression__

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

#include "Groupe.hpp"

class ParseurExpression
{
    public :
    
    ParseurExpression(std::string source, std::string sortie);
    std::string recuperer_expression() { return _expression; };
    bool parser_fichier(std::string mot, std::vector <Groupe> & groupes);
    
    private :
    
    bool _expression_existe;
    
    std::string _expression,
                _langue_source,
                _langue_sortie;
        
    std::map <std::string, std::string> __expression;
    
    std::string _fichier = "./Resources/Dictionnaire/expressions.txt";
};

#endif /* defined(__Traducteur_universel__expression__) */
