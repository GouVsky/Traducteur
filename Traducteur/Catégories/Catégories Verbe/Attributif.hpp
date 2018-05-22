//
//  Attributif.hpp
//  Traducteur
//
//  Created by Grégoire on 13/05/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef Attributif_hpp
#define Attributif_hpp

#include <string>
#include <stdio.h>

#include "Verbe.hpp"


class VerbeAttributif : public Verbe
{
    public :
    
    VerbeAttributif();
    VerbeAttributif(std::string propriete);
};

#endif /* Attributif_hpp */
