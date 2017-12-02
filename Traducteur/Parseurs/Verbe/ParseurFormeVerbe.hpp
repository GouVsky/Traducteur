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

class ParseurFormeVerbe
{
    public :
    
    ParseurFormeVerbe(std::string langue_source, std::string langue_sortie, std::string fichier);
    std::vector <std::string> & recuperer_temps(std::string langue) { return __temps[langue]; };
    std::vector <std::vector <std::string>> & recuperer_formes(std::string langue) { return __formes_decoupees[langue]; };
    void parser();
    
    private :
    
    std::vector <std::string> recuperer_composants_forme(std::string forme);
    
    
    std::string _fichier,
                _langue_source,
                _langue_sortie;
    
    std::map <std::string, std::vector <std::string>> __temps;
    
    std::map <std::string, std::vector <std::vector <std::string>>> __formes_decoupees;
};

#endif /* ParseurFormeVerbe_hpp */
