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
    int recuperation_valeur_champ_lexical(std::string champ_lexical);
    void incrementation_des_champs_lexicaux(std::string champ_lexical);
    
    private :
    
    std::vector <int> __tableau_des_champs_lexicaux;

    std::map <std::string, int> __liste_champs_lexicaux = {{"MER", 0},
                                                           {"NOM", 1},
                                                           {"CORPS", 2},
                                                           {"RESEAU", 3},
                                                           {"MUSIQUE", 4},
                                                           {"MOBILIER", 5},
                                                           {"DISTANCE", 6},
                                                           {"PRINTEMPS", 7},
                                                           {"TU_ES_UN_SORCIER_HARRY", 8},
                                                           {"NATURE", 9},
                                                           {"FOURNITURE", 10}};
};

#endif /* champsLexicaux_hpp */
