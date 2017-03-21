//
//  nomPropre.cpp
//  Traducteur
//
//  Created by Grégoire on 26/01/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "NomPropre.hpp"
#include "ResourcePath.hpp"

using namespace std;


NomPropre::NomPropre() : Mot()
{
    __genre[0] = "masculin";
    __genre[1] = "feminin";
}




string NomPropre::recuperer_genre()
{
    return _genre;
}




void NomPropre::le_mot_est_un_nom_propre(string mot)
{
    for (int i = 0; i< 2; i++)
    {
        ifstream fichier_noms_propres(resourcePath() + "noms_propres_" + __genre[i] + "s.txt");
        
        while (!fichier_noms_propres.eof())
        {
            fichier_noms_propres >> _nom_propre;
            
            if (_nom_propre == mot)
            {
                _nom_propre[0] = toupper(_nom_propre[0]);
                
                ajouter_mot(_nom_propre);
                
                _genre = __genre[i];
                
                break;
            }
        }
        
        fichier_noms_propres.close();
    }
}

