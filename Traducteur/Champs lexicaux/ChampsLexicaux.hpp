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
#include <vector>
#include <stdio.h>


class ChampsLexicaux
{
    public :
    
    ChampsLexicaux();
    ChampsLexicaux(std::vector <std::string> champs_lexicaux);
    ChampsLexicaux & operator=(ChampsLexicaux champs_lexicaux);
    ChampsLexicaux operator+(ChampsLexicaux champs_lexicaux);
    std::pair <std::string, int> recuperer_champ_lexical_dominant() { return __champ_lexical_dominant; };
    size_t recuperer_nombre_champs_lexicaux() const { return __liste_champs_lexicaux.size(); };
    void recuperation_plus_grand_champ_lexical_commun(ChampsLexicaux & champs_lexicaux);
    
    private :
    
    void incrementation_du_champ_lexical(std::string champ_lexical);

    
    std::map <std::string, int> __liste_champs_lexicaux;
    
    std::pair <std::string, int> __champ_lexical_dominant;
};

#endif /* champsLexicaux_hpp */
