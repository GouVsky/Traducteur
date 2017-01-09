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
#include <string>
#include <stdio.h>

class ChampsLexicaux
{
    public :
    
    void initialisation();
    void incrementation_des_champs_lexicaux(std::string champ_lexical);
    int recuperation_tableau(std::string champ_lexical);
    
    private :
    
    static int tableau_des_champs_lexicaux[];

    std::map <std::string, int> liste_champs_lexicaux = {{"MER", 0},
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
