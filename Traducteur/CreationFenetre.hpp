//
//  CreationFenetre.hpp
//  Traducteur
//
//  Created by Grégoire on 21/03/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef CreationFenetre_hpp
#define CreationFenetre_hpp

#include <string>
#include <stdio.h>

#include "GBouton.hpp"
#include "GFenetre.hpp"
#include "GZoneTexte.hpp"
#include "GChampTexte.hpp"
#include "GRenduTexte.hpp"
#include "ConstructionTexte.hpp"
#include "ConstructionPhrase.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Fenetre
{
    public :
    
    Fenetre();
    void affichage_des_elements();
    void gestion_des_boutons();
    int creation_de_la_fenetre();
    
    private :
    
    int alpha_F = 120,
        alpha_A = 120,
        alpha_langue_traduction = 0;
    
    std::string langue_source,
                langue_sortie,
                texte_traduit;
    
    sf::Event evenement;
    
    GFenetre fenetre;
    
    GBouton bouton_F,
            bouton_A,
            traduire,
            langue_de_traduction;
    
    GChampDeTexte champ_texte_source;
    
    GTexteDeRendu rendu;
};


#endif /* CreationFenetre_hpp */
