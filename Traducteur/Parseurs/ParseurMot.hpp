//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurMot_hpp
#define ParseurMot_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Parseur.hpp"


class ParseurMot : public Parseur
{
    public :
    
    ParseurMot(std::string source, std::string sortie);
    bool chercher_mot(std::string mot_source);
    
    private :
    
    bool _mot_trouve;
    
    std::string _types,
                _mot_source,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <std::string, std::string> __mots;
    
    
    std::string _fichier = "./Resources/Dictionnaire/mots.txt";
};

#endif /* ParseurMot_hpp */
