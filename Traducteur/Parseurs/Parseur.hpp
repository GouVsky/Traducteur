//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Parseur_hpp
#define Parseur_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "ChampsLexicaux.hpp"


class Parseur
{
    public :
    
    Parseur();
    std::vector <std::vector <std::string>> & recuperer_mots() { return __mots; };
    std::vector <std::string> & recuperer_types() { return __types; };
    std::vector <std::vector <ChampsLexicaux>> & recuperer_champs_lexicaux() { return __champs_lexicaux; };
    void parser_champs_lexicaux(std::string champs_lexicaux);
    void parser_types(std::string types);
    void parser_mots(std::string mots);
    
    private :
    
    std::vector <std::string> __types;
    
    std::vector <std::vector <std::string>> __mots;
    
    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* Parseur_hpp */
