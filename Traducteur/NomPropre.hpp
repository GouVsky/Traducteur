//
//  nomPropre.hpp
//  Traducteur
//
//  Created by Grégoire on 26/01/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef nomPropre_hpp
#define nomPropre_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

class NomPropre
{
    public :
    
    NomPropre();
    int recuperer_nombre_de_mots();
    std::string recuperer_genre(int numero_du_mot);
    std::string recuperer_mot(int numero_du_mot);
    void le_mot_est_un_nom_propre(std::string mot);
    
    private :
    
    int nombre_de_prenoms;
    
    std::string prenom;
    
    std::vector <std::string> tableau_des_prenoms,
                              tableau_des_genres;
    
    std::map <int, std::string> genre;
};

#endif /* nomPropre_hpp */
