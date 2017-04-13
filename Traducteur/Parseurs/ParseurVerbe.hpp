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

#include "Sujet.hpp"
#include "Auxiliaire.hpp"
#include "Terminaison.hpp"

#include "ChampsLexicaux.hpp"

#include "Groupe.hpp"



class ParseurVerbe
{
    public :
    
    ParseurVerbe(std::string source, std::string sortie);
    std::vector <std::string> recuperer_champs_lexicaux() const { return __champs_lexicaux; };
    std::vector <std::string> recuperer_verbes_sortie() const { return __verbes_sortie; };
    bool le_verbe_est_present() const { return _verbe_trouve; };
    std::string recuperer_forme_irreguliere(std::string langue, std::string verbe);
    std::string construire_verbe(std::string langue, std::string verbe);
    void parser_fichier(std::string mot, std::vector <Groupe> & groupes);
    
    private :
    
    Sujet __sujet;
    Auxiliaire __auxiliaire;
    Terminaison __terminaison;
    
    bool _verbe_trouve;
    
    int _groupe;
    
    std::string _temps_verbe,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux,
                _forme_verbe_source;
    
    std::vector <std::string> __verbes_sortie,
                              __champs_lexicaux;
    
    std::map <int, std::string> __type_verbe;
    
    std::map <std::string, std::string> __verbe,
                                        __irregulier,
                                        __conjugaison,
                                        __irregularite;
};

#endif /* ParseurVerbe_hpp */
