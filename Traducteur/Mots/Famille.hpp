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
    Type & recuperer_type() { return __type; };
    size_t recuperer_nombre_de_sens_sortie() const { return __sens_sortie.size(); };
    Mot & recuperer_sens_sortie(int numero_sens) { return __sens_sortie[numero_sens]; };
    void definir_le_type(std::string classe, std::string categorie, std::string propriete);
    void definir_les_champs_lexicaux_des_mots(std::vector <ChampsLexicaux> champs_lexicaux);
    void ajouter_sens_sortie(Mot mot);
    void ajouter_sens_sortie(std::vector <Mot> mots);
    
    private :
    
    std::vector <Mot> __sens_sortie;
    
    Type __type;
};

#endif /* Famille_hpp */
