//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Auxiliaire.hpp"
#include "Terminaison.hpp"

using namespace std;


Terminaison::Terminaison()
{
    __A = {"", "", "s", "s", "s", "", "", "", ""};
    
    __present_1_F = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    __futur_simple_F = {"ai", "as", "a", "a", "a", "ons", "ez", "ont", "ont"};
    __passe_simple_F = {"ais", "ais", "a", "a", "a", "ions", "iez", "èrent", "èrent"};
    __imparfait_F = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    __present_2_F = {"is", "is", "it", "it", "it", "issons", "issez", "issent", "issent"};
    __conditionnel_F = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    
    __terminaisons_groupe_3 = {"ir", "tir", "ire", "dre", "oir", "oire", "evoir"};
    
    __present_ir_F = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    __present_tir_F = {"s", "s", "t", "t", "t", "tons", "tez", "tent", "tent"};
    __present_ire_F = {"s", "s", "t", "t", "t", "ions", "iez", "ient", "ient"};
    __present_dre_F = {"ds", "ds", "d", "d", "d", "dons", "dez", "dent", "dent"};
    __present_oir_F = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    __present_oire_F = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    __present_evoir_F = {"ois", "ois", "oit", "oit", "oit", "evons", "evez", "oivent", "oivent"};
}




// Les terminaisons anglaises.

void Terminaison::nouvelle_terminaison_anglaise(int sujet, string temps, string verbe)
{
    if (temps == "present" || temps == "present_be+ing")
    {
        _nouvelle_terminaison = __A[sujet];
    }
    
    else if (temps == "passe_compose" || temps == "imparfait" || temps == "passe_simple")
    {
        _nouvelle_terminaison = (verbe[verbe.size() - 1] == 'e') ? "d" : "ed";
    }
}




// Les terminaisons des verbes du troisième groupe.

void Terminaison::nouvelle_terminaison_francaise_troisieme_groupe(string verbe, string temps_verbe, int sujet)
{
    if (temps_verbe == "present" || temps_verbe == "present_be+ing")
    {
        __groupe_3["present_ir_F"] = __present_ir_F[sujet];
        __groupe_3["present_ire_F"] = __present_ire_F[sujet];
        __groupe_3["present_dre_F"] = __present_dre_F[sujet];
        __groupe_3["present_tir_F"] = __present_tir_F[sujet];
        __groupe_3["present_oir_F"] = __present_oir_F[sujet];
        __groupe_3["present_oire_F"] = __present_oire_F[sujet];
        __groupe_3["present_evoir_F"] = __present_evoir_F[sujet];
    }
    
    _nouvelle_terminaison = __groupe_3[temps_verbe + "_" + _ancienne_terminaison + "_F"];
}





// Les terminaisons des verbes du premier et deuxième groupe.

void Terminaison::nouvelle_terminaison_francaise_premier_ou_deuxieme_groupe(int groupe_verbe, int sujet, string temps)
{
    if (temps == "present" || temps == "present_be+ing")
    {
        __terminaisons["present_1_F"] = __present_1_F[sujet];
        __terminaisons["present_2_F"] = __present_2_F[sujet];
        
        _nouvelle_terminaison = __terminaisons[temps + "_" + to_string(groupe_verbe) + "_F"];
    }
    
    else
    {
        __terminaisons["passe_compose_F"] = "é";
        __terminaisons["imparfait_F"] = __imparfait_F[sujet];
        __terminaisons["futur_simple_F"] = __futur_simple_F[sujet];
        __terminaisons["conditionnel_F"] = __conditionnel_F[sujet];
        __terminaisons["passe_simple_F"] = __passe_simple_F[sujet];
        
        _nouvelle_terminaison = __terminaisons[temps + "_F"];
    }
}




// Détermine la terminaison après conjugaison du verbe.

void Terminaison::determiner_nouvelle_terminaison(string langue, string verbe, string temps_verbe, int sujet, int groupe_verbe)
{    
    if (langue == "F")
    {
        switch (groupe_verbe)
        {
            case 0 :
            {
                Auxiliaire auxiliaire;
                
                auxiliaire.construction_auxiliaire(sujet, langue, verbe, temps_verbe);
                
                _nouvelle_terminaison = auxiliaire.recuperer_auxiliaire();
            }
                break;
                
            case 1 : nouvelle_terminaison_francaise_premier_ou_deuxieme_groupe(groupe_verbe, sujet, temps_verbe);
                break;
                
            case 2 : nouvelle_terminaison_francaise_premier_ou_deuxieme_groupe(groupe_verbe, sujet, temps_verbe);
                break;
                
            case 3 : nouvelle_terminaison_francaise_troisieme_groupe(verbe, temps_verbe, sujet);
                break;
                
            default:
                break;
        }
    }
    
    else if (langue == "A")
    {
        switch (groupe_verbe)
        {
            case 0 :
            {
                Auxiliaire auxiliaire;
                
                auxiliaire.construction_auxiliaire(sujet, langue, verbe, temps_verbe);
                
                _nouvelle_terminaison = auxiliaire.recuperer_auxiliaire();
            }
                break;
                
            default : nouvelle_terminaison_anglaise(sujet, temps_verbe, verbe);
                break;
        }
    }
}




// Les terminaisons des verbes du troisième groupe.

void Terminaison::ancienne_terminaison_troisieme_groupe(string verbe)
{
    size_t max = 0;
    
    for (int i = 0; i < __terminaisons_groupe_3.size(); i++)
    {
        string terminaison = __terminaisons_groupe_3[i];
        
        
        // On s'assure que la terminaison sélectionnée n'est pas plus grande que le verbe.
        
        if (terminaison.size() < verbe.size())
        {
            // Pour ajouter une sécurité, on précise que la chaîne de caractères recherchée est à la fin,
            
            string fin_du_verbe = verbe.substr(verbe.size() - terminaison.size());
            
            
            // On s'assure que la terminaison trouvée est la plus grande possible.
            
            if (fin_du_verbe == terminaison && terminaison.size() > max)
            {                
                _ancienne_terminaison = terminaison;
                
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
            case 0 : _ancienne_terminaison = verbe;
                break;
                
            case 1 : _ancienne_terminaison = "er";
                break;
                
            case 2 : _ancienne_terminaison = "ir";
                break;
                
            case 3 : ancienne_terminaison_troisieme_groupe(verbe);
                
            default:
                break;
        }
    }
    
    else if (langue == "A")
    {
        switch (groupe_verbe)
        {
            case 0 : _ancienne_terminaison = verbe;
                break;
                
            default : _ancienne_terminaison = "";
                break;
        }
    }
}
