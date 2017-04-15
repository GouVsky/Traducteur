//
//  constructionPhrase.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef constructionPhrase_hpp
#define constructionPhrase_hpp

#include <map>
#include <thread>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>

#include "Parseur.hpp"
#include "ParseurVerbe.hpp"

#include "Groupe.hpp"
#include "Famille.hpp"

#include "Verbe.hpp"
#include "Adjectif.h"
#include "Invariable.h"
#include "NomPropre.hpp"
#include "NomCommun.hpp"
#include "PronomPersonnel.hpp"

#include "ParseurExpression.h"

#include "ChampsLexicaux.hpp"


class Phrase
{
    public :
    
    Phrase(std::string phrase, std::string langue_source, std::string langue_sortie);
    std::string recuperer_phrase_traduite() const { return _phrase_sortie; };
    void choix_des_mots_selon_les_champs_lexicaux(int numero_sous_phrase);
    void incrementer_les_champs_lexicaux(Famille & famille);
    Groupe traduction(std::string mot);
    void construire_les_sous_phrases();
    void construire_la_phrase();
    
    private :
    
    ChampsLexicaux __champs_lexicaux;
    
    std::string _phrase_source,
                _phrase_sortie,
                _langue_source,
                _langue_sortie;
    
    std::vector <Groupe> __groupes;
    
    std::vector <std::string> __sous_phrases_sorties;
    
    // Chaque sous-phrase initiales contient un ensemble de groupes.
    
    std::vector <std::vector <Groupe>> __sous_phrases_sources;
};

#endif /* constructionPhrase_hpp */
