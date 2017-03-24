//
//  champsLexicaux.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 27/04/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef champsLexicaux_hpp
#define champsLexicaux_hpp

#include <map>
#include <vector>
#include <string>
#include <stdio.h>


class ChampsLexicaux
{
    public :
    
    ChampsLexicaux();
    int recuperation_valeur_champ_lexical(std::string champ_lexical) { __liste_champs_lexicaux[champ_lexical]; };
    void incrementation_des_champs_lexicaux(std::string champ_lexical);
    
    private :
    
    std::map <std::string, int> __liste_champs_lexicaux;
};

#endif /* champsLexicaux_hpp */
