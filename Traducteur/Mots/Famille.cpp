//
//  Famille.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Famille.hpp"

using namespace std;


Famille::Famille(vector <string> mots)
{
    for (int i = 0; i < mots.size(); i++)
    {
        Mot mot(mots[i]);
        
        __mots.push_back(mot);
    }
}



Famille & Famille::operator=(Famille famille)
{
    __type = famille.__type;
    
    __mots = famille.__mots;
    
    return * this;
}




void Famille::ajouter_type(Type type)
{
    __type = type;
}




void Famille::ajouter_champs_lexicaux(vector <ChampsLexicaux> champs_lexicaux)
{
    for (int i = 0; i < __mots.size(); i++)
    {
        __mots[i].definir_les_differents_champs_lexicaux(champs_lexicaux[i]);
    }
}
