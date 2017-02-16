//
//  nomCommun.hpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef nomCommun_hpp
#define nomCommun_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "ChampsLexicaux.hpp"

class NomCommun
{
    public :
    
    NomCommun(std::string source, std::string sortie);
    int recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(int numero_du_mot);
    int recuperer_nombre_de_significations();
    std::string recuperer_champ_lexical(int numero_du_mot, int numero_du_champ_lexical);
    std::string recuperer_nombre(int numero_du_mot);
    std::string recuperer_genre(int numero_du_mot);
    std::string recuperer_mot(int numero_du_mot);
    void le_mot_est_un_nom_commun(std::string mot, ChampsLexicaux * champs_lexicaux);
    
    private :
    
    int nombre_de_mots;
    
    std::vector <int> nombre_de_champs_lexicaux;
    
    std::map <int, std::string> genre;
    std::map <std::string, std::string> nom;
    
    std::string mot_source,
                mot_sortie,
                nombre,
                langue_source,
                langue_sortie,
                champ_lexical,
                les_champs_lexicaux,
                un_des_champs_lexicaux;
    
    std::vector <std::string> tableau_mots,
                              tableau_genre;
    
    std::vector <std::vector <std::string>> tableau_champs_lexicaux;
};

#endif /* nomCommun_hpp */
