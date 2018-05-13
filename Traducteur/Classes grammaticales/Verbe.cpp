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




Verbe::Verbe(string propriete)
{
    __groupe["A"] = propriete[0] - '0';
    
    __groupe["F"] = propriete[1] - '0';
}




size_t Verbe::calculer_taille(string verbe)
{
    if (verbe.empty())
    {
        return 0;
    }
    
    else
    {
        return count(verbe.begin(), verbe.end(), ' ') + 1;
    }
}




bool Verbe::comparer_taille(string verbe_compare, string verbe_comparant)
{
    return calculer_taille(verbe_compare) < calculer_taille(verbe_comparant);
}




string Verbe::construire_verbe(string langue, string verbe, vector <string> & formes, string temps, int groupe, int sujet)
{
    string verbe_construit;
    
    // Cette sauvegarde va nous permettre de créer le radical.
    
    string sauvegarde = verbe;
    
    Terminaison terminaison(langue);
    
    terminaison.parser_terminaisons(verbe, temps, groupe);
    
    
    // On récupère chaque partie qui compose la forme du verbe.
    
    for (int i = 0; i < formes.size(); i++)
    {
        string partie_forme = formes[i];
        
        
        if (partie_forme == "verbe")
        {
            verbe_construit += verbe;
        }
        
        else if (partie_forme == "radical")
        {
            sauvegarde.erase(sauvegarde.size() - terminaison.recuperer_ancienne_terminaison().size());
         
            verbe_construit += sauvegarde;
        }
         
        else if (partie_forme == "terminaison")
        {
            verbe_construit += terminaison.recuperer_nouvelle_terminaison(sujet);
        }
        
        else
        {
            verbe_construit += partie_forme;
        }
    }
    
    return verbe_construit;
}
