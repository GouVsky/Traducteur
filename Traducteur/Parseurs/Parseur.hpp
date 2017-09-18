//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Parseur_hpp
#define Parseur_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Mot.hpp"
#include "Type.hpp"
#include "Groupe.hpp"
#include "ChampsLexicaux.hpp"

#include "ParseurVerbe.hpp"


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie, std::string fichier);
    size_t recuperer_nombre_types() const { return __types.size(); };
    size_t recuperer_nombre_mots() const { return __mots_sorties.size(); };
    size_t recuperer_nombre_champs_lexicaux() const { return __champs_lexicaux.size(); };
    Type & recuperer_type(int indice) { return __types[indice]; };
    std::vector <Mot> & recuperer_mots(int indice) { return __mots_sorties[indice]; };
    std::vector <ChampsLexicaux> & recuperer_champs_lexicaux(int indice) { return __champs_lexicaux[indice]; };
    void parser_champs_lexicaux(std::string champs_lexicaux);
    void parser_types(std::string types);
    void parser_mots(std::string mots, std::vector <std::vector <Mot>> & tableau_a_remplir);
    virtual bool parser(std::string mot_a_trouver, std::vector <Groupe> & groupes);
    
    private :
    
    std::string _types,
                _fichier,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <std::string, std::string> __mots_fichier;

    
    std::vector <Type> __types;
    
    std::vector <std::vector <Mot>> __mots_sources,
                                    __mots_sorties;
    
    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* Parseur_hpp */
