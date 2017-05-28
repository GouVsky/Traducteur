//
//  ParseurChampsLexicaux.hpp
//  Traducteur
//
//  Created by Grégoire on 28/05/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurChampsLexicaux_hpp
#define ParseurChampsLexicaux_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

#include "ChampsLexicaux.hpp"


class ParseurChampsLexicaux
{
    public :
    
    ParseurChampsLexicaux();
    std::vector <ChampsLexicaux> parser(std::string champs_lexicaux);
    
    private :
    
    std::vector <ChampsLexicaux> __champs_lexicaux;
};

#endif /* ParseurChampsLexicaux_hpp */
