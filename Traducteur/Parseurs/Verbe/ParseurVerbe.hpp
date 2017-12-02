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

#include "Etre.hpp"
#include "Avoir.hpp"
#include "Sujet.hpp"
#include "Terminaison.hpp"

#include "Mot.hpp"
#include "Groupe.hpp"

#include "Type.hpp"

#include "ParseurFormeVerbe.hpp"


class ParseurVerbe
{
    public :
    
    ParseurVerbe(std::string source, std::string sortie, Type type);
    std::string construire_verbe(std::string langue, std::string verbe, std::vector <std::string> & formes, std::string temps);
    bool parser(std::string mot, std::vector <Mot> & verbes, std::vector <Groupe> & groupes, std::vector <std::vector <Mot>> & verbes_sorties);
    
    private :
    
    Etre __etre;
    Avoir __avoir;
    Sujet __sujet;
    Terminaison __terminaison;
    
    ParseurFormeVerbe __parseur_forme;
    
    
    std::string _langue_source,
                _langue_sortie,
                _forme_verbe_source,
                _forme_verbe_sortie;
    
    std::map <std::string, int> __groupe;
    
    std::map <std::string, std::string> __temps,
                                        __forme;
};

#endif /* ParseurVerbe_hpp */
