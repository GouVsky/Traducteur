//
//  Testeur.cpp
//  Traducteur
//
//  Created by Grégoire on 23/01/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "TesteurMot.hpp"

using namespace std;


TesteurMot::TesteurMot() {}




bool TesteurMot::tester_mot(string mot, int langue, DonneesMot & donnees)
{
    bool trouve = false;
    
    size_t nombre_familles = donnees.recuperer_nombre_familles(langue);
    
    
    // On teste chaque famille.
    
    for (int famille = 0; famille < nombre_familles && !trouve; famille++)
    {
        if (donnees.recuperer_type(famille).classe() != "VERBE")
        {
            size_t nombre_sens = donnees.recuperer_nombre_sens(langue, famille);
            
            
            // On teste chaque signification.
            
            for (int sens = 0; sens < nombre_sens && !trouve; sens++)
            {
                string mot_dans_donnees = donnees.recuperer_famille(langue, famille).recuperer_mot(sens).recuperer_mot();
                
                if (mot_dans_donnees == mot)
                {
                    trouve = true;
                }
            }
        }
    }
    
    return trouve;
}
