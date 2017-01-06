//
//  champTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "champTexte.hpp"

using namespace sf;
using namespace std;

#define DEBUT_TEXTE 40
#define FIN_TEXTE 970


void ChampTexte::easter_egg(RenderTexture * texture, Text texte, string mot, int indice_ligne)
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

void ChampTexte::affichage_des_phrases(RenderTexture &texture, vector <string> t_justification, int indice_ligne)
{
    taille_phrase = 0;
    
    // Affichage des mots.
    
    for(int i = 0; i < t_justification.size(); i++)
    {
        taille = 0;
                
        texte.setFont(police);
        texte.setCharacterSize(37);
        texte.setColor(Color::Black);
        texte.setString(t_justification[i]);
        
        // Si l'utilisateur a activé l'easter egg.
        
        if(t_justification[i].find("[rainbow]") != -1)
        {
            easter_egg(&texture, texte, t_justification[i], indice_ligne);
        }
        
        else
        {
            // Les mots non répertoriés dans la base de données sont affichés en rouge.
            
            if(type_texte == "sortie" && structure[compteur_structure] == "inconnu_1")
            {
                texte.setColor(Color::Red);
            }
            
            texte.setPosition(DEBUT_TEXTE + taille_phrase, 200 + indice_ligne * 45);
            
            texture.draw(texte);
            
            taille = texte.getLocalBounds().width;
        }
        
        taille_phrase += taille;
        
        compteur_structure++;
    }
}




// Justification du texte.

vector <string> ChampTexte::justification_du_texte(string phrase, int indice)
{
    string mot = "";
    vector <string> t_mots;
    int nb_espace_a_ajouter = 0;
    
    Text ligne(phrase, police, 37);
    
    // On calcule la marge comprise entre la fin de la phrase et le seuil.
    // On récupère la taille en pixel du caractère espace.
    // Et on en déduit le nombre d'espace à ajouter.
    
    if(ligne.getLocalBounds().width > 0 && ligne.getLocalBounds().width < FIN_TEXTE)
    {
        Text espace(' ', police, 37);
        
        int difference = FIN_TEXTE - ligne.getLocalBounds().width;
        
        nb_espace_a_ajouter = difference / (espace.getLocalBounds().width);
    }
    
    // Decoupage de la phrase à chaque espace pour isoler les mots.
    
    for(int i = 0; i < phrase.size(); i++)
    {
        if(phrase[i] == ' ' || i == phrase.size() - 1)
        {
            t_mots.push_back(mot + phrase[i]);
            
            mot = "";
        }
        
        else
        {
            mot += phrase[i];
        }
    }
    
    // On ajoute un espace entre chaque mot jusqu'à atteindre le seuil.
    // La dernière ligne n'est justifiée que si elle est suffisamment grande.
    
    if(indice < compteur || (indice == compteur && ligne.getLocalBounds().width > FIN_TEXTE - 20))
    {
        for(int i = 1; i < nb_espace_a_ajouter; i++)
        {
            t_mots[i % (t_mots.size() - 1)] += ' ';
        }
    }
    
    return t_mots;
}




// Construction d'un texte affiché sur plusieurs lignes.

void ChampTexte::texte_multilignes(char caractere)
{
    ligne = tableau[compteur];
    ligne += caractere;
    
    Text texte(ligne, police, 37);
    
    // Si la taille du texte dépasse un certain seuil, on l'affiche sur plusieurs lignes.
    // On incrémente donc un compteur correspondant au numéro de la ligne.
    
    if(texte.getLocalBounds().width > FIN_TEXTE)
    {
        tableau.push_back("");

        // On cherche le dernier espace.
        // On vérifie également que ce n'est pas le dernier caractère de la ligne,
        // afin qu'il ne se trouve pas au début de la ligne suivante.
        
        for(int i = (int) ligne.size() - 1; i >= 0; i--)
        {
            if(ligne[i] == ' ' && i < ligne.size() - 1)
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

vector <string> ChampTexte::traitement_des_phrases(Font police_texte, string type, string texte, RenderTexture * texture, std::vector <std::string> structure_texte)
{
    type_texte = type;

    police = police_texte;
    
    structure = structure_texte;
    
    // Réinitialisation.
    
    ligne = "";
    
    compteur = 0;
    compteur_structure = 0;
    
    tableau.clear();
    tableau.push_back("");
    
    texture->clear(Color::White);
    
    // On coupe le texte pour qu'il s'affiche sur plusieurs lignes si cela est nécessaire.
    
    for (int i = 0; i < texte.size(); i++)
    {
        texte_multilignes(texte[i]);
    }
    
    // On justifie le texte et on l'affiche sur la texture correspondante.
    
    for (int i = 0; i <= compteur; i++)
    {        
        vector <string> t_justification = justification_du_texte(tableau[i], i);
        
        affichage_des_phrases(* texture, t_justification, i);
    }
    
    return tableau;
}
