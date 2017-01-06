//
//  participePasse.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/10/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "participePasse.hpp"

using namespace std;


string ParticipePasse::terminaison_participe_passe(string langue, string verbe)
{
    participe_passe["terminaison_participe_passe_F"] = "\u00E9";
    
    if(verbe[verbe.size()-1] == 'e')
    {
        participe_passe["terminaison_participe_passe_A"] = 'd';
    }
    
    else participe_passe["terminaison_participe_passe_A"] = "ed";
    
    return participe_passe["terminaison_participe_passe_" + langue];
}
