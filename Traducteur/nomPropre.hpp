//
//  nomPropre.hpp
//  Traducteur
//
//  Created by Grégoire on 26/01/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef nomPropre_hpp
#define nomPropre_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

class NomPropre
{
    public :
    
    std::tuple <std::string, std::vector <std::string>> le_mot_est_un_nom_propre(std::string mot);
    
    private :
    
    std::string prenom;
    std::map <int, std::string> genre;
};

#endif /* nomPropre_hpp */
