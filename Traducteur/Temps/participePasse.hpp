//
//  participePasse.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef participePasse_hpp
#define participePasse_hpp

#include <map>
#include <string>
#include <stdio.h>

class ParticipePasse
{
    public :
    
    std::string terminaison_participe_passe(std::string langue, std::string verbe);
    
    private :
    
    std::map <std::string, std::string> participe_passe;
};

#endif /* participePasse_hpp */
