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
    
    enum __langues {ANGLAIS, FRANCAIS};
    
    static std::string fichier_mots;
    static std::string fichier_formes;
    static std::string fichier_expressions;
    static std::string dossier_terminaisons;
};

#endif /* config_hpp */
