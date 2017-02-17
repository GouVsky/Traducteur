//
//  zoneTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 03/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Fenetre.hpp"
#include "ZoneTexte.hpp"

using namespace sf;
using namespace std;

#define DEBUT_TEXTE 30
#define FIN_TEXTE largeur - 50


GZoneDeTexte::GZoneDeTexte()
{
    largeur = 0;
    hauteur = 0;
    
    position_x = 0;
    position_y = 0;
    
    numero_couleur = 0.5;
    
    texte_source = "";
}




// Affiche un easter egg.

void GZoneDeTexte::easter_egg(Text texte, string mot, int indice_ligne)
{
    couleur[0] = Color::Color(160, 0, 155);
    couleur[1] = Color::Color(4, 42, 200);
    couleur[2] = Color::Color(0, 140, 255);
    couleur[3] = Color::Color(0, 200, 0);
    couleur[4] = Color::Color(240, 230, 10);
    couleur[5] = Color::Color(236, 135, 0);
    couleur[6] = Color::Red;
    
    
    size_t position = mot.find("[rainbow]");
    
    // Si le mot "[rainbow]" n'est pas un mot à part,
    // Il faut l'isoler pour qu'il puisse être coloré.
    
    texte.setString(mot.substr(0, position));
    texte.setPosition(DEBUT_TEXTE + taille_phrase, 200 + indice_ligne * 45);
    texture->draw(texte);
    
    taille = texte.getLocalBounds().width;
    
    // On colore le mot "[rainbow]".
    
    texte.setString(mot.substr(position, 9));
    texte.setColor(couleur[(int) numero_couleur % 7]);
    texte.setPosition(DEBUT_TEXTE + taille_phrase + taille, 200 + indice_ligne * 45);
    texture->draw(texte);
    
    taille += texte.getLocalBounds().width;
    
    // Le reste du mot (s'il n'y avait pas d'espace avec [rainbow]).
    
    texte.setColor(Color::Black);
    texte.setString(mot.substr(position + 9));
    texte.setPosition(DEBUT_TEXTE + taille_phrase + taille, 200 + indice_ligne * 45);
    texture->draw(texte);
    
    taille += texte.getLocalBounds().width;
    
    numero_couleur += 0.5;
}




// Affichage de chaque ligne.

void GZoneDeTexte::affichage_des_phrases(int indice_ligne)
{
    taille_phrase = 0;
    
    // Affichage des mots.
    
    for (int i = 0; i < t_justification.size(); i++)
    {
        taille = 0;
        
        /*wstring ws(t_justification[i].size(), L' ');
         ws.resize(mbstowcs(&ws[0], t_justification[i].c_str(), t_justification[i].size()));*/
        
        texte.setFont(police);
        texte.setCharacterSize(37);
        texte.setColor(Color::Black);
        texte.setString(t_justification[i]);
        
        // Si l'utilisateur a activé l'easter egg.
        
        if (t_justification[i].find("[rainbow]") != -1)
        {
            easter_egg(texte, t_justification[i], indice_ligne);
        }
        
        else
        {
            texte.setPosition(DEBUT_TEXTE + taille_phrase, 20 + indice_ligne * 45);
            
            texture->draw(texte);
            
            taille = texte.getLocalBounds().width;
        }
        
        taille_phrase += taille;
        
        compteur_structure++;
    }
}




// Justification du texte.

void GZoneDeTexte::justification_du_texte(string phrase, int indice)
{
    string mot = "";
    int nb_espace_a_ajouter = 0;
    
    t_justification.clear();
    
    Text ligne(phrase, police, 37);
    
    // On calcule la marge comprise entre la fin de la phrase et le seuil.
    // On récupère la taille en pixel du caractère espace.
    // Et on en déduit le nombre d'espace à ajouter.
    
    if (ligne.getLocalBounds().width > 0 && ligne.getLocalBounds().width < FIN_TEXTE)
    {
        Text espace(' ', police, 37);
        
        int difference = FIN_TEXTE - ligne.getLocalBounds().width;
        
        nb_espace_a_ajouter = difference / (espace.getLocalBounds().width);
    }
    
    // Decoupage de la phrase à chaque espace pour isoler les mots.
    
    istringstream iss(phrase);
    
    while (getline(iss, mot, ' '))
    {
        t_justification.push_back(mot + ' ');
    }
    
    // On ajoute un espace entre chaque mot jusqu'à atteindre le seuil.
    // La dernière ligne n'est justifiée que si elle est suffisamment grande.
    
    if (indice < compteur || (indice == compteur && ligne.getLocalBounds().width > FIN_TEXTE - 20))
    {
        for (int i = 1; i < nb_espace_a_ajouter; i++)
        {
            t_justification[i % (t_justification.size() - 1)] += ' ';
        }
    }
}




// Construction d'un texte affiché sur plusieurs lignes.

void GZoneDeTexte::texte_multilignes(char caractere)
{
    ligne = tableau[compteur] + caractere;
    
    Text texte(ligne, police, 37);
    
    // Si la taille du texte dépasse un certain seuil, on l'affiche sur plusieurs lignes.
    // On incrémente donc un compteur correspondant au numéro de la ligne.
    
    if(texte.getLocalBounds().width > FIN_TEXTE)
    {
        tableau.push_back("");
        
        // On cherche le dernier espace.
        // On vérifie également que ce n'est pas le dernier caractère de la ligne,
        // afin qu'il ne se trouve pas au début de la ligne suivante.
        
        for (int i = (int) ligne.size() - 1; i >= 0; i--)
        {
            if (ligne[i] == ' ' && i < ligne.size() - 1)
            {
                // On envoie les caractères compris entre l'espace et la fin de la ligne à la ligne suivante.
                
                for(int j = i + 1; j < ligne.size() - 1; j++)
                {
                    tableau[compteur + 1] += tableau[compteur][j];
                }
                
                // On efface les caractères qui ont été envoyés à la ligne suivante.
                // Si le dernier caractère est un espace, on ne fait rien.
                
                if(i + 1 < tableau[compteur].size())
                {
                    tableau[compteur].erase(i + 1);
                }
                
                break;
            }
        }
        
        compteur++;
        
        ligne = "";
    }
    
    tableau[compteur] += caractere;
}




// Traitement des phrases puis affichage à l'écran.

void GZoneDeTexte::traitement_des_phrases(string texte, RenderTexture * t)
{    
    texture = t;
    
    // Réinitialisation.
    
    ligne = "";
    
    compteur = 0;
    compteur_structure = 0;
    
    tableau.clear();
    tableau.push_back("");
    
    // On coupe le texte pour qu'il s'affiche sur plusieurs lignes si cela est nécessaire.
    
    for (int i = 0; i < texte.size(); i++)
    {
        texte_multilignes(texte[i]);
    }
    
    // On justifie le texte et on l'affiche sur la texture correspondante.
    
    for (int i = 0; i <= compteur; i++)
    {
        justification_du_texte(tableau[i], i);
        
        affichage_des_phrases(i);
    }
}




// Définie le contour de la zone de texte.

void GZoneDeTexte::definir_contours()
{
    contour.setSize(Vector2f(largeur, hauteur));
    contour.setPosition(position_x, position_y);
    contour.setOutlineColor(Color::Black);
    contour.setOutlineThickness(2);
    contour.setFillColor(Color(255, 255, 255, 0));
}




void GZoneDeTexte::definir_police(Font police_texte)
{
    police = police_texte;
}




// Définie la position de la zone de texte.

void GZoneDeTexte::definir_position(int x, int y)
{
    position_x = x;
    
    position_y = y;
}




// Définie la taille de la zone de texte.

void GZoneDeTexte::definir_taille(int l, int h)
{
    largeur = l;
    
    hauteur = h;
}
