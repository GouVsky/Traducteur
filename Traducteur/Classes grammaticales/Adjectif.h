//
//  adjectif.h
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#ifndef __Traducteur_universel__adjectif__
#define __Traducteur_universel__adjectif__

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>

#include "Mot.hpp"

class Adjectif
{
    public :
    
    Adjectif();
    std::string accorder_pluriel(std::string adjectif, std::string langue);
    std::string accorder_feminin(std::string adjectif, std::string langue);
};

#endif /* defined(__Traducteur_universel__adjectif__) */
