//
//  adjectif.h
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#ifndef __Traducteur_universel__adjectif__
#define __Traducteur_universel__adjectif__

#include <string>
#include <stdio.h>

class Adjectif
{
    public :
    
    Adjectif();
    static std::string accorder_pluriel(std::string adjectif, std::string langue);
    static std::string accorder_feminin(std::string adjectif, std::string langue);
};

#endif /* defined(__Traducteur_universel__adjectif__) */
