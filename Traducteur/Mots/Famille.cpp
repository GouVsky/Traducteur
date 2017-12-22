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




Famille::Famille(vector <string> mots)
{
    for (int i = 0; i < mots.size(); i++)
    {
        Mot mot(mots[i]);
        
        __mots.push_back(mot);
    }
}




Famille::Famille(string mot)
{
    Mot inconnu(mot);
    
    __mot_dominant = inconnu;
}




Famille & Famille::operator=(Famille famille)
{
    __type = famille.__type;
    
    __mots = famille.__mots;
    
    __mot_dominant = famille.__mot_dominant;
    
    return * this;
}




Famille Famille::operator+(Famille famille)
{
    Famille reunion;
    
    size_t nombre_mots_famille_1 = __mots.size(),
           nombre_mots_famille_2 = famille.__mots.size();
    
    
    for (int i = 0; i < nombre_mots_famille_1; i++)
    {
        reunion.__mots.push_back(__mots[i]);
    }
    
    for (int i = 0; i < nombre_mots_famille_2; i++)
    {
        reunion.__mots.push_back(famille.__mots[i]);
    }
    
    reunion.__type = __type + famille.__type;
    
    reunion.__mot_dominant = __mot_dominant + famille.__mot_dominant;
    
    return reunion;
}




Famille & Famille::operator+=(Famille famille)
{
    * this = * this + famille;
    
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




void Famille::determiner_mot_dominant(ChampsLexicaux & champs_lexicaux)
{
    int max = -1,
        valeur_champ_lexical = -1;
    
    size_t nombre_de_sens = __mots.size();
    
    
    for (int i = 0; i < nombre_de_sens; i++)
    {
        // On récupère le mot dominant de la famille en fonction des champs lexicaux de la phrase.
        // Pour cela, on récupère le champ lexical dominant parmi ceux que les mots possèdent.
        // S'il y a un conflit entre plusieurs sens, on les garde.
        
        champs_lexicaux.recuperation_plus_grand_champ_lexical_commun(__mots[i].recuperer_champs_lexicaux());
        
        valeur_champ_lexical = __mots[i].recuperer_champs_lexicaux().recuperer_champ_lexical_dominant().second;
        

        if (valeur_champ_lexical > max)
        {
            max = valeur_champ_lexical;
            
            __mot_dominant = __mots[i];
        }
        
        else if (valeur_champ_lexical == max)
        {
            __mot_dominant += __mots[i];
        }
    }
}
