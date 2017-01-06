//
//  icone.cpp
//  Traducteur
//
//  Created by Grégoire on 27/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "icone.hpp"

using namespace sf;
using namespace std;


// Création du drapeau représentant la langue dans lequel le texte sera traduit.

void Icone::creation_bouton_sortie(Sprite * bouton_sortie)
{
    affichage_langue_sortie = * bouton_sortie;
    affichage_langue_sortie.setPosition(1480, 50);
    affichage_langue_sortie.setColor(Color(255, 255, 255, 255));
}




// Détermine quel est la langue choisie.

void Icone::selection_du_bouton(Sprite * bouton_source, Sprite * bouton_sortie, string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
    
    bouton_actif = * bouton_source;
    
    creation_bouton_sortie(bouton_sortie);
    
    bouton_actif_sortie = affichage_langue_sortie;
}




// Création des boutons de sélections des langues.

tuple <string, string> Icone::creation_des_boutons(RenderWindow * fenetre, Texture langues, string source, string sortie)
{
    bouton_F.setTexture(langues);
    bouton_F.setScale(0.6, 0.6);
    bouton_F.setPosition(600, 50);
    bouton_F.setColor(Color(255, 255, 255, 120));
    bouton_F.setTextureRect(IntRect(0, 0, 219, 146));
    
    bouton_A.setTexture(langues);
    bouton_A.setScale(0.6, 0.6);
    bouton_A.setPosition(300, 50);
    bouton_A.setColor(Color(255, 255, 255, 120));
    bouton_A.setTextureRect(IntRect(219, 0, 216, 146));
    
    
    // Si une langue a déjà été sélectionnée.
    
    if (source == "A")
    {
        bouton_A.setColor(Color(255, 255, 255, 255));
        selection_du_bouton(&bouton_A, &bouton_F, source, sortie);
    }
    
    else if (source == "F")
    {
        bouton_F.setColor(Color(255, 255, 255, 255));
        selection_du_bouton(&bouton_F, &bouton_A, source, sortie);
    }
    
    
    // Si l'utilisateur n'a pas encore sélectionné de langue.
    
    // La langue source est l'anglais.
    
    if(bouton_A.getGlobalBounds().contains(Mouse::getPosition(* fenetre).x, Mouse::getPosition(* fenetre).y))
    {
        bouton_A.setColor(Color(255, 255, 255, 255));
        
        creation_bouton_sortie(&bouton_F);
        
        // La langue est sélectionnée.
        
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            selection_du_bouton(&bouton_A, &bouton_F, "A", "F");
        }
    }
    
    // La langue source est le français.
    
    else if(bouton_F.getGlobalBounds().contains(Mouse::getPosition(* fenetre).x, Mouse::getPosition(* fenetre).y))
    {
        bouton_F.setColor(Color(255, 255, 255, 255));

        creation_bouton_sortie(&bouton_A);
        
        // La langue est sélectionnée.
        
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            selection_du_bouton(&bouton_F, &bouton_A, "F", "A");
        }
    }
    
    // La souris ne survole plus les drapeaux.
    
    else
    {
        bouton_A.setColor(Color(255, 255, 255, 120));
        bouton_F.setColor(Color(255, 255, 255, 120));
        affichage_langue_sortie.setColor(Color(255, 255, 255, 0));
    }
    
    fenetre->draw(bouton_A);
    fenetre->draw(bouton_F);
    fenetre->draw(bouton_actif);
    fenetre->draw(bouton_actif_sortie);
    fenetre->draw(affichage_langue_sortie);
    
    return make_tuple(langue_source, langue_sortie);
}
