//
//  Testeur.hpp
//  Traducteur
//
//  Created by Grégoire on 23/01/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef Testeur_hpp
#define Testeur_hpp

#include <string>
#include <stdio.h>

#include "DonneesMot.hpp"


class TesteurMot
{
    public :
    
    TesteurMot();
    bool tester_mot(std::string mot, std::string langue, DonneesMot & donnees);
};

#endif /* Testeur_hpp */
