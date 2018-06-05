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

#include "config.hpp"
#include "Groupe.hpp"
#include "TesteurMot.hpp"
#include "DonneesMot.hpp"
#include "TesteurVerbe.hpp"
#include "DonneesVerbe.hpp"


class Parseur
{
    public :
    
    Parseur(std::string fichier);
    DonneesVerbe & recuperer_donnees_verbe() { return __testeur_verbe.recuperer_donnees_verbe(); };
    DonneesMot & recuperer_donnees_mot() { return __donnees_mot; };
    bool parser(std::string mot_a_trouver, std::vector <Groupe> & groupes);
    
    private :
    
    void parser_champs_lexicaux(std::string champs_lexicaux);
    void parser_types(std::string types, int langue);
    void parser_mots(std::string mots, int langue);
    
    
    DonneesMot __donnees_mot;
    
    TesteurMot __testeur_mot;
    
    TesteurVerbe __testeur_verbe;
    
    
    std::string _types,
                _fichier,
                _champs_lexicaux;
    
    std::map <int, std::string> __mots_fichier;
};

#endif /* Parseur_hpp */
