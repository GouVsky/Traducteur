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

    std::map <std::string, int> liste_champs_lexicaux = {{"-", 0},
                                                         {"MER", 1},
                                                         {"NOM", 2},
                                                         {"CORPS", 3},
                                                         {"RESEAU", 4},
                                                         {"MUSIQUE", 5},
                                                         {"MOBILIER", 6},
                                                         {"DISTANCE", 7},
                                                         {"PRINTEMPS", 8},
                                                         {"TU_ES_UN_SORCIER_HARRY", 9},
                                                         {"NATURE", 10},
                                                         {"FOURNITURE", 11}};
};

#endif /* champsLexicaux_hpp */
