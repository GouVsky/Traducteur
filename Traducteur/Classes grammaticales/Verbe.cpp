//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"

using namespace std;


Verbe::Verbe()
{
    _taille = 0;
    
    _verbe_construit = "";
    
    _indice_groupe_debut_verbe = 0;
}




void Verbe::calculer_taille()
{
    _taille = count(_verbe_construit.begin(), _verbe_construit.end(), ' ');
}




Verbe & Verbe::operator=(Verbe verbe)
{
    _taille = verbe._taille;
    
    _verbe_construit = verbe._verbe_construit;
    
    return * this;
}




void Verbe::definir_indice_groupe_debut_verbe(size_t indice)
{
    _indice_groupe_debut_verbe = indice;
}




void Verbe::construire_verbe(string langue, string verbe, vector <string> & formes, string temps, int sujet)
{
    _temps = temps;

    string sauvegarde = verbe;
    
    
    // On récupère chaque partie qui compose la forme du verbe.
    
    for (int i = 0; i < formes.size(); i++)
    {
        string partie_forme = formes[i];
        
        
        if (partie_forme == "verbe")
        {
            _verbe_construit += verbe;
        }
        
        /*else if (partie_forme == "radical")
         {
         __terminaison.determiner_ancienne_terminaison(langue, verbe, __groupe[langue]);
         
         sauvegarde.erase(sauvegarde.size() - __terminaison.recuperer_ancienne_terminaison().size());
         
         _verbe_construit += sauvegarde;
         }
         
         else if (partie_forme == "terminaison")
         {
         __terminaison.determiner_nouvelle_terminaison(langue, temps, __sujet.recuperer_valeur(), __groupe[langue]);
         
         _verbe_construit += __terminaison.recuperer_nouvelle_terminaison();
         }*/
        
        else
        {
            _verbe_construit += partie_forme;
        }
    }
    
    calculer_taille();
}
