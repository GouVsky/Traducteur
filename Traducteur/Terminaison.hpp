//
//  terminaison.hpp
//  Traducteur_universel
//
//  Created by Grégoire on 22/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#ifndef terminaison_hpp
#define terminaison_hpp

#include <map>
#include <string>
#include <vector>
#include <stdio.h>


class Terminaison
{
    public :
    
    Terminaison();
    std::string recuperer_ancienne_terminaison() { return _ancienne_terminaison; };
    std::string recuperer_nouvelle_terminaison() { return _nouvelle_terminaison; };
    void nouvelle_terminaison_anglaise(int sujet, std::string temps, std::string verbe);
    void nouvelle_terminaison_troisieme_groupe(std::string verbe, std::string temps_verbe, int sujet);
    void nouvelle_terminaison_premier_ou_deuxieme_groupe(int groupe_verbe, int sujet, std::string temps);
    void determiner_nouvelle_terminaison(std::string langue, std::string verbe, std::string temps_verbe, int sujet, int groupe_verbe);
    void ancienne_terminaison_troisieme_groupe(std::string verbe);
    void determiner_ancienne_terminaison(std::string langue, std::string verbe, int groupe_verbe);
    
    private :
    
    std::string _nouvelle_terminaison,
                _ancienne_terminaison;
    
    std::map <std::string, std::string> __terminaisons,
                                        __groupe_3;
    
    // Les terminaisons anglaises au présent.
    
    std::vector <std::string> __A = {"", "", "s", "s", "s", "", "", "", ""};
    
    
    
    // Les terminaisons françaises du premier et deuxième groupe à tous les temps.
    
    std::vector <std::string> __present_1_F = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    std::vector <std::string> __futur_simple_F = {"ai", "as", "a", "a", "a", "ons", "ez", "ont", "ont"};
    std::vector <std::string> __passe_simple_F = {"ais", "ais", "a", "a", "a", "ions", "iez", "èrent", "èrent"};
    std::vector <std::string> __imparfait_F = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    std::vector <std::string> __present_2_F = {"is", "is", "it", "it", "it", "issons", "issez", "issent", "issent"};
    std::vector <std::string> __conditionnel_F = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    
    
    // L'ensemble des terminaisons françaises du troisième groupe.
    
    std::vector <std::string> __terminaisons_groupe_3 = {"ir", "tir", "ire", "dre", "oir", "oire", "evoir"};
    
    // Les terminaisons du troisième groupe au présent.
    
    std::vector <std::string> __present_ir_F = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    std::vector <std::string> __present_tir_F = {"s", "s", "t", "t", "t", "tons", "tez", "tent", "tent"};
    std::vector <std::string> __present_ire_F = {"s", "s", "t", "t", "t", "ions", "iez", "ient", "ient"};
    std::vector <std::string> __present_dre_F = {"ds", "ds", "d", "d", "d", "dons", "dez", "dent", "dent"};
    std::vector <std::string> __present_oir_F = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    std::vector <std::string> __present_oire_F = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    std::vector <std::string> __present_evoir_F = {"ois", "ois", "oit", "oit", "oit", "evons", "evez", "oivent", "oivent"};
};

#endif /* terminaison_hpp */
