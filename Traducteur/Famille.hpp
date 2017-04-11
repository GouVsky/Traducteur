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
#include "Verbe.hpp"
#include "Adjectif.h"
#include "Invariable.h"
#include "NomPropre.hpp"
#include "NomCommun.hpp"
#include "PronomPersonnel.hpp"


typedef struct __Type
{
    Verbe verbe;
    Adjectif adjectif;
    NomPropre nom_propre;
    NomCommun nom_commun;
    Invariable invariable;
    PronomPersonnel pronom_personnel;
    
} __type;



class Famille
{
    public :
    
    Famille();
    int recuperer_nombre_de_sens_sortie() const { return __sens_sortie.size(); };
    Mot & recuperer_sens_sortie(int numero_sens) { return __sens_sortie[numero_sens]; };
    __Type recuperer_le_type() { return __type; };
    void definir_le_type(int type);
    void definir_les_champs_lexicaux_des_mots(std::vector <std::string> champs_lexicaux);
    void definir_les_differents_sens_sortie(std::vector <std::string> mots);
    
    private :
    
    int _type;
    
    __Type __type;
    
    std::vector <Mot> __sens_sortie;
};

#endif /* Famille_hpp */
