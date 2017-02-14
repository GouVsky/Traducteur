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

#include "champsLexicaux.hpp"

class Adjectif
{
    public :
    
    Adjectif(std::string source, std::string sortie);
    std::tuple <std::string, std::string> le_mot_est_un_adjectif(std::string mot, ChampsLexicaux * champs_lexicaux);
    
    private :
    
    std::map <std::string, std::string> adjectif;
    std::string champ_lexical, langue_source, langue_sortie;
};

#endif /* defined(__Traducteur_universel__adjectif__) */
