//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"

using namespace std;


Verbe::Verbe() {}





string Verbe::recuperer_forme_verbe_irregulier(string langue, string temps, int sujet)
{
    transform(langue.begin(), langue.end(), langue.begin(), ::tolower);
    
    string fichier = "./Resources/Dictionnaire/Verbes/Irreguliers/" + langue;
    
    return 0;
}
