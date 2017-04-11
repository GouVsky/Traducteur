//
//  Groupe.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Groupe_hpp
#define Groupe_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "Famille.hpp"


class Groupe
{
    public :
    
    Groupe(std::string mot_source);
    std::string recuperer_mot_source() const { return _mot_source; };
    int recuperer_nombre_de_familles() const { return __familles.size(); };
    Famille & recuperer_famille(int numero_famille) { return __familles[numero_famille]; };
    void ajouter_famille(Famille famille);
    
    private :
    
    std::string _mot_source;
    
    std::vector <Famille> __familles;
};

#endif /* Groupe_hpp */
