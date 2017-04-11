//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"
#include "Sujet.hpp"
#include "ResourcePath.hpp"

using namespace std;


Verbe::Verbe()
{
    _taille_verbe_source = 0;
    _taille_verbe_sortie = 0;
}




void Verbe::definir_taille_verbe_sortie(int taille)
{
    _taille_verbe_sortie = taille;
}




void Verbe::definir_taille_verbe_source(int taille)
{
    _taille_verbe_source = taille;
}
