//
//  motInvariable.h
//  Traducteur_universel
//
//  Created by Grégoire on 13/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#ifndef __Traducteur_universel__motInvariable__
#define __Traducteur_universel__motInvariable__

#include <map>
#include <string>
#include <fstream>
#include <stdio.h>

#include "Mot.hpp"

class Invariable : public Mot
{
    public :
    
    Invariable(std::string source, std::string sortie);
    void le_mot_est_invariable(std::string mot);
    
    private :
    
    std::string _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <std::string, std::string> __invariable;
};

#endif /* defined(__Traducteur_universel__motInvariable__) */
