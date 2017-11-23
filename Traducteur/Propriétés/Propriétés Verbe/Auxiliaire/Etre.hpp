//
//  Etre.hpp
//  Traducteur
//
//  Created by Grégoire on 22/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Etre_hpp
#define Etre_hpp

#include <string>
#include <stdio.h>

#include "Auxiliaire.hpp"


class Etre : public Auxiliaire
{
    public :
    
    Etre(std::string langue_source, std::string langue_sortie);
};

#endif /* Etre_hpp */
