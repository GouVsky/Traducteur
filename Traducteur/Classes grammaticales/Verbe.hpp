//
//  verbe.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef verbe_hpp
#define verbe_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>


class Verbe
{
    public :
    
    Verbe();
    size_t recuperer_taille() { return _taille; };
    std::string recuperer_verbe() { return _verbe_construit; };
    Verbe & operator=(Verbe verbe);
    void definir_indice_groupe_debut_verbe(size_t indice);
    void construire_verbe(std::string langue, std::string verbe, std::vector <std::string> & formes, std::string temps, int sujet);
    
    private :
    
    void calculer_taille();
    
        
    size_t _taille,
           _indice_groupe_debut_verbe;
    
    std::string _temps,
                _verbe_construit;
};

#endif /* verbe_hpp */
