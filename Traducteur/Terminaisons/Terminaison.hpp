//
//  terminaison.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef terminaison_hpp
#define terminaison_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>


class Terminaison
{
    public :
    
    Terminaison(std::string langue);
    std::string recuperer_ancienne_terminaison() const { return _ancienne_terminaison; };
    std::string recuperer_nouvelle_terminaison(int sujet) const { return (__nouvelles_terminaisons.size() > 0 ? __nouvelles_terminaisons[sujet] : ""); };
    void parser_terminaisons(std::string verbe, std::string temps, int groupe);
    
    private :
    
    void ancienne_terminaison_troisieme_groupe(std::string verbe);

    
    std::string _langue,
                _ancienne_terminaison;
    
    std::vector <std::string> __nouvelles_terminaisons;
    
    std::string _fichier = "./Resources/Dictionnaire/Terminaisons/";
};

#endif /* terminaison_hpp */
