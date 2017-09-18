//
//  ParseurVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurVerbe_hpp
#define ParseurVerbe_hpp

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Sujet.hpp"
#include "Auxiliaire.hpp"
#include "Terminaison.hpp"

#include "Mot.hpp"
#include "Groupe.hpp"


class ParseurVerbe
{
    public :
    
    ParseurVerbe(std::string source, std::string sortie, std::string fichier_formes);
    //std::string recuperer_forme_irreguliere(std::string langue, std::string verbe);
    std::string construire_verbe(std::string langue, std::string verbe);
    bool parser(std::string mot, std::vector <Mot> & verbes, std::vector <Groupe> & groupes, std::vector <std::vector <Mot>> & verbes_sorties);
    
    private :
    
    Sujet __sujet;
    Auxiliaire __auxiliaire;
    Terminaison __terminaison;
    
    
    int _groupe = 1;
    
    std::string _temps_verbe,
                _langue_source,
                _langue_sortie,
                _forme_verbe_source,
                _forme_verbe_sortie,
                _fichier_formes;
    
    std::map <std::string, std::string> __conjugaison;
};

#endif /* ParseurVerbe_hpp */
