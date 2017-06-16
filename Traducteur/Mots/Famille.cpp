//
//  Famille.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Famille.hpp"

using namespace std;


Famille::Famille() {}




void Famille::definir_le_type(string classe, string categorie, string propriete)
{
    __type.definir_classe(classe);
    
    __type.definir_categorie(categorie);
    
    __type.definir_propriete(propriete);
}




void Famille::definir_les_champs_lexicaux_des_mots(vector <ChampsLexicaux> champs_lexicaux)
{
    for (int i = 0; i < __sens_sortie.size(); i++)
    {
        __sens_sortie[i].definir_les_differents_champs_lexicaux(champs_lexicaux[i]);
    }
}




void Famille::ajouter_sens_sortie(string mot)
{
    Mot sens_sortie(mot);
    
    __sens_sortie.push_back(mot);
}




void Famille::ajouter_sens_sortie(vector <string> mots)
{
    for (int i = 0; i < mots.size(); i++)
    {
        Mot sens_sortie(mots[i]);
        
        __sens_sortie.push_back(sens_sortie);
    }
}
