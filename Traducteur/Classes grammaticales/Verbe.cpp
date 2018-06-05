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
    __groupe[config::ANGLAIS] = propriete[0] - '0';
    
    __groupe[config::FRANCAIS] = propriete[1] - '0';
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




vector <string> Verbe::construire_verbe(int langue, string verbe, vector <string> & formes, string temps, int groupe, int sujet)
{
    // On retourne 2^(nombre d'options) formes distinctes.
    vector <string> verbes_construits;
    
    // Cette sauvegarde va nous permettre de créer le radical.
    string sauvegarde = verbe;
    
    Terminaison terminaison(langue);
    
    terminaison.parser_terminaisons(verbe, temps, groupe);
    
    
    string structure;
        
    // On récupère chaque partie qui compose la forme du verbe.
    
    for (int i = 0; i < formes.size(); i++)
    {
        bool option = false;
        
        string partie_forme = formes[i];
        
        
        // On vérifie si la partie n'est pas une option.
        
        size_t parenthese_ouvrante = partie_forme.find('(');
        size_t parenthese_fermante = partie_forme.find(')');
        
        if (parenthese_ouvrante != -1 && parenthese_fermante != - 1)
        {
            option = true;
            
            partie_forme = partie_forme.substr(parenthese_ouvrante + 1, parenthese_fermante - 1);
        }
        

        if (partie_forme == "verbe")
        {
            structure = verbe;
        }
        
        else if (partie_forme == "radical")
        {
            sauvegarde.erase(sauvegarde.size() - terminaison.recuperer_ancienne_terminaison().size());
            
            structure = sauvegarde;
        }
        
        else if (partie_forme == "terminaison")
        {
            structure = terminaison.recuperer_nouvelle_terminaison(sujet);
        }
        
        else
        {
            structure = partie_forme;
        }
        

        // Si la structure est une option, on l'ajoute à toutes les formes distinctes.
        // Pour une option, il y aura donc une forme avec, et une forme sans.

        if (option && verbes_construits.empty())
        {
            verbes_construits.push_back(structure);
            verbes_construits.push_back("");
        }
        
        else if (option)
        {
            // Cette variable permet d'éviter une boucle infinie.
            size_t taille = verbes_construits.size();
            
            for (int j = 0; j < taille; j++)
            {
                verbes_construits.push_back(verbes_construits[j] + structure);
            }
        }
        
        else if (verbes_construits.empty())
        {
            verbes_construits.push_back(structure);
        }
        
        else
        {
            for (int j = 0; j < verbes_construits.size(); j++)
            {
                // Les options peuvent entrainer :
                // - un espace au début,
                // - une succession de deux espaces
                // que l'on doit éviter.

                if (!((verbes_construits[j].empty() || verbes_construits[j][verbes_construits[j].size() - 1] == ' ') && structure == " "))
                {
                    verbes_construits[j] += structure;
                }
            }
        }
    }
    
    return verbes_construits;
}
