//
//  sujet.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Sujet.hpp"

using namespace std;


int Sujet::transformer_le_sujet(int masculin, int feminin)
{
    int valeur = NEUTRE;
    
    
    // Un nom féminin.
    
    if (masculin == 0 && feminin == 1)
    {
        valeur = ELLE;
    }
    
    // Plusieurs noms féminins.
    
    else if (masculin == 0 && feminin > 1)
    {
        valeur = ELLES;
    }
    
    // Un nom masculin.
    
    else if (masculin == 1 && feminin == 0)
    {
        valeur = IL;
    }
    
    // Plusieurs noms masculins.
    
    else if ((masculin == 1 && feminin >= 1) || masculin > 1)
    {
        valeur = ILS;
    }
    
    return valeur;
}



// Création du sujet.

int  Sujet::recuperer_valeur_sujet(vector <Groupe> & groupes)
{
    int feminin = 0,
        masculin = 0;

    
    for (int i = 0; i < groupes.size(); i++)
    {
        size_t nombre_familles = groupes[i].recuperer_nombre_de_familles();
        
        
        for (int j = 0; j < nombre_familles; j++)
        {
            string type = groupes[i].recuperer_famille(j).recuperer_type().recuperer_type();
            

            if (type == "NOM_COMMUN_MASCULIN")
            {
                masculin++;
            }
            
            else if (type == "NOM_COMMUN_FEMININ")
            {
                feminin++;
            }
        }
    }
    
    return transformer_le_sujet(masculin, feminin);
}
