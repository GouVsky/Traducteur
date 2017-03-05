//
//  sujet.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef sujet_hpp
#define sujet_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>

class Sujet
{
    public :
    
    Sujet(std::vector <std::vector <std::string>> structure);
    int recuperer_valeur() { return _valeur; };
    void transforme_groupe_nominal_sujet_en_pronom(std::vector <std::string> structure);
    void creation_du_sujet();
    
    private :
    
    int _valeur;
    
    std::vector <std::string> __structure_phrase,
                              __structure_sujet;
};

#endif /* sujet_hpp */
