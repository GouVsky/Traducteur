//
//  DonneesFormeVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 06/12/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef DonneesFormeVerbe_hpp
#define DonneesFormeVerbe_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

class DonneesFormeVerbe
{
    public :
    
    DonneesFormeVerbe();
    size_t recuperer_nombre_formes(std::string langue) { return __temps[langue].size(); };
    void ajouter_temps(std::string temps, std::string langue);
    void ajouter_forme(std::vector <std::string> forme, std::string langue);
    std::string recuperer_temps(std::string langue, int temps) { return __temps[langue][temps]; };
    std::vector <std::string> & recuperer_formes(std::string langue, int temps) { return __formes_decoupees[langue][temps]; };
    
    
    private :
    
    std::map <std::string, std::vector <std::string>> __temps;
    
    std::map <std::string, std::vector <std::vector <std::string>>> __formes_decoupees;
};

#endif /* DonneesFormeVerbe_hpp */
