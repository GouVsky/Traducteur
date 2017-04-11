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

class Verbe
{
    public :
    
    Verbe();
    int recuperer_taille_verbe_sortie() const { return _taille_verbe_sortie; };
    int recuperer_taille_verbe_source() const { return _taille_verbe_source; };
    void definir_taille_verbe_sortie(int taille);
    void definir_taille_verbe_source(int taille);
    
    private :
    
    int _taille_verbe_source,
        _taille_verbe_sortie;
};

#endif /* verbe_hpp */
