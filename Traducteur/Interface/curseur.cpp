//
//  curseur.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "curseur.hpp"

using namespace sf;
using namespace std;


GCurseur::GCurseur()
{
    largeur = 0;
    hauteur = 0;
    
    position_x = 30;
    position_y = 20;
    
    couleur = Color::Black;
}




// Calcul de la position du curseur.

void GCurseur::calcul_de_la_position(vector <string> tableau, vector <int> parametres)
{
    int temporaire = position_x;
    
    for (int i = 0; i < tableau.size(); i++)
    {
        if (temporaire <= tableau[i].size() && i != parametres[2])
        {
            size_t debut_phrase = tableau[i + parametres[0]].substr(0, temporaire).size();
            
            size_t fin_phrase = tableau[i + parametres[1]].substr(temporaire).size();
            
            position_x += parametres[3] * (debut_phrase + fin_phrase);
            
            break;
        }
        
        else
        {
            temporaire -= tableau[i].size();
        }
    }
}




int GCurseur::recuperer_position_y()
{
    return position_y;
}




int GCurseur::recuperer_position_x()
{
    return position_x;
}




// Définie la position du curseur selon où l'on se situe dans la phrase.

void GCurseur::definir_position(int x, int y, vector <string> tableau, vector <int> parametres)
{
    position_x = 30 + x;
    
    position_y += y * 45;
        
    calcul_de_la_position(tableau, parametres);
    
    curseur.setPosition(Vector2f(position_x, position_y));
}




// Définie la couleur du curseur.

void GCurseur::definir_couleur(Color c)
{
    couleur = c;
    
    curseur.setFillColor(couleur);
}




// Définie la taille du curseur.

void GCurseur::definir_taille(int l, int h)
{
    largeur = l;
    
    hauteur = h;
    
    curseur.setSize(Vector2f(largeur, hauteur));
}




// Affichage du curseur.

void GCurseur::afficher(RenderTexture * texture)
{
    texture->draw(curseur);
}
