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
    
    Affinage(std::string sortie, std::vector <std::vector <std::string>> * phrases, std::vector <std::vector <std::string>> * structure);
    void accord_des_mots();
    void nouvelle_organisation();
    void affiner_phrases();
    
    private :
    
    std::string _langue_sortie;
    
    std::vector <std::vector <std::string>> * __phrases,
                                            * __structure;
};

#endif /* AffinagePhrase_hpp */
