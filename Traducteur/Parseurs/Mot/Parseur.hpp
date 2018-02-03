//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Parseur_hpp
#define Parseur_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Groupe.hpp"
#include "TesteurMot.hpp"
#include "DonneesMot.hpp"
#include "TesteurVerbe.hpp"


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie, std::string fichier);
    DonneesMot & recuperer_donnees() { return __donnees; };
    bool parser(std::string mot_a_trouver, std::vector <Groupe> & groupes);
    
    private :
    
    void parser_champs_lexicaux(std::string champs_lexicaux);
    void parser_types(std::string types, std::string langue);
    void parser_mots(std::string mots, std::string langue);
    
    
    DonneesMot __donnees;

    TesteurMot __testeur_mot;
    
    TesteurVerbe __testeur_verbe;
    
    
    std::string _types,
                _fichier,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::map <std::string, std::string> __mots_fichier;
};

#endif /* Parseur_hpp */
