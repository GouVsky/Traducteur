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

#include "Groupe.hpp"
#include "Famille.hpp"
#include "Parseur.hpp"
#include "ChampsLexicaux.hpp"
#include "ConstructeurExpression.hpp"


class Phrase
{
    public :
    
    Phrase(std::vector <std::string> mots_source, std::string langue_source, std::string langue_sortie);
    size_t recuperer_nombre_mots(int sous_phrase) { return __phrases_sortie_sens_unique[sous_phrase].size(); };
    size_t recuperer_nombre_sous_phrases() { return __phrases_sortie_sens_unique.size(); };
    size_t recuperer_nombre_expressions() { return __expressions.size(); };
    Mot & recuperer_mot(int sous_phrase, int mot) { return __phrases_sortie_sens_unique[sous_phrase][mot]; };
    ConstructeurExpression & recuperer_expression(int expression) { return __expressions[expression]; };
    void traduire();
    
    private :
    
    void choix_des_mots_selon_les_champs_lexicaux(std::vector <Groupe> & groupe, int indice);
    void incrementer_les_champs_lexicaux(Famille & famille);
    Groupe traduire_mot(std::string mot);
    

    std::string _langue_source,
                _langue_sortie;
    
    ChampsLexicaux __champs_lexicaux;
    
    std::vector <std::string> __mots_source;
    
    std::vector <ConstructeurExpression> __expressions;
    
    // Ce tableau est utilisé pour considérer les cas de phrases à virgule.
    // Un traitement est effectué afin de savoir si ces sous-phrases sont indépendantes ou non.
    std::vector <std::vector <Groupe>> __phrases_sortie_plusieurs_sens;

    // Ce tableau est contenu dans le précédent.
    // Il s'agit donc des mots contenus dans une sous-phrase.
    std::vector <Groupe> __groupes;
    
    // Ce tableau contient les différents mots une fois le traitement des champs lexicaux terminé.
    std::vector <std::vector <Mot>> __phrases_sortie_sens_unique;
    
    std::vector <std::string> __structure;
};

#endif /* constructionPhrase_hpp */
