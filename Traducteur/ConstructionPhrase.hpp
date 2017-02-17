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

#include "ChampsLexicaux.hpp"

class Phrase
{
    public :
    
    Phrase(std::string source, std::string sortie, std::string texte);
    std::string recuperer_phrase();
    void ajouter_le_champ_lexical(std::string champ_lexical, int numero);
    void ajouter_le_type_sortie(std::string type);
    void ajouter_le_type_source(std::string type);
    void ajouter_le_mot_sortie(std::string mot);
    void choix_des_mots_selon_champ_lexical();
    void traduction_des_mots(std::vector <std::string> phrase, bool virgule);
    void recherche_virgule();
    
    private :
    
    ChampsLexicaux champ_lexical;
    
    std::string _langue_source,
                _langue_sortie,
                _phrase_source,
                _phrase_sortie;
    
    bool presence_verbe;
    
    int indice_mot,
        indice_sous_phrase;
    
    std::vector <std::string> t_final,
                              t_structure;
    
    std::vector <std::vector <std::vector <std::string>>> structure_du_texte_source,
                                                          structure_du_texte_sortie,
                                                          tableau_contenant_significations_mot;
    
    std::vector <std::vector <std::vector <std::vector <std::string>>>> tableau_contenant_champs_lexicaux;
    
    std::map <std::string, std::string *> pronom_personnel;
};

#endif /* constructionPhrase_hpp */
