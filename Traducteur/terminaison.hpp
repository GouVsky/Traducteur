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
#include <stdio.h>

#define NB_TERMINAISONS 9
#define NB_TERMINAISONS_GR_3 7


class Terminaison
{
    public :
    
    void terminaisons_anglaises(int sujet, std::string temps, std::string verbe);
    void troisieme_groupe(int sujet, std::string verbe, std::string temps, std::string langue);
    void premier_et_deuxieme_groupe(int groupe_verbe, int sujet, std::string verbe, std::string temps, std::string langue);
    std::tuple <std::string, std::string> construction(int groupe_verbe, std::string temps, int sujet, std::string langue, std::string verbe);
    
    private :
    
    std::string nouvelle_terminaison, ancienne_terminaison;
    
    std::map <std::string, std::string> terminaisons, groupe_3;
    
    // Les terminaisons anglaises au présent.
    
    std::string A[NB_TERMINAISONS] = {"", "", "s", "s", "s", "", "", "", ""};
    
    
    
    // Les terminaisons françaises du premier et deuxième groupe à tous les temps.
    
    std::string futur_F[NB_TERMINAISONS] = {"ai", "as", "a", "a", "a", "ons", "ez", "ont", "ont"};
    std::string present_1_F[NB_TERMINAISONS] = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    std::string passe_simple_F[NB_TERMINAISONS] = {"ais", "ais", "a", "a", "a", "ions", "iez", "èrent", "èrent"};
    std::string imparfait_F[NB_TERMINAISONS] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    std::string present_2_F[NB_TERMINAISONS] = {"is", "is", "it", "it", "it", "issons", "issez", "issent", "issent"};
    std::string conditionnel_F[NB_TERMINAISONS] = {"ais", "ais", "ait", "ait", "ait", "ions", "iez", "aient", "aient"};
    
    
    // L'ensemble des terminaisons françaises du troisième groupe.
    
    std::string terminaisons_groupe_3[NB_TERMINAISONS_GR_3] = {"ir", "tir", "ire", "dre", "oir", "oire", "evoir"};
    
    // Les terminaisons du troisième groupe au présent.
    
    std::string present_ir_F[NB_TERMINAISONS] = {"e", "es", "e", "e", "e", "ons", "ez", "ent", "ent"};
    std::string present_tir_F[NB_TERMINAISONS] = {"s", "s", "t", "t", "t", "tons", "tez", "tent", "tent"};
    std::string present_ire_F[NB_TERMINAISONS] = {"s", "s", "t", "t", "t", "ions", "iez", "ient", "ient"};
    std::string present_dre_F[NB_TERMINAISONS] = {"ds", "ds", "d", "d", "d", "dons", "dez", "dent", "dent"};
    std::string present_oir_F[NB_TERMINAISONS] = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    std::string present_oire_F[NB_TERMINAISONS] = {"ois", "ois", "oit", "oit", "oit", "oyons", "oyez", "oient", "oient"};
    std::string present_evoir_F[NB_TERMINAISONS] = {"ois", "ois", "oit", "oit", "oit", "evons", "evez", "oivent", "oivent"};
};

#endif /* terminaison_hpp */
