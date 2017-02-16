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
    
    Sujet(std::string source, std::string sortie);
    int transforme_groupe_nominal_sujet_en_pronom(std::vector <std::string> * tableau);
    int creation_du_sujet(std::vector <std::string> * structure_de_la_phrase);
    
    private :
    
    std::string langue_source, langue_sortie;
    
    std::string pp[9] = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
};

#endif /* sujet_hpp */
