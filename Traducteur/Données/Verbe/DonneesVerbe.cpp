//
//  DonneesVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 22/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "DonneesVerbe.hpp"

using namespace std;


DonneesVerbe::DonneesVerbe()
{
    _indice_groupe_debut_verbe = 0;
}




void DonneesVerbe::ajouter_groupe(int langue, int groupe)
{
    __groupe[langue] = groupe;
}




void DonneesVerbe::ajouter_verbe_traduit(string verbe_traduit)
{
    _verbe_traduit = verbe_traduit;
}




void DonneesVerbe::ajouter_verbe_source(string verbe_source)
{
    _verbe_source = verbe_source;
}




void DonneesVerbe::ajouter_indice_groupe_debut_verbe(size_t indice_groupe_verbe_debut)
{
    _indice_groupe_debut_verbe = indice_groupe_verbe_debut;
}




void DonneesVerbe::reinitialisation()
{
    __groupe.clear();
}
