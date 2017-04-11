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
#include <sstream>

#include "ChampsLexicaux.hpp"


class Mot
{
    public :
    
    Mot(std::string mot);
    int recuperer_nombre_de_champs_lexicaux() const { return __champs_lexicaux.size(); };
    std::string recuperer_champs_lexicaux(int numero_champ_lexical) const { return __champs_lexicaux[numero_champ_lexical]; };
    std::string recuperer_mot() const { return _mot; };
    void definir_les_differents_champs_lexicaux(std::string ensemble_champ_lexicaux);
    
    private :
    
    std::string _mot;
        
    std::vector <std::string> __champs_lexicaux;
};

#endif /* Mot_hpp */
