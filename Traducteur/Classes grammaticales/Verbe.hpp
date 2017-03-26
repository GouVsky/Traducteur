//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Mot.hpp"
#include "Terminaison.hpp"
#include "Auxiliaire.hpp"
#include "ChampsLexicaux.hpp"

class Verbe : public Mot
{
    public :
    
    Verbe(std::string source, std::string sortie);
    std::string recuperer_type() const { return "Verbe"; };
    int recuperer_taille_verbe_sortie() const { return _taille_verbe_sortie; };
    int recuperer_taille_verbe_source() const { return _taille_verbe_source; };
    std::string le_verbe_est_irregulier(std::string verbe, std::string langue);
    std::string construction(std::string langue, std::string verbe, int compteur);
    void determine_si_existe_un_verbe_dans_la_phrase(int compteur, std::vector <std::string> & phrases, std::vector <Mot> & mots);
    
    private :
    
    Auxiliaire _auxiliaire;
    
    Terminaison _terminaison;
    
    int _sujet,
        _groupe_verbe,
        _taille_verbe_source,
        _taille_verbe_sortie;
        
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
};

#endif /* verbe_hpp */
