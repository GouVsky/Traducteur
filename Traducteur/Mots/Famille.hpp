//
//  Famille.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Famille_hpp
#define Famille_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

#include "Mot.hpp"
#include "Type.hpp"
#include "ChampsLexicaux.hpp"


class Famille
{
    public :
    
    Famille(std::vector <std::string> mots);
    Famille & operator=(Famille famille);
    Type & recuperer_type() { return __type; };
    std::vector <Mot> & recuperer_mots() { return __mots; };
    size_t recuperer_nombre_de_sens_sortie() const { return __mots.size(); };
    void ajouter_type(Type type);
    void ajouter_champs_lexicaux(std::vector <ChampsLexicaux> champs_lexicaux);
    
    private :
    
    Type __type;

    std::vector <Mot> __mots;
};

#endif /* Famille_hpp */
