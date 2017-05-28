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

#include "ParseurChampsLexicaux.hpp"


class Parseur
{
    public :
    
    Parseur(std::string source, std::string sortie);
    size_t recuperer_nombre_fichiers() { return __fichiers.size(); };
    std::string recuperer_fichier(int numero_fichier) { return __fichiers[numero_fichier]; };
    std::vector <ChampsLexicaux> recuperer_champs_lexicaux() const { return __champs_lexicaux; };
    std::vector <std::string> recuperer_sens_sortie() const { return __sens_sortie; };
    bool parser_fichier(std::string chemin_fichier, std::string mot_source);
    
    private :
    
    ParseurChampsLexicaux parseur_champs_lexicaux;
    
    bool _mot_trouve;
    
    std::string _mot_source,
                _langue_source,
                _langue_sortie,
                _champs_lexicaux;
    
    std::vector <std::string> __sens_sortie;
    
    std::vector <ChampsLexicaux> __champs_lexicaux;
    
    std::map <std::string, std::string> __mots;
    
    std::vector <std::string> __fichiers = {"./Resources/Dictionnaire/adjectifs.txt",
                                            "./Resources/Dictionnaire/invariables.txt",
                                            "./Resources/Dictionnaire/noms_feminins.txt",
                                            "./Resources/Dictionnaire/noms_masculins.txt",
                                            "./Resources/Dictionnaire/noms_propres_feminins.txt",
                                            "./Resources/Dictionnaire/noms_propres_masculins.txt"};;
};

#endif /* Parseur_hpp */
