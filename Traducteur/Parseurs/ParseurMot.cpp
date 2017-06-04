//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurMot.hpp"

using namespace std;


ParseurMot::ParseurMot(string langue_source, string langue_sortie) : Parseur()
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}



bool ParseurMot::chercher_mot(string mot_source)
{
    _mot_trouve = false;
    
    
    string mot,
           ligne;

    ifstream fichier(_fichier);
    
    
    while (!fichier.eof() && !_mot_trouve)
    {
        fichier >> __mots["A"] >> __mots["F"] >> _types >> _champs_lexicaux;
        

        string champs_lexicaux;

        // On récupère l'ensemble des mots sources.
        
        istringstream flux_source(__mots[_langue_source]);
        
        while (getline(flux_source, mot, '/'))
        {
            // Si le mot entré par l'utilisateur est trouvé dans le fichier.
            
            if (mot == mot_source)
            {
                _mot_source = mot;
                
                
                parser_mots(__mots[_langue_sortie]);
                
                parser_types(_types);
                
                parser_champs_lexicaux(_champs_lexicaux);
                                
                _mot_trouve = true;
                
                break;
            }
        }
    }
    
    fichier.close();
    
    return _mot_trouve;
}
