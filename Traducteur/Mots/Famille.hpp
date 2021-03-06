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
    
    Famille();
    Famille(std::string mot);
    Famille(std::vector <std::string> mots);
    Famille & operator=(Famille famille);
    Famille operator+(Famille famille);
    Famille & operator+=(Famille famille);
    Type & recuperer_type() { return __type; };
    Mot & recuperer_mot_dominant() { return __mot_dominant; };
    Mot & recuperer_mot(int mot) { return __mots[mot]; };
    std::vector <Mot> & recuperer_mots() { return __mots; };
    size_t recuperer_nombre_de_sens_sortie() const { return __mots.size(); };
    void ajouter_type(Type type);
    void ajouter_champs_lexicaux(std::vector <ChampsLexicaux> champs_lexicaux);
    void determiner_mot_dominant(ChampsLexicaux & champs_lexicaux);
    
    private :
    
    Type __type;

    Mot __mot_dominant;
    
    std::vector <Mot> __mots;
};

#endif /* Famille_hpp */
