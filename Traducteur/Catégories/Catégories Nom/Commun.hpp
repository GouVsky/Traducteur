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

#include "Nom.hpp"


class Commun : public Nom
{
    public :
    
    Commun();
    void ajouter_pluriel(std::string & nom_commun);
};

#endif /* Commun_hpp */
