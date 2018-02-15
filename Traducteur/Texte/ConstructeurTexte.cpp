//
//  ConstructeurTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 15/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "ConstructeurTexte.hpp"

using namespace std;


ConstructeurTexte::ConstructeurTexte(string texte, string source, string sortie) : __constructeur_phrase(source, sortie)
{
    _texte_source = texte;
}




void ConstructeurTexte::construire_texte()
{
    size_t nombre_phrases;
    
    
    __constructeur_phrase.construire_phrases(_texte_source);
    
    
    nombre_phrases = __constructeur_phrase.recuperer_nombre_phrases_traduites();
    
    
    for (int i = 0; i < nombre_phrases; i++)
    {
        _texte_traduit += __constructeur_phrase.recuperer_phrase_traduite(i);
    }
}
