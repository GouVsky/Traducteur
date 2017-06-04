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

#include "Groupe.hpp"
#include "Parseur.hpp"


class ParseurVerbe : public Parseur
{
    public :
    
    ParseurVerbe(std::string source, std::string sortie);
    std::string recuperer_forme_irreguliere(std::string langue, std::string verbe);
    std::string construire_verbe(std::string langue, std::string verbe);
    bool chercher_verbe(std::string mot, std::vector <Groupe> & groupes);
    
    private :
    
    Sujet __sujet;
    Auxiliaire __auxiliaire;
    Terminaison __terminaison;
  
    int _groupe;

    bool _verbe_trouve;
    
    std::string _type,
                _temps_verbe,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux,
                _forme_verbe_source;
    
    std::map <std::string, std::string> __verbe,
                                        __irregulier,
                                        __conjugaison,
                                        __irregularite;
        
    
    std::string __fichier_verbes = "./Resources/Dictionnaire/Verbes/verbes.txt";
    
    std::string _fichier_forme_verbe = "./Resources/Dictionnaire/Verbes/forme_verbe.txt";
    
    std::string _fichier_verbes_irreguliers = "./Resources/Dictionnaire/Verbes/verbes_irreguliers_";
};

#endif /* ParseurVerbe_hpp */
