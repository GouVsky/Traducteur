//
//  ParseurVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurVerbe_hpp
#define ParseurVerbe_hpp

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Terminaison.hpp"
#include "Auxiliaire.hpp"
#include "ChampsLexicaux.hpp"

#include "Sujet.hpp"


class ParseurVerbe
{
    public :
    
    ParseurVerbe(std::string source, std::string sortie);
    std::vector <std::string> recuperer_champs_lexicaux() const { return __champs_lexicaux; };
    std::vector <std::string> recuperer_verbes_sortie() const { return __verbe_sortie; };
    bool le_verbe_est_present() const { return _verbe_trouve; };
    std::string recuperer_forme_irreguliere(std::string verbe, std::string langue);
    std::string construction_verbe(std::string langue, std::string verbe, int compteur);
    void parser_fichier(int compteur, std::vector <std::string> & phrases);
    
    private :
    
    Auxiliaire _auxiliaire;
    
    Terminaison _terminaison;
    
    int _sujet,
        _groupe;
    
    bool _verbe_trouve;
    
    std::string _temps_verbe,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux,
                _forme_verbe_source,
                _forme_verbe_sortie;
    
    std::map <int, std::string> __type_verbe;
    
    std::map <std::string, std::string> __verbe,
                                        __irregulier,
                                        __conjugaison,
                                        __irregularite;
    
    std::vector <std::string> __verbe_sortie,
                              __champs_lexicaux;
};

#endif /* ParseurVerbe_hpp */
