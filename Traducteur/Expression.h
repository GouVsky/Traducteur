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

class Expression
{
    public :
    
    Expression(std::string source, std::string sortie);
    int recuperer_taille_expression_sortie() const { return _taille_expression_sortie; };
    int recuperer_taille_expression_source() const { return _taille_expression_source; };
    std::string recuperer_expression() { return __expression[_langue_sortie]; };
    bool expression_existe() const { return _expression_existe; };
    void determine_si_existe_une_expression_dans_la_phrase(int compteur, std::vector <std::string> phrase);
    
    private :
    
    bool _expression_existe;
    
    std::string _expression,
                _langue_source,
                _langue_sortie;
    
    int _taille_expression_source,
        _taille_expression_sortie;
    
    std::map <std::string, std::string> __expression;
};

#endif /* defined(__Traducteur_universel__expression__) */
