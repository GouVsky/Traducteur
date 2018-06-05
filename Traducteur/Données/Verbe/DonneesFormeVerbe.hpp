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
    size_t recuperer_nombre_formes(int langue) { return __temps[langue].size(); };
    void ajouter_temps(std::string temps, int langue);
    void ajouter_forme(std::vector <std::string> forme, int langue);
    std::string recuperer_temps(int langue, int temps) { return __temps[langue][temps]; };
    std::vector <std::string> & recuperer_formes(int langue, int temps) { return __formes_decoupees[langue][temps]; };
    
    
    private :
    
    std::map <int, std::vector <std::string>> __temps;
    
    std::map <int, std::vector <std::vector <std::string>>> __formes_decoupees;
};

#endif /* DonneesFormeVerbe_hpp */
