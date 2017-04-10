//
//  Mot.hpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Mot_hpp
#define Mot_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

#include "ChampsLexicaux.hpp"


class Mot
{
    public :
    
    Mot();
    Mot(std::string mot);
    void operator=(std::string mot);
    virtual std::string recuperer_type() const { return "Mot"; };
    int recuperer_nombre_de_champs_lexicaux(int numero_du_sens) const;
    std::string recuperer_champs_lexicaux(int numero_du_sens, int numero_champ_lexical) const;
    int recuperer_nombre_de_sens_sortie() const { return _nombre_de_sens_sortie; };
    int recuperer_nombre_de_sens_source() const { return _nombre_de_sens_source; };
    std::string recuperer_sens_sortie(int numero_sens) const { return __sens_sortie[numero_sens]; };
    std::string recuperer_sens_source(int numero_sens) const { return __sens_source[numero_sens]; };
    void definir_les_differents_champs_lexicaux(std::string ensemble_champ_lexicaux);
    void definir_les_differents_sens_sortie(std::string ensemble_mots);
    void definir_les_differents_sens_source(std::string ensemble_mots);
    
    private :
    
    int _nombre_de_sens_source,
    _nombre_de_sens_sortie;
    
    std::vector <int> __nombre_de_champs_lexicaux;
    
    std::vector <std::string> __sens_source,
    __sens_sortie;
    
    std::vector <std::vector <std::string>> __champs_lexicaux;
};

#endif /* Mot_hpp */
