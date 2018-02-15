//
//  constructionPhrase.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef constructionPhrase_hpp
#define constructionPhrase_hpp


#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

#include "Parseur.hpp"

#include "Groupe.hpp"
#include "Famille.hpp"

#include "ChampsLexicaux.hpp"


class Phrase
{
    public :
    
    Phrase(std::vector <std::string> mots_source, std::string langue_source, std::string langue_sortie);
    size_t recuperer_nombre_mots(int sous_phrase) { return __phrases_sortie_sens_unique[sous_phrase].size(); };
    size_t recuperer_nombre_sous_phrases() { return __phrases_sortie_sens_unique.size(); };
    Mot & recuperer_mot(int sous_phrase, int mot) { return __phrases_sortie_sens_unique[sous_phrase][mot]; };
    void traduire();
    
    private :
    
    void choix_des_mots_selon_les_champs_lexicaux(std::vector <Groupe> & groupe, int indice);
    void incrementer_les_champs_lexicaux(Famille & famille);
    Groupe traduire_mot(std::string mot);
    

    std::string _langue_source,
                _langue_sortie;
    
    std::vector <Groupe> __groupes;

    ChampsLexicaux __champs_lexicaux;
    
    std::vector <std::string> __mots_source;

    std::vector <std::vector <Mot>> __phrases_sortie_sens_unique;
    
    std::vector <std::vector <Groupe>> __phrases_sortie_plusieurs_sens;
};

#endif /* constructionPhrase_hpp */
