//
//  ParseurFormeVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 16/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurFormeVerbe_hpp
#define ParseurFormeVerbe_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <fstream>

#include "DonneesFormeVerbe.hpp"

class ParseurFormeVerbe
{
    public :
    
    ParseurFormeVerbe(std::string langue_source, std::string langue_sortie, std::string fichier);
    ~ParseurFormeVerbe();
    DonneesFormeVerbe parser();
    
    private :
    
    std::vector <std::string> parser_forme(std::string forme);
    
    
    std::string _fichier,
                _langue_source,
                _langue_sortie;
};

#endif /* ParseurFormeVerbe_hpp */
