//
//  config.hpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef config_hpp
#define config_hpp

#include <string>
#include <stdio.h>


class config
{
    public :
    
    static int langue_source;
    static int langue_sortie;
    
    enum Langues {ANGLAIS, FRANCAIS};
};

#endif /* config_hpp */
