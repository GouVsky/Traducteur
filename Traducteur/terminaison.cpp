//
//  terminaison.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "terminaison.hpp"

#include "futur.hpp"
#include "imparfait.hpp"
#include "presentGr1.hpp"
#include "presentGr2.hpp"
#include "passeSimple.hpp"
#include "conditionnel.hpp"
#include "participePasse.hpp"

using namespace std;


string Terminaison::construction_de_la_terminaison(int groupe_verbe, string temps, int sujet, string langue, string verbe)
{
    Futur futur;
    Imparfait imparfait;
    PresentGr1 presentGr1;
    PresentGr2 presentGr2;
    PasseSimple passeSimple;
    Conditionnel conditionnel;
    ParticipePasse participePasse;
    
    if(temps == "present" || temps == "present_be+ing")
    {
        switch(groupe_verbe)
        {
            case 1 : terminaison = presentGr1.terminaison_premier_groupe_present(sujet, langue);
                break;
                
            case 2 : terminaison = presentGr2.terminaison_deuxieme_groupe_present(sujet, langue);
                break;
                
            default :
                break;
        }
    }
    
    else if(temps == "imparfait" || temps == "passe_habitude")
    {
        terminaison = imparfait.terminaison_imparfait(sujet, langue);
    }
    
    else if(temps == "passe_compose" || temps == "plus_que_parfait") // La terminaison sera le participe passé du verbe.
    {
        terminaison = participePasse.terminaison_participe_passe(langue, verbe);
    }
    
    else if(temps == "passe_simple")
    {
        terminaison = passeSimple.terminaison_passe_simple(sujet, langue, verbe);
    }
    
    else if(temps == "futur_simple")
    {
        terminaison = futur.terminaison_futur(sujet, langue);
    }
    
    else if(temps == "conditionnel")
    {
        terminaison = conditionnel.terminaison_conditionnel(sujet, langue);
    }
    
    string of_the_jedi = terminaison;
    
    return of_the_jedi;
}
