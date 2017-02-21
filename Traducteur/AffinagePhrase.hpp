//
//  AffinagePhrase.hpp
//  Traducteur
//
//  Created by Grégoire on 20/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef AffinagePhrase_hpp
#define AffinagePhrase_hpp

#include <string>
#include <vector>
#include <stdio.h>


class Affinage
{
    public :
    
    Affinage(std::string source, std::string sortie);
    std::string recuperer_phrase_sortie();
    void affiner_phrases(std::vector <std::vector <std::string>> phrase, std::vector <std::vector <std::string>> structure);
    
    private :
    
    std::string _phrase_sortie,
                _langue_source,
                _langue_sortie;
};

#endif /* AffinagePhrase_hpp */
