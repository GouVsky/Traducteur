//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "terminaison.hpp"

using namespace std;


// Les terminaisons anglaises.

void Terminaison::terminaisons_anglaises(int sujet, string temps, string verbe)
{
    if (temps == "present" || temps == "present_be+ing")
    {
        nouvelle_terminaison = A[sujet];
    }
    
    else if (temps == "passe_compose" || temps == "imparfait" || temps == "passe_simple")
    {
        if (verbe[verbe.size() - 1] == 'e')
        {
            nouvelle_terminaison = 'd';
        }
        
        else
        {
            nouvelle_terminaison = "ed";
        }
    }
}




// Les terminaisons des verbes du troisième groupe.

void Terminaison::troisieme_groupe(int sujet, string verbe, string temps, string langue)
{
    // Recherche des terminaisons.
    // Pour ajouter une sécurité, on précise que la chaîne de caractères recherchées est à la fin.
    
    if (temps == "present" || temps == "present_be+ing")
    {
        if (verbe.find("evoir", verbe.size() - 5) != -1)
        {
            nouvelle_terminaison = present_evoir_F[sujet];
            
            ancienne_terminaison = "evoir";
        }
        
        else if (verbe.find("oire", verbe.size() - 4) != -1)
        {
            nouvelle_terminaison = present_oire_F[sujet];
            
            ancienne_terminaison = "oire";
        }
        
        else if (verbe.find("tir", verbe.size() - 3) != -1)
        {
            nouvelle_terminaison = present_tir_F[sujet];
            
            ancienne_terminaison = "tir";
        }
        
        else if (verbe.find("ire", verbe.size() - 3) != -1)
        {
            nouvelle_terminaison = present_ire_F[sujet];
            
            ancienne_terminaison = "ire";
        }
        
        else if (verbe.find("dre", verbe.size() - 3) != -1)
        {
            nouvelle_terminaison = present_dre_F[sujet];
            
            ancienne_terminaison = "dre";
        }
    }
}




// Les terminaisons des verbes du premier et deuxième groupe.

void Terminaison::premier_et_deuxieme_groupe(int groupe_verbe, int sujet, string verbe, string temps, string langue)
{
    switch (groupe_verbe)
    {
        case 1 : ancienne_terminaison = "er";
            break;
            
        case 2 : ancienne_terminaison = "ir";
            break;
            
        default:
            break;
    }
    
    if (temps == "present" || temps == "present_be+ing")
    {
        terminaisons["present_1_F"] = present_1_F[sujet];
        terminaisons["present_2_F"] = present_2_F[sujet];
        
        nouvelle_terminaison = terminaisons[temps + "_" + to_string(groupe_verbe) + "_" + langue];
    }
    
    else
    {
        terminaisons["passe_compose_F"] = "é";
        terminaisons["futur_F"] = futur_F[sujet];
        terminaisons["imparfait_F"] = imparfait_F[sujet];
        terminaisons["conditionnel_F"] = conditionnel_F[sujet];
        terminaisons["passe_simple_F"] = passe_simple_F[sujet];
        
        nouvelle_terminaison = terminaisons[temps + "_" + langue];
    }
}




// Construction de la terminaison selon la langue, le groupe et le temps du verbe.

tuple <string, string> Terminaison::construction(int groupe_verbe, string temps, int sujet, string langue, string verbe)
{
    nouvelle_terminaison = "";
    ancienne_terminaison = "";
    
    // Le français.
    
    if (langue == "F")
    {
        if (groupe_verbe == 1 || groupe_verbe == 2)
        {
            premier_et_deuxieme_groupe(groupe_verbe, sujet, verbe, temps, langue);
        }
        
        else
        {
            troisieme_groupe(sujet, verbe, temps, langue);
        }
    }
    
    // L'anglais.
    
    else
    {
        terminaisons_anglaises(sujet, temps, verbe);
    }
    
    return make_tuple(ancienne_terminaison, nouvelle_terminaison);
}
