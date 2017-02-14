//
//  nomCommun.hpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef nomCommun_hpp
#define nomCommun_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "champsLexicaux.hpp"

class NomCommun
{
    public :
    
    NomCommun(std::string source, std::string sortie);
    std::tuple <std::vector <std::string>, std::vector <std::vector <std::string>>, std::vector <std::string>, std::string> le_mot_est_un_nom_commun(std::string mot, ChampsLexicaux * champs_lexicaux);
    
    private :
    
    std::map <int, std::string> genre;
    std::map <std::string, std::string> nom;
    
    std::string mot_source,
                mot_sortie,
                langue_source,
                langue_sortie,
                champ_lexical,
                les_champs_lexicaux,
                un_des_champs_lexicaux;
};

#endif /* nomCommun_hpp */
