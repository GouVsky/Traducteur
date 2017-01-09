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

class NomCommun
{
    public :
    
    std::tuple <std::vector <std::string>, std::vector <std::vector <std::string>>, std::vector <std::string>, std::string> le_mot_est_un_nom_commun(std::string mot, std::string l_source, std::string l_sortie);
    
    private :
    
    std::map <int, std::string> genre;
    std::map <std::string, std::string> nom;
    std::string prenom, champ_lexical, les_champs_lexicaux, un_des_champs_lexicaux, mot_source, mot_sortie, langue_source, langue_sortie;
};

#endif /* nomCommun_hpp */
