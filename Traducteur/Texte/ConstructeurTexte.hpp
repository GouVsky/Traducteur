//
//  ConstructeurTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 15/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef ConstructeurTexte_hpp
#define ConstructeurTexte_hpp

#include <stdio.h>

#include "config.hpp"
#include "ConstructeurPhrase.hpp"


class ConstructeurTexte
{
    public :
    
    ConstructeurTexte(std::string texte);
    std::string recuperer_texte_traduit() { return _texte_traduit; };
    void construire_texte();
    
    private :
    
    ConstructeurPhrase __constructeur_phrase;
    
    std::string _texte_source,
                _texte_traduit;
};

#endif /* ConstructeurTexte_hpp */
