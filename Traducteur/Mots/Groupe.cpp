//
//  Groupe.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Groupe.hpp"

using namespace std;



Groupe::Groupe(string mot_source)
{    
    _mot_source = mot_source;
}




Groupe & Groupe::operator=(Groupe groupe)
{
    _mot_source = groupe._mot_source;
    
    __familles = groupe.__familles;
    
    __famille_dominante = groupe.__famille_dominante;
    
    return * this;
}




void Groupe::ajouter_famille(Famille famille)
{
    __familles.push_back(famille);
}



#include <iostream>
void Groupe::determiner_famille_dominante()
{
    int max = -1,
        valeur_champ_lexical_dominant = 0;
    
    
    for (int famille = 0; famille < __familles.size(); famille++)
    {
        valeur_champ_lexical_dominant = __familles[famille].recuperer_mot_dominant().recuperer_champs_lexicaux().recuperer_champ_lexical_dominant().second;

        //cout << __familles[famille].recuperer_mot_dominant().recuperer_mot() << " " << valeur_champ_lexical_dominant << endl;
        
        if (valeur_champ_lexical_dominant > max)
        {
            max = valeur_champ_lexical_dominant;
            
            __famille_dominante = __familles[famille];
        }
        
        else if (valeur_champ_lexical_dominant == max)
        {
            __famille_dominante += __familles[famille];
        }
    }
}
