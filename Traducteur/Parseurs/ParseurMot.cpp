//
//  Parseur.cpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ParseurMot.hpp"

using namespace std;


Parseur::Parseur(string langue_source, string langue_sortie)
{
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




bool Parseur::parser_fichier(string mot_source)
{
    _mot_trouve = false;

    __types.clear();
    __sens_sortie.clear();
    __champs_lexicaux.clear();
    
    
    string ligne;

    ifstream fichier(_fichier);
    
    
    while (!fichier.eof() && !_mot_trouve)
    {
        fichier >> __mots["A"] >> __mots["F"] >> _types >> _champs_lexicaux;
        

        string mot,
               famille,
               champs_lexicaux;

        // On récupère l'ensemble des mots sources.
        
        istringstream flux_source(__mots[_langue_source]);
        
        while (getline(flux_source, mot, '/'))
        {
            // Si le mot entré par l'utilisateur est trouvé dans le fichier.
            
            if (mot == mot_source)
            {
                _mot_source = mot;
                
                
                // On récupère l'ensemble des mots traduits.
                // On commence par récupérer chaque famille.
                
                istringstream flux_famille(__mots[_langue_sortie]);
                
                while (getline(flux_famille, famille, '|'))
                {
                    istringstream flux_sortie(famille);

                    vector <string> sens;
                    
                    
                    // On récupère chaque sens qu'un mot peut avoir.
                    
                    while (getline(flux_sortie, mot, '/'))
                    {
                        sens.push_back(mot);
                    }
                    
                    __sens_sortie.push_back(sens);
                }
                
                // On récupère le type de chaque sens.
                
                istringstream flux_type(_types);
                
                while (getline(flux_type, mot, '|'))
                {
                    __types.push_back(mot);
                }
                
                // On récupère les différents champs lexicaux associés à un sens.
                
                __champs_lexicaux = parseur_champs_lexicaux.parser(_champs_lexicaux);
                                
                _mot_trouve = true;
                
                break;
            }
        }
    }
    
    fichier.close();
    
    return _mot_trouve;
}
