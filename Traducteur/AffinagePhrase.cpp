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




void Affinage::affiner_phrases(vector <vector <string>> phrases, vector <vector <string>> structure)
{
    NomCommun nom_commun(_langue_source, _langue_sortie);
    
    for (int i = 0; i < phrases.size(); i++)
    {
        for (int j = 0; j < phrases[i].size(); j++)
        {
            if (structure[i][j].find("masculin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(&phrases[i][j], _langue_sortie);
            }
            
            else if (structure[i][j].find("feminin_pluriel") != -1)
            {
                nom_commun.accorder_pluriel(&phrases[i][j], _langue_sortie);
            }
            
            _phrase_sortie += phrases[i][j] + '/';
        }
        
        _phrase_sortie.erase(_phrase_sortie.size() - 1);
        
        _phrase_sortie += ' ';
    }
    
    _phrase_sortie.erase(_phrase_sortie.size() - 1);
}
