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

#include "Mot.hpp"

class NomPropre : public Mot
{
    public :
    
    NomPropre();
    std::string recuperer_genre() const { return _genre; };
    void le_mot_est_un_nom_propre(std::string mot);
    
    private :
    
    std::string _nom_propre,
                _genre;
    
    std::map <int, std::string> __genre;
};

#endif /* nomPropre_hpp */
