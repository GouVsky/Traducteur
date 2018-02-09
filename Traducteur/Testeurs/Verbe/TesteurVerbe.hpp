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
#include "ParseurFormeVerbe.hpp"


class TesteurVerbe
{
    public :
    
    TesteurVerbe();
    bool tester_verbe(std::string verbe, std::string langue_source, std::string langue_sortie, std::vector <Groupe> & groupes, DonneesMot & donnees);
    
    private :
    
    bool comparer(std::string verbe_dans_phrase, std::string verbe_construit, std::vector <Groupe> & groupes);
    
    
    Verbe __verbe;
    
    
    std::string _sauvegarde;
    
    size_t _indice_groupe_debut_verbe;
};

#endif /* TesteurVerbe_hpp */
