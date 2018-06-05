//
//  ConstructionTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 17/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ConstructionTexte_hpp
#define ConstructionTexte_hpp

#include <thread>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>

#include "Phrase.hpp"
#include "ConstructeurExpression.hpp"


class ConstructeurPhrase
{
    public :
    
    ConstructeurPhrase();
    size_t recuperer_nombre_phrases_traduites() { return __phrases_sorties.size(); };
    std::string recuperer_phrase_traduite(int phrase) { return __phrases_sorties[phrase]; };
    void construire_phrases(std::string texte);
    
    private :
    
    void assembler_sous_phrases_traduites(size_t nombre_phrases);
    void traduction_multithreading(size_t nombre_phrases);
    Phrase decouper_en_mots(std::string phrase);
    void decouper_par_ponctuation(std::string texte);

    
    std::vector <Phrase> __phrases;
    
    std::vector <char> __ponctuation;

    std::vector <std::string> __phrases_sources,
                              __phrases_sorties;
    
    ConstructeurExpression constructeur_expression;
};

#endif /* ConstructionTexte_hpp */
