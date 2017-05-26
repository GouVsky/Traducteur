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
    
    ChampsLexicaux();
    ChampsLexicaux & operator=(ChampsLexicaux champs_lexicaux);
    ChampsLexicaux operator+(ChampsLexicaux champs_lexicaux);
    size_t recuperer_nombre_champs_lexicaux() const { return __liste_champs_lexicaux.size(); };
    int recuperation_valeur_plus_grand_champ_lexical_commun(ChampsLexicaux champs_lexicaux);
    void incrementation_du_champ_lexical(std::string champ_lexical);
    
    private :
    
    std::map <std::string, int> __liste_champs_lexicaux;
};

#endif /* champsLexicaux_hpp */
