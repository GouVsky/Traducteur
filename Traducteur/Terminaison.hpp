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
    std::string recuperer_ancienne_terminaison() const { return _ancienne_terminaison; };
    std::string recuperer_nouvelle_terminaison() const { return _nouvelle_terminaison; };
    void nouvelle_terminaison_anglaise(int sujet, std::string temps, std::string verbe);
    void nouvelle_terminaison_francaise_troisieme_groupe(std::string verbe, std::string temps_verbe, int sujet);
    void nouvelle_terminaison_francaise_premier_ou_deuxieme_groupe(int groupe_verbe, int sujet, std::string temps);
    void determiner_nouvelle_terminaison(std::string langue, std::string verbe, std::string temps_verbe, int sujet, int groupe_verbe);
    void ancienne_terminaison_troisieme_groupe(std::string verbe);
    void determiner_ancienne_terminaison(std::string langue, std::string verbe, int groupe_verbe);
    
    private :
    
    std::string _nouvelle_terminaison,
                _ancienne_terminaison;
    
    std::map <std::string, std::string> __terminaisons,
                                        __groupe_3;
    
    // Les terminaisons anglaises au présent.
    
    std::vector <std::string> __A;
    
    
    
    // Les terminaisons françaises du premier et deuxième groupe à tous les temps.
    
    std::vector <std::string> __present_1_F,
                              __futur_simple_F,
                              __passe_simple_F,
                              __imparfait_F,
                              __present_2_F,
                              __conditionnel_F;
    
    
    // L'ensemble des terminaisons françaises du troisième groupe.
    
    std::vector <std::string> __terminaisons_groupe_3;
    
    // Les terminaisons du troisième groupe au présent.
    
    std::vector <std::string> __present_ir_F,
                              __present_tir_F,
                              __present_ire_F,
                              __present_dre_F,
                              __present_oir_F,
                              __present_oire_F,
                              __present_evoir_F;
};

#endif /* terminaison_hpp */
