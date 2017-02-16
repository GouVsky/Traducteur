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
#include <stdio.h>

class Auxilliaire
{
    public :
    
    std::string construction_auxilliaire(int pronom, std::string langue, std::string auxilliaire, std::string temps);
    
    private :
    
    std::map <std::string, std::string> conjugaison_auxilliaire;
    
    // Verbe "Aller".
    
    const std::string tableau_aller_present_F[10] = {"vais", "vas", "va", "va", "va", "allons", "allez", "vont", "vont", "aller"};

    // Auxilliaire "Avoir".
    
    const std::string tableau_avoir_present_F[10] = {"ai", "as", "a", "a", "a", "avons", "avez", "ont", "ont", "avoir"};
    const std::string tableau_avoir_present_A[10] = {"have", "have", "has", "has", "has", "have", "have", "have", "have", "have"};
    
    const std::string tableau_avoir_plus_que_parfait_F[10] = {"avais", "avais", "avait", "avait", "avait", "avions", "aviez", "avaient", "avaient", "avoir"};
    const std::string tableau_avoir_plus_que_parfait_A[10] = {"had", "had", "had", "had", "had", "had", "had", "had", "had", "have"};
    
    // Auxilliaire "Etre".
    
    const std::string tableau_etre_present_F[10] = {"suis", "es", "est", "est", "est", "sommes", "êtes", "sont", "sont", "être"};
    const std::string tableau_etre_present_A[10] = {"am", "are", "is", "is", "is", "are", "are", "are", "are", "be"};
};

#endif /* auxilliaire_hpp */
