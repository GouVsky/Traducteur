//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Parseur.hpp"
#include "ResourcePath.hpp"

using namespace std;


Parseur::Parseur(string langue_source, string langue_sortie)
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




void Parseur::parser_fichier(string chemin_fichier, string mot_source)
{
    _mot_trouve = false;

    __sens_sortie.clear();
    __champs_lexicaux.clear();
    
    string ligne;
    
    ifstream fichier(resourcePath() + chemin_fichier);
    
    while (!fichier.eof() && !_mot_trouve)
    {
        fichier >> __mots["A"] >> __mots["F"] >> _champs_lexicaux;
        

        string mot,
               champs_lexicaux;

        // On récupère l'ensemble des mots source.
        
        istringstream flux_source(__mots[_langue_source]);
        
        while (getline(flux_source, mot, '/'))
        {
            // Si le mot entré par l'utilisateur est trouvé dans le fichier.
            
            if (mot == mot_source)
            {
                _mot_source = mot;
                
                // On récupère l'ensemble des mots traduits.
                
                istringstream flux_sortie(__mots[_langue_sortie]);
                
                while (getline(flux_sortie, mot, '/'))
                {
                    __sens_sortie.push_back(mot);
                }
                
                // On récupère les différents champs lexicaux.
                
                istringstream flux_champs_lexicaux(_champs_lexicaux);
                
                while (getline(flux_champs_lexicaux, champs_lexicaux, '/'))
                {
                    __champs_lexicaux.push_back(champs_lexicaux);
                }
                
                _mot_trouve = true;
                
                break;
            }
        }
    }
    
    fichier.close();
}
