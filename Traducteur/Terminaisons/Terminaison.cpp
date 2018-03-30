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


Terminaison::Terminaison() {}




void Terminaison::determiner_nouvelle_terminaison(string langue, string temps, int sujet, int groupe)
{
    char fichier_groupe;
    
    string fichier_temps,
           fichier_terminaison,
           fichier_liste_terminaisons;
    
    ifstream fichier(_fichier  + langue + ".txt");
    

    while (!fichier.eof())
    {
        vector <string> fichier_liste_terminaisons_tableau;

        
        fichier >> fichier_temps >> fichier_groupe >> fichier_terminaison >> fichier_liste_terminaisons;
        

        // On récupère la liste des terminaisons correspondant au temps et au groupe du verbe.
        // Les différentes conditions ternaires sont utilisées pour gérer le cas où il n'y a pas de terminaison.

        if (fichier_temps == temps
            && ((fichier_groupe - '0') == groupe)
            && (fichier_terminaison == "-" ? "" : fichier_terminaison) == _ancienne_terminaison)
        {
            string terminaison;
            
            istringstream lecture(fichier_liste_terminaisons);
            
            while (getline(lecture, terminaison, '/'))
            {
                fichier_liste_terminaisons_tableau.push_back((terminaison == "-" ? "" : terminaison));
            }
            
            // On récupère la terminaison associée au sujet.
            
            _nouvelle_terminaison = fichier_liste_terminaisons_tableau[sujet];
        }
    }
}




void Terminaison::ancienne_terminaison_troisieme_groupe(string verbe)
{
    size_t max = 0;
    
    vector <string> terminaisons = {"ir", "tir", "ire", "dre", "oir", "oire", "evoir"};

    
    for (int i = 0; i < terminaisons.size(); i++)
    {
        string terminaison = terminaisons[i];
        
        
        // On s'assure que la terminaison sélectionnée n'est pas plus grande que le verbe.
        
        if (terminaison.size() < verbe.size())
        {
            // Pour ajouter une sécurité, on précise que la chaîne de caractères recherchée est à la fin,
            
            string fin_du_verbe = verbe.substr(verbe.size() - terminaison.size());
            
            
            // On s'assure que la terminaison trouvée est la plus grande possible.
            
            if (fin_du_verbe == terminaison && terminaison.size() > max)
            {                
                _ancienne_terminaison = terminaison;
                
                max = terminaison.size();
            }
        }
    }
}




void Terminaison::determiner_ancienne_terminaison(string langue, string verbe, int groupe_verbe)
{
    if (langue == "F")
    {
        switch (groupe_verbe)
        {
            case 1 : _ancienne_terminaison = "er";
                break;
                
            case 2 : _ancienne_terminaison = "ir";
                break;
                
            case 3 : ancienne_terminaison_troisieme_groupe(verbe);
                
            default:
                break;
        }
    }
    
    else if (langue == "A")
    {
        _ancienne_terminaison = "";
    }
}
