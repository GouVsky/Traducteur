//
//  ConstructeurExpression.hpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef ConstructeurExpression_hpp
#define ConstructeurExpression_hpp

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "config.hpp"

class ConstructeurExpression
{
    public :
    
    ConstructeurExpression(std::string fichier);
    std::string recuperer_mots(int mot) { return __mots_expression_traduite[mot]; };
    size_t recuperer_taille_source() { return _taille_source; };
    size_t recuperer_taille_sortie() { return __mots_expression_traduite.size(); };
    bool construire_expression(std::vector <std::string> mots);
    
    private :
    
    std::string _fichier;

    size_t _taille_source;
    
    std::map <int, std::string> __expression;

    std::vector <std::string> __mots_expression_traduite;
};

#endif /* ConstructeurExpression_hpp */
