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
    int recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(int numero_du_mot) const { return __nombre_de_champs_lexicaux[numero_du_mot]; };
    int recuperer_nombre_de_mots() const { return _nombre_de_mots; };
    std::vector <std::vector <std::string>> recuperer_champs_lexicaux() const { return __tableau_champs_lexicaux; };
    std::string recuperer_mot(int numero_du_mot) const { return __tableau_mots[numero_du_mot]; };
    void ajouter_champs_lexicaux(std::string champ_lexicaux);
    void ajouter_mot(std::string mots);
    
    private :
        
    int _nombre_de_mots;
    
    std::vector <int> __nombre_de_champs_lexicaux;
    
    std::vector <std::string> __tableau_mots;
    
    std::vector <std::vector <std::string>> __tableau_champs_lexicaux;
};

#endif /* Mot_hpp */
