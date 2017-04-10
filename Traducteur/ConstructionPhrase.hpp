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

#include "Mot.hpp"
#include "ChampsLexicaux.hpp"

class Phrase
{
    public :
    
    Phrase(std::string source, std::string sortie, std::string texte);
    std::string recuperer_phrase() const { return _phrase_sortie; };
    void choix_des_mots_selon_champ_lexical();
    void traduction_des_mots(std::vector <std::string> phrase, bool virgule);
    void recherche_virgule();
    void construire_la_phrase();
    
    private :
    
    ChampsLexicaux __champ_lexical;
    
    std::string _langue_source,
    _langue_sortie,
    _phrase_source,
    _phrase_sortie;
    
    bool _presence_verbe;
    
    int _indice_sous_phrase;
    
    std::vector <std::vector <Mot>> __mots;
    
    std::vector <std::vector <std::string>> __phrase;
};

#endif /* constructionPhrase_hpp */
