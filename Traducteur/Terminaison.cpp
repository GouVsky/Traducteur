//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Terminaison.hpp"

using namespace std;


Terminaison::Terminaison() {}




// Retourne la nouvelle terminaison du verbe.

string Terminaison::recuperer_ancienne_terminaison()
{
    return ancienne_terminaison;
}




// Retourne l'ancienne terminaison du verbe.

string Terminaison::recuperer_nouvelle_terminaison()
{
    return nouvelle_terminaison;
}




// Les terminaisons anglaises.

void Terminaison::nouvelle_terminaison_anglaise(int sujet, string temps, string verbe)
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

void Terminaison::nouvelle_terminaison_troisieme_groupe(string verbe, string temps_verbe, int sujet)
{
    if (temps_verbe == "present" || temps_verbe == "present_be+ing")
    {
        groupe_3["present_ir_F"] = present_ir_F[sujet];
        groupe_3["present_ire_F"] = present_ire_F[sujet];
        groupe_3["present_dre_F"] = present_dre_F[sujet];
        groupe_3["present_tir_F"] = present_tir_F[sujet];
        groupe_3["present_oir_F"] = present_oir_F[sujet];
        groupe_3["present_oire_F"] = present_oire_F[sujet];
        groupe_3["present_evoir_F"] = present_evoir_F[sujet];
    }
    
    nouvelle_terminaison = groupe_3[temps_verbe + "_" + ancienne_terminaison + "_F"];
}





// Les terminaisons des verbes du premier et deuxième groupe.

void Terminaison::nouvelle_terminaison_premier_ou_deuxieme_groupe(int groupe_verbe, int sujet, string temps)
{
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




// Détermine la terminaison après conjugaison du verbe.

void Terminaison::determiner_nouvelle_terminaison(string langue, string verbe, string temps_verbe, int sujet, int groupe_verbe)
{    
    if (langue == "F")
    {
        switch (groupe_verbe)
        {
            case 1 : nouvelle_terminaison_premier_ou_deuxieme_groupe(groupe_verbe, sujet, temps_verbe);
                break;
                
            case 2 : nouvelle_terminaison_premier_ou_deuxieme_groupe(groupe_verbe, sujet, temps_verbe);
                break;
                
            case 3 : nouvelle_terminaison_troisieme_groupe(verbe, temps_verbe, sujet);
                break;
                
            default:
                break;
        }
    }
    
    else
    {
        nouvelle_terminaison_anglaise(sujet, temps_verbe, verbe);
    }
}




// Les terminaisons des verbes du troisième groupe.

void Terminaison::ancienne_terminaison_troisieme_groupe(string verbe)
{
    size_t max = 0;
    
    for (int i = 0; i < NB_TERMINAISONS_GR_3; i++)
    {
        string terminaison = terminaisons_groupe_3[i];
        
        // On s'assure que la terminaison sélectionnée n'est pas plus grande que le verbe.
        
        if (terminaison.size() < verbe.size())
        {
            // Pour ajouter une sécurité, on précise que la chaîne de caractères recherchée est à la fin,
            
            string fin_du_verbe = verbe.substr(verbe.size() - terminaison.size());
            
            // On s'assure que la terminaison trouvée est la plus grande possible.
            
            if (fin_du_verbe == terminaison && terminaison.size() > max)
            {                
                ancienne_terminaison = terminaison;
                
                max = terminaison.size();
            }
        }
    }
}




// Détermine la terminaison du groupe du verbe.

void Terminaison::determiner_ancienne_terminaison(string langue, string verbe, int groupe_verbe)
{
    if (langue == "F")
    {
        switch (groupe_verbe)
        {
            case 1 : ancienne_terminaison = "er";
                break;
                
            case 2 : ancienne_terminaison = "ir";
                break;
                
            case 3 : ancienne_terminaison_troisieme_groupe(verbe);
                
            default:
                break;
        }
    }
    
    else
    {
        ancienne_terminaison = "";
    }
}
