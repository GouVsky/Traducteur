//
//  Avoir.hpp
//  Traducteur
//
//  Created by Grégoire on 23/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Avoir_hpp
#define Avoir_hpp

#include <string>
#include <stdio.h>

#include "Auxiliaire.hpp"


class Avoir : public Auxiliaire
{
    public :
    
    Avoir(std::string langue_source, std::string langue_sortie);
};

#endif /* Avoir_hpp */
