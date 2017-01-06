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
#include <sstream>
#include <stdio.h>
#include <fstream>

class Sujet
{
    public :
    
    int transforme_groupe_nominal_sujet_en_pronom(std::vector <std::string> tableau);
    int creation_du_sujet(std::vector <std::string> structure_de_la_phrase, std::string l_source, std::string l_sortie);
    
    private :
    
    int debut = 0;
    std::string langue_source, langue_sortie;
    
    std::string pp[9] = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
};

#endif /* sujet_hpp */
