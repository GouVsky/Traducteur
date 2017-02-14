//
//  renduTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "fenetre.hpp"
#include "renduTexte.hpp"


using namespace sf;
using namespace std;


GTexteDeRendu::GTexteDeRendu() : GZoneDeTexte() {}




// Affichage de la zone de rendu.

void GTexteDeRendu::afficher()
{
    Fenetre fenetre;
    
    texture.create(largeur, hauteur);
    
    texture.clear(Color::White);
    
    definir_contours();
        
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contour);
}




// Affichage dans texte dans la zone de rendu.

void GTexteDeRendu::afficher(string texte)
{
    Fenetre fenetre;
    
    texture.create(largeur, hauteur);
    
    texture.clear(Color::White);
    
    traitement_des_phrases(texte, &texture);
    
    definir_contours();
    
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contour);
}
