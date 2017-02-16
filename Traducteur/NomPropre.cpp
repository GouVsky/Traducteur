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


NomPropre::NomPropre()
{
    nombre_de_prenoms = 0;
}




int NomPropre::recuperer_nombre_de_mots()
{
    return nombre_de_prenoms;
}




string NomPropre::recuperer_genre(int numero_du_mot)
{
    return tableau_des_genres[numero_du_mot];
}




string NomPropre::recuperer_mot(int numero_du_mot)
{
    return tableau_des_prenoms[numero_du_mot];
}




void NomPropre::le_mot_est_un_nom_propre(std::string mot)
{
    genre[0] = "masculin";
    genre[1] = "feminin";
    
    nombre_de_prenoms = 0;
    
    tableau_des_prenoms.clear();
    tableau_des_genres.clear();
    
    for (int i = 0; i < 2; i++)
    {
        ifstream fichier_prenoms(resourcePath() + "prenoms_" + genre[i] + "s.txt");
        
        // Est-ce un prénom ?
        
        while (!fichier_prenoms.eof())
        {
            fichier_prenoms >> prenom;
            
            if (prenom == mot)
            {
                nombre_de_prenoms++;
                
                prenom[0] = toupper(prenom[0]);
                
                tableau_des_prenoms.push_back(prenom);
                tableau_des_genres.push_back(genre[i]);
                
                break;
            }
        }
        
        fichier_prenoms.close();
    }
}

