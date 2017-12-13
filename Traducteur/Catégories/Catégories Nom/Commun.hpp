//
//  Commun.hpp
//  Traducteur
//
//  Created by Grégoire on 15/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Commun_hpp
#define Commun_hpp

#include <string>
#include <stdio.h>

#include "Mot.hpp"
#include "Nom.hpp"


class Commun : public Nom
{
    public :
    
    Commun();
    void accorder_pluriel(Mot & mot, std::string langue);
};

#endif /* Commun_hpp */
