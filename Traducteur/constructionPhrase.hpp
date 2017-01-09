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

class Phrase
{
    public :
    
    Phrase();
    void assemblage_des_phrases();
    void choix_des_mots_selon_champ_lexical(int indice);
    void traduction_des_mots(std::vector <std::string> phrase, int indice, bool virgule);
    void recherche_conjonction_coordination(std::vector <std::string> tableau);
    void recherche_virgule(std::string phrase, int indice);
    void recherche_de_la_ponctuation(std::string texte);
    std::tuple <std::string, std::vector <std::string>> construction_du_texte(std::string texte, std::string l_source, std::string l_sortie);
    
    private :
    
    std::vector <char> t_ponctuation;
    std::vector <bool> presence_verbe;
    std::vector <int> indice_mot, indice_sous_phrase, indice_chp_lexical;
    std::string langue_source, langue_sortie, phrase_finale;
    std::map <std::string, std::string*> conjonction_coordination, pronom_personnel;
    
    std::vector <std::vector <std::string>> t_final;
    
    std::vector <std::string> t_structure, phrases_constituantes_le_texte;
    
    std::vector <std::vector <std::vector <std::vector <std::string>>>> structure_du_texte_source;
    std::vector <std::vector <std::vector <std::vector <std::string>>>> structure_du_texte_sortie;
    std::vector <std::vector <std::vector <std::vector <std::string>>>> tableau_contenant_significations_mot;
    std::vector <std::vector <std::vector <std::vector <std::vector <std::string>>>>> tableau_contenant_champs_lexicaux;
    
    std::string cc_a[6] = {"but", "where", "so", "because", "when", "if"};
    std::string cc_f[8] = {"mais", "où", "donc", "or", "ni", "car", "parce-que", "quand"};
    
    std::string pp_a[9] = {"i", "you", "he", "she", "it", "we", "you", "they", "they"};
    std::string pp_f[9] = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
};

#endif /* constructionPhrase_hpp */
