//
//  Parseur.hpp
//  Traducteur
//
//  Created by Grégoire on 11/04/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Parseur_hpp
#define Parseur_hpp

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie);
    std::vector <std::string> recuperer_champs_lexicaux() const { return __champs_lexicaux; };
    std::vector <std::string> recuperer_sens_sortie() const { return __sens_sortie; };
    bool le_mot_est_present_dans_fichier() const { return _mot_trouve; };
    void parser_fichier(std::string chemin_fichier, std::string mot_source);
    
    private :
    
    bool _mot_trouve;
    
    std::string _mot_source,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::vector <std::string> __sens_sortie,
                              __champs_lexicaux;
    
    std::map <std::string, std::string> __mots;
};

#endif /* Parseur_hpp */
