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
    champ_texte_source.afficher();
    
    rendu.afficher(texte_traduit);
    
    bouton_F.definir_couleur(Color(255, 255, 255, alpha_F));
    bouton_A.definir_couleur(Color(255, 255, 255, alpha_A));
    
    langue_de_traduction.definir_couleur(Color(255, 255, 255, alpha_langue_traduction));
    
    traduire.afficher();
    bouton_F.afficher();
    bouton_A.afficher();
    langue_de_traduction.afficher();
}




void Fenetre::gestion_des_boutons()
{
    // La langue choisie est le français.
    
    if (bouton_F.est_presse())
    {
        alpha_F = 255;
        alpha_A = 100;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.rogner_image(219, 0, 216, 146);
        
        langue_source = "F";
        langue_sortie = "A";
    }
    
    // La langue choisie est l'anglais.
    
    else if (bouton_A.est_presse())
    {
        alpha_F = 100;
        alpha_A = 255;
        
        alpha_langue_traduction = 255;
        langue_de_traduction.rogner_image(0, 0, 219, 146);
        
        langue_source = "A";
        langue_sortie = "F";
    }
    
    if (traduire.est_presse())
    {
        Texte bob_le_bricoleur(langue_source, langue_sortie);
        
        bob_le_bricoleur.construction_du_texte(champ_texte_source.recuperer_texte());
        
        texte_traduit = bob_le_bricoleur.recuperer_texte_traduit();
    }
}




// Création de la fenêtre.

int Fenetre::creation_de_la_fenetre()
{
    fenetre.create(2080, 1060);
    
    champ_texte_source.definir_taille(1005, 760);
    champ_texte_source.definir_position(20, 200);
    champ_texte_source.definir_contours_visibles();
    
    rendu.definir_taille(1005, 760);
    rendu.definir_position(1055, 200);
    rendu.definir_contours_visibles();
    
    bouton_F.definir_image("selection_langue.png");
    bouton_F.definir_position(600, 50);
    bouton_F.redimensionner(0.6, 0.6);
    bouton_F.rogner_image(0, 0, 219, 146);
    
    bouton_A.definir_image("selection_langue.png");
    bouton_A.definir_position(300, 50);
    bouton_A.redimensionner(0.6, 0.6);
    bouton_A.rogner_image(219, 0, 216, 146);
    
    langue_de_traduction.definir_image("selection_langue.png");
    langue_de_traduction.definir_position(1480, 50);
    langue_de_traduction.redimensionner(0.6, 0.6);
    
    traduire.definir_image("traduire.png");
    traduire.definir_position(503, 990);
    traduire.redimensionner(0.06, 0.06);
    
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
