//
//  DonneesFormeVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 06/12/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "DonneesFormeVerbe.hpp"

using namespace std;


DonneesFormeVerbe::DonneesFormeVerbe() {}




void DonneesFormeVerbe::ajouter_temps(string temps, int langue)
{
    __temps[langue].push_back(temps);
}




void DonneesFormeVerbe::ajouter_forme(vector <string> forme, int langue)
{
    __formes_decoupees[langue].push_back(forme);
}
