//
//  DonneesMot.hpp
//  Traducteur
//
//  Created by Grégoire on 07/12/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef DonneesMot_hpp
#define DonneesMot_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

#include "Type.hpp"
#include "Famille.hpp"
#include "ChampsLexicaux.hpp"


class DonneesMot
{
    public :
    
    DonneesMot();
    Type & recuperer_type(int famille) { return __types[famille]; };
    Famille & recuperer_famille(std::string langue, int famille) { return __famille[langue][famille]; };
    std::vector <ChampsLexicaux> & recuperer_champs_lexicaux(std::string langue, int famille) { return __champs_lexicaux[famille]; };
    size_t recuperer_nombre_sens(std::string langue, int famille) { return __famille[langue][famille].recuperer_nombre_de_sens_sortie(); };
    size_t recuperer_nombre_familles(std::string langue) { return __famille[langue].size(); };
    void ajouter_type(std::vector <std::string> types);
    void ajouter_famille(std::vector <std::string> mots, std::string langue);
    void ajouter_champs_lexicaux(std::vector <std::vector <std::string>> champs_lexicaux);
    void reinitialisation();
    
    private :
    
    std::vector <Type> __types;
    
    std::map <std::string, std::vector <Famille>> __famille;

    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* DonneesMot_hpp */
