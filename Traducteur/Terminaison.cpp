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
    // Présent.

    __terminaisons["A"]["PRE"] = {"", "", "s", "s", "s", "", "", "", ""};
    __terminaisons["A"]["ING"] = {"", "", "", "", "", "", "", "", ""};
    
    __terminaisons["F"]["PREer"] = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    __terminaisons["F"]["PREir"] = {"is", "is", "it", "it", "it", "issons", "issez", "issent", "issent"};
    __terminaisons["F"]["PRE3ir"] = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    __terminaisons["F"]["PRE3tir"] = {"s", "s", "t", "t", "t", "tons", "tez", "tent", "tent"};
    __terminaisons["F"]["PRE3ire"] = {"s", "s", "t", "t", "t", "ions", "iez", "ient", "ient"};
    __terminaisons["F"]["PRE3dre"] = {"ds", "ds", "d", "d", "d", "dons", "dez", "dent", "dent"};
    __terminaisons["F"]["PRE3oir"] = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    __terminaisons["F"]["PRE3oire"] = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    __terminaisons["F"]["PRE3evoir"] = {"ois", "ois", "oit", "oit", "oit", "evons", "evez", "oivent", "oivent"};
    
    
    // Futur.
    
    __terminaisons["F"]["FUSer"] = {"ai", "as", "a", "a", "a", "ons", "ez", "ont", "ont"};
    __terminaisons["F"]["FUSir"] = __terminaisons["F"]["FUSer"];
    
    
    // Passé.
    
    __terminaisons["F"]["PASer"] = {"ais", "ais", "a", "a", "a", "ions", "iez", "èrent", "èrent"};
    __terminaisons["F"]["PASir"] = __terminaisons["F"]["PASer"];
    
    __terminaisons["F"]["IMPer"] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    __terminaisons["F"]["IMPir"] = __terminaisons["F"]["IMPer"];
    
    
    // Conditionnel.
    
    __terminaisons["F"]["CONer"] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    __terminaisons["F"]["CONir"] = __terminaisons["F"]["CONer"];
}




void Terminaison::determiner_nouvelle_terminaison(string langue, string temps, int sujet, int groupe)
{
    string temps_verbe = temps;
    
    
    // Ajout du chiffre 3 pour différencier un cas spécifique du troisième groupe français.
    // Ce cas concerne une terminaison identique à celle du deuxième groupe.
    
    temps_verbe.append((groupe == 3 && langue == "F") ? "3" : "");
    
    
    _nouvelle_terminaison = __terminaisons[langue][temps_verbe + _ancienne_terminaison][sujet];
}




void Terminaison::ancienne_terminaison_troisieme_groupe(string verbe)
{
    size_t max = 0;
    
    vector <string> terminaisons = {"ir", "tir", "ire", "dre", "oir", "oire", "evoir"};

    
    for (int i = 0; i < terminaisons.size(); i++)
    {
        string terminaison = terminaisons[i];
        
        
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




void Terminaison::determiner_ancienne_terminaison(string langue, string verbe, int groupe_verbe)
{
    if (langue == "F")
    {
        switch (groupe_verbe)
        {
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
        _ancienne_terminaison = "";
    }
}
