//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Mot.hpp"
#include "ChampsLexicaux.hpp"

class Verbe : public Mot
{
    public :
    
    Verbe(std::string source, std::string sortie, ChampsLexicaux * champ_lexical);
    int recuperer_taille_verbe_sortie();
    int recuperer_taille_verbe_source();
    std::string le_verbe_est_irregulier(std::string verbe, std::string temps, std::string langue);
    std::string construction(std::string caracteristique, std::string langue, std::string temps_verbe, int sujet, int groupe_verbe, std::string verbe, std::string marque_vb_si_irregulier, std::vector <std::string> * tableau, int compteur);
    void determine_si_existe_un_verbe_dans_la_phrase(int compteur, std::vector <std::string> tableau, std::vector <std::vector <std::string>> structure_de_la_phrase);
    
    private :
    
    int _taille_verbe_source,
        _taille_verbe_sortie;
        
    std::string _mot,
                _temps_verbe,
                _champ_lexical,
                _langue_source,
                _langue_sortie,
                _forme_verbe_source,
                _forme_verbe_sortie;
    
    std::map <std::string, std::string> caracteristique,
                                        verbe,
                                        marque_vb_irr,
                                        verbe_irregulier;
    
    std::map <std::string, int> position_pronom;
    
    std::map <std::string, int> pronom = {{"me", 0},
                                          {"you", 1},
                                          {"te", 1},
                                          {"him", 2},
                                          {"il", 2},
                                          {"her", 3},
                                          {"elle", 3},
                                          {"it", 4},
                                          {"us", 5},
                                          {"nous", 5},
                                          {"vous", 7},
                                          {"them", 6},
                                          {"les", 6}};
    
    std::map <std::pair <std::string, int>, std::string> association = {{std::make_pair("A", 0), "me"},
                                                                        {std::make_pair("A", 1), "you"},
                                                                        {std::make_pair("A", 2), "him"},
                                                                        {std::make_pair("A", 3), "her"},
                                                                        {std::make_pair("A", 4), "it"},
                                                                        {std::make_pair("A", 5), "us"},
                                                                        {std::make_pair("A", 6), "them"},
                                                                        {std::make_pair("F", 0), "me"},
                                                                        {std::make_pair("F", 1), "te"},
                                                                        {std::make_pair("F", 2), "le"},
                                                                        {std::make_pair("F", 3), "la"},
                                                                        {std::make_pair("F", 5), "nous"},
                                                                        {std::make_pair("F", 7), "vous"},
                                                                        {std::make_pair("F", 6), "les"}};

};

#endif /* verbe_hpp */
