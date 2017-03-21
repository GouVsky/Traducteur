//
//  CreationFenetre.cpp
//  Traducteur
//
//  Created by Grégoire on 21/03/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "CreationFenetre.hpp"

using namespace sf;
using namespace std;


Fenetre::Fenetre()
{
    langue_source = "";
    langue_sortie = "";
}




void Fenetre::affichage_des_elements()
{
    champ_texte_source.display();
    
    rendu.display(texte_traduit);
    
    bouton_F.setColor(Color(255, 255, 255, alpha_F));
    bouton_A.setColor(Color(255, 255, 255, alpha_A));
    
    langue_de_traduction.setColor(Color(255, 255, 255, alpha_langue_traduction));
    
    traduire.display();
    bouton_F.display();
    bouton_A.display();
    langue_de_traduction.display();
}




void Fenetre::gestion_des_boutons()
{
    // La langue choisie est le français.
    
    if (bouton_F.isPressed())
    {
        alpha_F = 255;
        alpha_A = 100;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.setROI(219, 0, 216, 146);
        
        langue_source = "F";
        langue_sortie = "A";
    }
    
    // La langue choisie est l'anglais.
    
    else if (bouton_A.isPressed())
    {
        alpha_F = 100;
        alpha_A = 255;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.setROI(0, 0, 219, 146);
        
        langue_source = "A";
        langue_sortie = "F";
    }
    
    if (traduire.isPressed())
    {
        Texte bob_le_bricoleur(langue_source, langue_sortie);
        
        bob_le_bricoleur.construction_du_texte(champ_texte_source.getText());
        
        texte_traduit = bob_le_bricoleur.recuperer_texte_traduit();
    }
}




// Création de la fenêtre.

int Fenetre::creation_de_la_fenetre()
{
    fenetre.create(2080, 1060);
    
    champ_texte_source.setSize(1005, 760);
    champ_texte_source.setPosition(20, 200);
    champ_texte_source.setVisibleContours();
    
    rendu.setSize(1005, 760);
    rendu.setPosition(1055, 200);
    rendu.setVisibleContours();
    
    bouton_F.setImage("selection_langue.png");
    bouton_F.setPosition(600, 50);
    bouton_F.resize(0.6, 0.6);
    bouton_F.setROI(0, 0, 219, 146);
    
    bouton_A.setImage("selection_langue.png");
    bouton_A.setPosition(300, 50);
    bouton_A.resize(0.6, 0.6);
    bouton_A.setROI(219, 0, 216, 146);
    
    langue_de_traduction.setImage("selection_langue.png");
    langue_de_traduction.setPosition(1480, 50);
    langue_de_traduction.resize(0.6, 0.6);
    
    traduire.setImage("traduire.png");
    traduire.setPosition(503, 990);
    traduire.resize(0.06, 0.06);
    
    while (fenetre.isOpen())
    {
        fenetre.clear();
        
        while (fenetre.pollEvent(evenement))
        {
            // On ferme la fenêtre en pressant la croix ou en appuyant sur "ECHAP".
            
            if(evenement.type == Event::Closed || (evenement.type == Event::KeyPressed && evenement.key.code == Keyboard::Escape))
            {
                fenetre.close();
            }
        }
        
        affichage_des_elements();
        
        gestion_des_boutons();
        
        fenetre.display();
    }
    
    return EXIT_SUCCESS;
}
