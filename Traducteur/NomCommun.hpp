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

#include "Mot.hpp"
#include "ChampsLexicaux.hpp"

class NomCommun : public Mot
{
    public :
    
    NomCommun(std::string source, std::string sortie, ChampsLexicaux * champs_lexicaux);
    std::string recuperer_nombre();
    std::string recuperer_genre();
    void le_mot_est_un_nom_commun(std::string mot, int genre);
    
    private :
    
    std::string _genre,
                _nombre,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <int, std::string> __genre;
    
    std::map <std::string, std::string> __nom_commun;
};

#endif /* nomCommun_hpp */
