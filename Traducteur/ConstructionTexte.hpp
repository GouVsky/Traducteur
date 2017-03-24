//
//  ConstructionTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 17/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ConstructionTexte_hpp
#define ConstructionTexte_hpp

#include <map>
#include <vector>
#include <string>
#include <stdio.h>

#include "ConstructionPhrase.hpp"


class Texte
{
    public :
    
    Texte(std::string source, std::string sortie);
    std::string recuperer_texte_traduit() const { return _texte_traduit; };
    void assembler_les_phrases();
    void recherche_conjonction_coordination(std::vector <std::string> tableau);
    void recherche_de_la_ponctuation(std::string texte);
    void construction_du_texte(std::string texte);
    
    private :
    
    int _nombre_de_phrases;
    
    std::string _langue_source,
                _langue_sortie,
                _texte_traduit;
    
    std::vector <Phrase> __phrase;
    
    std::vector <char> __ponctuation;
    
    std::map <std::string, std::vector <std::string>> __conjonction_coordination;
};

#endif /* ConstructionTexte_hpp */
