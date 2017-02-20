//
//  fenetre.hpp
//  Traducteur
//
//  Created by Grégoire on 05/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef fenetre_hpp
#define fenetre_hpp

#include <thread>
#include <string>
#include <stdio.h>

#include "Bouton.hpp"
#include "ZoneTexte.hpp"
#include "ChampTexte.hpp"
#include "RenduTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Fenetre
{
    public :
    
    Fenetre();
    static sf::Event * recuperer_evenement();
    static sf::RenderWindow * recuperer_fenetre();
    void affichage_des_elements();
    //void chargement_du_texte();
    void gestion_des_boutons();
    int creation_de_la_fenetre();
    
    private :
    
    sf::Font police;
    sf::Texture texture;
    sf::Event evenement;
    sf::Sprite chargement;
    static sf::RenderWindow fenetre;
    
    static std::vector <sf::Event> queue;
        
    static int element_dans_la_queue;
    
    int alpha_F = 120,
        alpha_A = 120,
        alpha_langue_traduction = 0;
    
    std::string langue_source,
                langue_sortie,
                texte_traduit;
    
    GBouton bouton_F,
            bouton_A,
            traduire,
            langue_de_traduction;
    
    GChampDeTexte champ_texte_source;
    
    GTexteDeRendu rendu;
};

#endif /* fenetre_hpp */
