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

#include "config.hpp"
#include "DonneesFormeVerbe.hpp"

class ParseurFormeVerbe
{
    public :
    
    ParseurFormeVerbe(std::string fichier);
    ~ParseurFormeVerbe();
    DonneesFormeVerbe parser();
    
    private :
    
    std::vector <std::string> parser_forme(std::string forme);
    
    
    std::string _fichier;
};

#endif /* ParseurFormeVerbe_hpp */
