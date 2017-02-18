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


NomPropre::NomPropre() : Mot() {}




string NomPropre::recuperer_genre()
{
    return _genre;
}




void NomPropre::definir_genre(string genre)
{
    _genre = genre;
}




void NomPropre::le_mot_est_un_nom_propre(std::string mot)
{
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    for (int i = 0; i < 2; i++)
    {
        ifstream fichier_prenoms(resourcePath() + "prenoms_" + genre[i] + "s.txt");
        
        // Est-ce un prénom ?
        
        while (!fichier_prenoms.eof())
        {
            fichier_prenoms >> _prenom;
            
            if (_prenom == mot)
            {
                _prenom[0] = toupper(_prenom[0]);
                
                ajouter_mot(_prenom);
                
                definir_genre(genre[i]);
                
                break;
            }
        }
        
        fichier_prenoms.close();
    }
}

