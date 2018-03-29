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

class ConstructeurExpression
{
    public :
    
    ConstructeurExpression(std::string source, std::string sortie);
    std::string recuperer_mots(int mot) { return __mots_expression_traduite[mot]; };
    size_t recuperer_taille_source() { return _taille_source; };
    size_t recuperer_taille_sortie() { return __mots_expression_traduite.size(); };
    bool construire_expression(std::vector <std::string> mots);
    
    private :
    
    size_t _taille_source;
    
    std::string _langue_source,
                _langue_sortie;
    
    std::vector <std::string> __mots_expression_traduite;
    
    std::map <std::string, std::string> __expression;
};

#endif /* ConstructeurExpression_hpp */
