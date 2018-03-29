//
//  DonneesVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 22/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#ifndef DonneesVerbe_hpp
#define DonneesVerbe_hpp

#include <map>
#include <string>
#include <stdio.h>

class DonneesVerbe
{
    public :
    
    DonneesVerbe();
    int recuperer_groupe(std::string langue) { return __groupe[langue]; };
    std::string recuperer_verbe_source() { return _verbe_source; };
    std::string recuperer_verbe_traduit() { return _verbe_traduit; };
    size_t recuperer_indice_groupe_debut_verbe() { return _indice_groupe_debut_verbe; };
    void ajouter_groupe(std::string langue, int groupe);
    void ajouter_verbe_source(std::string verbe_source);
    void ajouter_verbe_traduit(std::string verbe_traduit);
    void ajouter_indice_groupe_debut_verbe(size_t indice_groupe_debut_verbe);
    
    private :
    
    std::string _verbe_source,
                _verbe_traduit;
    
    size_t _indice_groupe_debut_verbe;
    
    std::map <std::string, int> __groupe;
};

#endif /* DonneesVerbe_hpp */
