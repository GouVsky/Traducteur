//
//  auxilliaire.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 26/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef auxilliaire_hpp
#define auxilliaire_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>

class Auxiliaire
{
    public :
    
    Auxiliaire();
    std::string recuperer_auxiliaire() const { return _auxiliaire; };
    void construction_auxiliaire(int pronom, std::string langue, std::string auxiliaire, std::string temps);
    
    private :
    
    std::string _auxiliaire;
    
    std::map <std::string, std::string> __auxiliaire_etre,
                                        __auxiliaire_avoir;
    
    // Auxiliaires anglais.
    
    std::vector <std::string> __present_etre_A = {"am", "are", "is", "is", "is", "are", "are", "are", "are"};
    std::vector <std::string> __present_avoir_A = {"have", "have", "has", "has", "has", "have", "have", "have", "have"};
    
    
    // Auxiliaire français.
    
    std::vector <std::string> __present_etre_F = {"suis", "es", "est", "est", "est", "sommes", "êtes", "sont", "sont"};
    std::vector <std::string> __present_avoir_F = {"ai", "as", "a", "a", "a", "avons", "avez", "ont", "ont"};
    
    
    std::map <std::string, std::string> __conjugaison_auxiliaire;
};

#endif /* auxilliaire_hpp */
