//
//  sujet.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Sujet.hpp"

using namespace std;


Sujet::Sujet(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _valeur = NEUTRE;
}




void Sujet::transformer_le_sujet(int masculin, int feminin)
{
    // Un nom féminin.
    
    if (masculin == 0 && feminin == 1)
    {
        _valeur = ELLE;
    }
    
    // Plusieurs noms féminins.
    
    else if (masculin == 0 && feminin > 1)
    {
        _valeur = ELLES;
    }
    
    // Un nom masculin.
    
    else if (masculin == 1 && feminin == 0)
    {
        _valeur = IL;
    }
    
    // Plusieurs noms masculins.
    
    else if ((masculin == 1 && feminin >= 1) || masculin > 1)
    {
        _valeur = ILS;
    }
}



// Création du sujet.

void Sujet::rechercher_le_sujet(vector <Groupe> & groupes)
{
    int feminin = 0,
        masculin = 0;

    
    for (int i = 0; i < groupes.size(); i++)
    {
        size_t nombre_familles = groupes[i].recuperer_nombre_de_familles();
        
        for (int j = 0; j < nombre_familles; j++)
        {
            string type = groupes[i].recuperer_famille(j).recuperer_type().type();
            

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
    
    transformer_le_sujet(masculin, feminin);
}
