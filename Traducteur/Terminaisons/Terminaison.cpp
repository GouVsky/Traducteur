//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Terminaison.hpp"

using namespace std;


Terminaison::Terminaison(string langue)
{
    _langue = langue;
}




void Terminaison::parser_terminaisons(string verbe, string temps, int groupe)
{
    int fichier_groupe;
    
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
        
        // On précise que la chaîne de caractères recherchée est à la fin.
        // On vérifie d'abord qu'elle n'est pas plus grande que le verbe.
        
        int taille_terminaison = (int) (verbe.size() - _ancienne_terminaison.size());
        
        if (taille_terminaison > 0)
        {
            string fin_du_verbe = verbe.substr(taille_terminaison);

            if (fichier_temps == temps && fichier_groupe == groupe && fin_du_verbe.size() >= _ancienne_terminaison.size())
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
}
