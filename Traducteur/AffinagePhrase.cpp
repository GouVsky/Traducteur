//
//  AffinagePhrase.cpp
//  Traducteur
//
//  Created by Grégoire on 20/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "NomCommun.hpp"
#include "AffinagePhrase.hpp"

using namespace std;


Affinage::Affinage(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
}




string Affinage::recuperer_phrase_sortie()
{
    return _phrase_sortie;
}




void Affinage::affiner_phrases(vector <string> phrases, vector <string> structure)
{
    NomCommun nom_commun(_langue_source, _langue_sortie);
    
    for (int i = 0; i < structure.size(); i++)
    {
        if (structure[i].find("masculin_pluriel") != -1)
        {
            phrases[i] = nom_commun.accorder_pluriel(phrases[i]);
        }
        
        else if (_langue_sortie == "F")
        {
            // Adjectifs.
        }
    }
    
    for (int i = 0; i < phrases.size(); i++)
    {
        _phrase_sortie += phrases[i] + ' ';
    }
    
    _phrase_sortie.erase(_phrase_sortie.size() - 1);
}
