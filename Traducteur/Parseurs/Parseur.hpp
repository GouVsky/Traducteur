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

#include "Mot.hpp"
#include "ChampsLexicaux.hpp"


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie);
    std::vector <std::string> & recuperer_types() { return __types; };
    std::vector <std::vector <Mot>> & recuperer_mots() { return __mots; };
    std::vector <std::vector <ChampsLexicaux>> & recuperer_champs_lexicaux() { return __champs_lexicaux; };
    void parser_champs_lexicaux(std::string champs_lexicaux);
    void parser_types(std::string types);
    void parser_mots(std::string mots);
    virtual bool parser(std::string mot_a_trouver);
    
    private :
    
    std::string _types,
                _fichier,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <std::string, std::string> __mots_fichier;

    
    std::vector <std::string> __types;
    
    std::vector <std::vector <Mot>> __mots;
    
    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* Parseur_hpp */
