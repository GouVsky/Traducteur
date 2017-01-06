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

#define DEBUT_TEXTE 40
#define FIN_TEXTE 970


// Retourne la position du curseur.

int Curseur::get_calcul_position()
{
    return position;
}




// Calcul de la position du curseur.

void Curseur::set_calcul_position(int position_dans_texte, int debut, int fin, int erreur, int coefficient, vector <string> tableau)
{
    position = position_dans_texte;
    
    int temporaire = position_dans_texte;
    
    for (int i = 0; i < tableau.size(); i++)
    {
        if (temporaire <= tableau[i].size() && i != erreur)
        {
            size_t debut_phrase = tableau[i + debut].substr(0, temporaire).size();
            
            size_t fin_phrase = tableau[i + fin].substr(temporaire).size();
            
            position += coefficient * (debut_phrase + fin_phrase);
            
            break;
        }
        
        else
        {
            temporaire -= tableau[i].size();
        }
    }
}




// Coloration du curseur en noir.

void Curseur::coloration(Color couleur)
{
    curseur.setFillColor(couleur);
}




// Définie la position du curseur selon où l'on se situe dans la phrase.

void Curseur::set_position(string texte_source, int position_dans_phrase, int y)
{
    texte.setFont(police);
    texte.setCharacterSize(37);
    texte.setColor(Color::Black);
    texte.setString(texte_source.substr(0, position_dans_phrase));
    
    int taille = texte.getLocalBounds().width;
    
    curseur.setPosition(Vector2f(DEBUT_TEXTE + taille + 2, y));
}




// Définie la taille du curseur.

void Curseur::taille(int largeur, int hauteur)
{
    curseur.setSize(Vector2f(largeur, hauteur));
}




// Création du curseur.

void Curseur::creation_curseur(Color couleur, int y, int largeur, int hauteur, string texte, int position_dans_phrase)
{
    set_position(texte, position_dans_phrase, y);
    coloration(couleur);
    taille(largeur, hauteur);
}




// Affichage du curseur.

RectangleShape Curseur::affichage(Font police_texte, int position_dans_phrase, vector <string> tableau)
{
    police = police_texte;

    for (int i = 0; i < tableau.size(); i++)
    {
        if (position_dans_phrase <= tableau[i].size())
        {
            creation_curseur(Color::Black, i * 45 + 200, 3, 50, tableau[i], position_dans_phrase);
            
            break;
        }
        
        else
        {
            position_dans_phrase -= tableau[i].size();
        }
    }
        
    return curseur;
}
