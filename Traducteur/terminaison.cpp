//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "terminaison.hpp"

using namespace std;


Terminaison::Terminaison()
{
    
}




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

void Terminaison::troisieme_groupe(int sujet, string verbe, string temps)
{
    size_t max = 0;
    
    if (temps == "present" || temps == "present_be+ing")
    {
        groupe_3["present_ir_F"] = present_ir_F[sujet];
        groupe_3["present_ire_F"] = present_ire_F[sujet];
        groupe_3["present_dre_F"] = present_dre_F[sujet];
        groupe_3["present_tir_F"] = present_tir_F[sujet];
        groupe_3["present_oir_F"] = present_oir_F[sujet];
        groupe_3["present_oire_F"] = present_oire_F[sujet];
        groupe_3["present_evoir_F"] = present_evoir_F[sujet];
    }
    
    // Recherche des terminaisons.
    // Pour ajouter une sécurité, on précise que la chaîne de caractères recherchée est à la fin,
    // et qu'elle doit être la plus grande possible.
    
    for (int i = 0; i < NB_TERMINAISONS_GR_3; i++)
    {
        string terminaison = terminaisons_groupe_3[i];
        
        // On s'assure que la terminaison sélectionnée n'est pas plus grande que le verbe.
        
        if (terminaison.size() < verbe.size())
        {
            string fin_du_verbe = verbe.substr(verbe.size() - terminaison.size());
            
            // On s'assure que la terminaison trouvée est la plus grande possible.
            
            if (fin_du_verbe == terminaison && terminaison.size() > max)
            {
                nouvelle_terminaison = groupe_3[temps + "_" + terminaison + "_F"];
                
                ancienne_terminaison = terminaison;
                
                max = terminaison.size();
            }
        }
    }
}




// Les terminaisons des verbes du premier et deuxième groupe.

void Terminaison::premier_et_deuxieme_groupe(int groupe_verbe, int sujet, string temps)
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
        
        nouvelle_terminaison = terminaisons[temps + "_" + to_string(groupe_verbe) + "_F"];
    }
    
    else
    {
        terminaisons["passe_compose_F"] = "é";
        terminaisons["futur_F"] = futur_F[sujet];
        terminaisons["imparfait_F"] = imparfait_F[sujet];
        terminaisons["conditionnel_F"] = conditionnel_F[sujet];
        terminaisons["passe_simple_F"] = passe_simple_F[sujet];
        
        nouvelle_terminaison = terminaisons[temps + "_F"];
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
            premier_et_deuxieme_groupe(groupe_verbe, sujet, temps);
        }
        
        else
        {
            troisieme_groupe(sujet, verbe, temps);
        }
    }
    
    // L'anglais.
    
    else
    {
        terminaisons_anglaises(sujet, temps, verbe);
    }
    
    return make_tuple(ancienne_terminaison, nouvelle_terminaison);
}
