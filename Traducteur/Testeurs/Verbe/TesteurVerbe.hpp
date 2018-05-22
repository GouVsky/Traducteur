//
//  TesteurVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 02/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef TesteurVerbe_hpp
#define TesteurVerbe_hpp

#include <string>
#include <stdio.h>

#include "Sujet.hpp"
#include "Verbe.hpp"
#include "Groupe.hpp"
#include "DonneesMot.hpp"
#include "DonneesVerbe.hpp"
#include "ParseurFormeVerbe.hpp"


class TesteurVerbe
{
    public :
    
    TesteurVerbe(std::string langue_source, std::string langue_sortie);
    DonneesVerbe & recuperer_donnees_verbe() { return __donnees_verbe; };
    bool tester_verbe(std::string verbe, std::vector <Groupe> & groupes, DonneesMot & donnees);
    
    private :
    
    bool comparer(std::string verbe_dans_phrase, std::vector <std::string> verbes_construits, std::vector <Groupe> & groupes);
    std::vector <std::string> construction(DonneesMot & donnees, std::string langue, int temps, int famille, int mot);

    
    int _sujet;
    
    std::string _langue_source,
                _langue_sortie,
                _verbe_construit;
    
    Verbe * __verbe;
    
    DonneesVerbe __donnees_verbe;
    
    ParseurFormeVerbe __parseur_formes;
    
    DonneesFormeVerbe __donnees_formes_verbes;
};

#endif /* TesteurVerbe_hpp */
