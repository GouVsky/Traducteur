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

class Invariable
{
    public :
    
    std::string le_mot_est_invariable(std::string mot, std::string l_source, std::string l_sortie);
    
    private :
    
    std::string langue_source, langue_sortie;
    std::map <std::string, std::string> invariable;
};

#endif /* defined(__Traducteur_universel__motInvariable__) */