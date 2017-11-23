//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <string>
#include <vector>
#include <stdio.h>


class Verbe
{
    public :
    
    Verbe();
    static std::string recuperer_forme_verbe_irregulier(std::string langue, std::string temps, int sujet);
};

#endif /* verbe_hpp */
