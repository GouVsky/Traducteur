//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Auxiliaire.hpp"
#include "Terminaison.hpp"

using namespace std;


Terminaison::Terminaison(string langue)
{
    _langue = langue;
}




void Terminaison::parser_terminaisons(string verbe, string temps, int groupe)
{
    char fichier_groupe;
    
    string fichier_temps,
           fichier_terminaison,
           fichier_liste_terminaisons;
    
    ifstream fichier(_fichier  + _langue + ".txt");
    

    while (!fichier.eof())
    {
        vector <string> fichier_liste_terminaisons_tableau;

        
        fichier >> fichier_temps >> fichier_groupe >> fichier_terminaison >> fichier_liste_terminaisons;
        
        
        _ancienne_terminaison = fichier_terminaison == "-" ? "" : fichier_terminaison;

        // On récupère la liste des terminaisons correspondant au temps et au groupe du verbe.
        // Un même groupe peut posséder différentes terminaisons, il faut donc récupérer la plus grande possible.
        
        // On précise que la chaîne de caractères recherchée est à la fin,
        
        string fin_du_verbe = verbe.substr(verbe.size() - _ancienne_terminaison.size());
        
        if (fichier_temps == temps && (fichier_groupe - '0') == groupe && fin_du_verbe.size() >= _ancienne_terminaison.size())
        {
            string terminaison;
            
            istringstream lecture(fichier_liste_terminaisons);
            
            while (getline(lecture, terminaison, '/'))
            {
                __nouvelles_terminaisons.push_back((terminaison == "-" ? "" : terminaison));
            }
        }
    }
}
