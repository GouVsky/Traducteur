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
    Famille & recuperer_famille(int langue, int famille) { return __famille[langue][famille]; };
    std::vector <ChampsLexicaux> & recuperer_champs_lexicaux(int langue, int famille) { return __champs_lexicaux[famille]; };
    size_t recuperer_nombre_sens(int langue, int famille) { return __famille[langue][famille].recuperer_nombre_de_sens_sortie(); };
    size_t recuperer_nombre_familles(int langue) { return __famille[langue].size(); };
    void ajouter_type(std::vector <std::string> types);
    void ajouter_famille(std::vector <std::string> mots, int);
    void ajouter_champs_lexicaux(std::vector <std::vector <std::string>> champs_lexicaux);
    void reinitialisation();
    
    private :
    
    std::vector <Type> __types;
    
    std::map <int, std::vector <Famille>> __famille;

    std::vector <std::vector <ChampsLexicaux>> __champs_lexicaux;
};

#endif /* DonneesMot_hpp */
