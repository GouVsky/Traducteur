//
//  renduTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Fenetre.hpp"
#include "RenduTexte.hpp"


using namespace sf;
using namespace std;


GTexteDeRendu::GTexteDeRendu() : GZoneDeTexte() {}




// Affichage de la zone de rendu.

void GTexteDeRendu::afficher()
{
    Fenetre fenetre;
    
    texture.create(largeur, hauteur);
    
    texture.clear(Color::White);
            
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contours);
}




// Affichage dans texte dans la zone de rendu.

void GTexteDeRendu::afficher(string texte)
{
    Fenetre fenetre;
    
    texture.clear(Color::White);
    
    _texte.afficher_texte(&texture, texte);
        
    texture.display();
    
    sprite.setTexture(texture.getTexture());
    sprite.setPosition(position_x, position_y);
    
    (fenetre.recuperer_fenetre())->draw(sprite);
    (fenetre.recuperer_fenetre())->draw(contours);
}
