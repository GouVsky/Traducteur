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
    
    std::tuple <std::string, int, int> determine_si_existe_une_expression_dans_la_phrase(int compteur, std::vector <std::string> phrase, std::string l_source, std::string l_sortie);
    
    private :
    
    std::map <std::string, std::string> expression;
    std::string phrase, langue_source, langue_sortie;
    int taille_expression_source = 0, taille_expression_sortie = 0;
};

#endif /* defined(__Traducteur_universel__expression__) */
