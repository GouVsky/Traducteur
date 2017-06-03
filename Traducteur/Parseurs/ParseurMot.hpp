//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
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

#include "ParseurChampsLexicaux.hpp"


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie);
    std::vector <std::vector <std::string>> & recuperer_sens_sortie() { return __sens_sortie; };
    std::vector <std::string> & recuperer_types() { return __types; };
    std::vector <std::vector <ChampsLexicaux>> & recuperer_champs_lexicaux() { return __champs_lexicaux; };
    bool parser_fichier(std::string mot_source);
    
    private :
    
    bool _mot_trouve;
    
    std::string _types,
                _mot_source,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::vector <std::string> __types;
    
    std::vector <std::vector <std::string>> __sens_sortie;
    
    std::string _fichier = "./Resources/Dictionnaire/mots.txt";
    
    std::map <std::string, std::string> __mots;
    
    
    ParseurChampsLexicaux parseur_champs_lexicaux;
    
    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* Parseur_hpp */
