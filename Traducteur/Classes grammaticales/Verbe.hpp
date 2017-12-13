//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "Mot.hpp"
#include "Sujet.hpp"
#include "Groupe.hpp"
#include "DonneesFormeVerbe.hpp"

class Verbe
{
    public :
    
    std::string recuperer_forme_verbe_irregulier(std::string langue, std::string temps, int sujet);
    std::string construire_verbe(std::string mot, std::vector <Mot> & verbes, std::vector <Groupe> & groupes, std::vector <std::vector <Mot>> & verbes_sorties, DonneesFormeVerbe & donnees);
    
    private :
    
    Sujet __sujet;
};

#endif /* verbe_hpp */
