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

class Adjectif : public Mot
{
    public :
    
    Adjectif(std::string source, std::string sortie);
    std::string accorder_pluriel(std::string adjectif);
    std::string accorder_feminin(std::string adjectif);
    void le_mot_est_un_adjectif(std::string mot);
    
    private :
    
    std::string _langue_source,
                _langue_sortie,
                _champs_lexicaux;

    std::map <std::string, std::string> __adjectif;
};

#endif /* defined(__Traducteur_universel__adjectif__) */
