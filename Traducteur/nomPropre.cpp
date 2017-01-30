//
//  nomPropre.cpp
//  Traducteur
//
//  Created by Grégoire on 26/01/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "nomPropre.hpp"
#include "ResourcePath.hpp"

using namespace std;


tuple <string, vector <string>> NomPropre::le_mot_est_un_nom_propre(std::string mot)
{
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    string prenom_final;
    vector <string> tableau_genre;
    
    for (int i = 0; i < 2; i++)
    {
        ifstream fichier_prenoms(resourcePath() + "prenoms_" + genre[i] + "s.txt");
        
        // Est-ce un prénom ?
        
        while (!fichier_prenoms.eof())
        {
            fichier_prenoms >> prenom;
            
            if (prenom == mot)
            {
                tableau_genre.push_back(genre[i]);
                
                prenom[0] = toupper(prenom[0]);
                
                prenom_final = prenom;
                
                break;
            }
        }
        
        fichier_prenoms.close();
    }
    
    return make_tuple(prenom_final, tableau_genre);
}

