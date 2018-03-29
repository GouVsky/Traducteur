//
//  Mot.hpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Mot_hpp
#define Mot_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "ChampsLexicaux.hpp"


class Mot
{
    public :
    
    Mot();
    Mot(std::string mot);
    Mot & operator=(Mot mot);
    Mot operator+(Mot mot);
    Mot & operator+=(Mot mot);
    ChampsLexicaux & recuperer_champs_lexicaux() { return __champs_lexicaux; };
    std::string & recuperer_mot() { return _mot; };
    void definir_mot(std::string mot);
    void definir_les_differents_champs_lexicaux(ChampsLexicaux champs_lexicaux);
    
    private :
    
    std::string _mot;
    
    ChampsLexicaux __champs_lexicaux;
};

#endif /* Mot_hpp */
