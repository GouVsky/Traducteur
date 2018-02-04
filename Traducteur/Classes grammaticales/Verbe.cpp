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




size_t Verbe::calculer_taille(string verbe)
{
    return count(verbe.begin(), verbe.end(), ' ');
}




bool Verbe::comparer_taille(string verbe_compare, string verbe_comparant)
{
    return calculer_taille(verbe_compare) < calculer_taille(verbe_comparant);
}




string Verbe::construire_verbe(string langue, string verbe, vector <string> & formes, string temps, int sujet)
{
    string verbe_construit,
           sauvegarde = verbe;
    
    
    // On récupère chaque partie qui compose la forme du verbe.
    
    for (int i = 0; i < formes.size(); i++)
    {
        string partie_forme = formes[i];
        
        
        if (partie_forme == "verbe")
        {
            verbe_construit += verbe;
        }
        
        /*else if (partie_forme == "radical")
        {
            __terminaison.determiner_ancienne_terminaison(langue, verbe, __groupe[langue]);
         
            sauvegarde.erase(sauvegarde.size() - __terminaison.recuperer_ancienne_terminaison().size());
         
            verbe_construit += sauvegarde;
        }*/
         
         /*else if (partie_forme == "terminaison")
         {
         __terminaison.determiner_nouvelle_terminaison(langue, temps, __sujet.recuperer_valeur(), __groupe[langue]);
         
         _verbe_construit += __terminaison.recuperer_nouvelle_terminaison();
         }*/
        
        else
        {
            verbe_construit += partie_forme;
        }
    }
    
    return verbe_construit;
}
