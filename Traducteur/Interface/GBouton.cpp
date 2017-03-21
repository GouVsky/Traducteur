//
//  bouton.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "GBouton.hpp"
#include "GFenetre.hpp"
#include "ResourcePath.hpp"

using namespace sf;
using namespace std;


GBouton::GBouton() : GImage() {}




GBouton::GBouton(string nom_fichier) : GImage(nom_fichier) {}




// Définie une image en tant que bouton.

void GBouton::definir_image(string nom_fichier)
{
    texture.loadFromFile(resourcePath() + nom_fichier);
    
    image.setTexture(texture);
}




// Indique si le bouton est survolé par l'utilisateur.

bool GBouton::est_survole()
{
    if(image.getGlobalBounds().contains(Mouse::getPosition(* (GFenetre::getWindow())).x,
                                        Mouse::getPosition(* (GFenetre::getWindow())).y))
    {
        return true;
    }
    
    return false;
}




// Indique si le bouton a été pressé par l'utilisateur.

bool GBouton::est_presse()
{
    if(est_survole() && Mouse::isButtonPressed(Mouse::Left))
    {
        return true;
    }
    
    return false;
}




// Définie la couleur du bouton.

void GBouton::definir_couleur(Color c)
{
    couleur = c;
    
    image.setColor(couleur);
}