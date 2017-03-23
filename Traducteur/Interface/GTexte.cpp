//
//  Texte.cpp
//  Traducteur
//
//  Created by Grégoire on 22/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "GTexte.hpp"
#include "GZoneTexte.hpp"
#include "ResourcePath.hpp"


using namespace sf;
using namespace std;


double GTexte::numero_de_couleur = 0;


GTexte::GTexte()
{
    _police.loadFromFile(resourcePath() + "GenR102.TTF");
    
    _taille_police = 37;
    
    // Initialisation du texte.
    
    _texte.setFont(_police);
    
    _texte.setCharacterSize(_taille_police);
}




void GTexte::setFont(Font font)
{
    _police = font;
}




void GTexte::setSize(int size)
{
    _taille_police = size;
}




// Affichage de chaque ligne.

void GTexte::displaySentences()
{
    // Affichage des mots.
    
    for (int i = 0; i < _nombre_de_phrases; i++)
    {
        int taille_phrase = 0;

        for (int j = 0; j < __phrases_justifiees[i].size(); j++)
        {
            int taille = 0;
            
            wstring_convert <codecvt_utf8_utf16 <wchar_t>> convertisseur;
            
            wstring w_phrase = convertisseur.from_bytes(__phrases_justifiees[i][j]);
            
            _texte.setString(w_phrase);
            _texte.setColor(Color::Black);
            _texte.setPosition(30 + taille_phrase, 20 + i * 45);

            // Easter egg !
            
            if (__phrases_justifiees[i][j] == "[rainbow]")
            {
                Color couleur[7];
                
                couleur[0] = Color::Color(160, 0, 155);
                couleur[1] = Color::Color(4, 42, 200);
                couleur[2] = Color::Color(0, 140, 255);
                couleur[3] = Color::Color(0, 200, 0);
                couleur[4] = Color::Color(240, 230, 10);
                couleur[5] = Color::Color(236, 135, 0);
                couleur[6] = Color::Red;
                
                _texte.setColor(couleur[(int) numero_de_couleur % 7]);
            }
            
            _texture->draw(_texte);
            
            taille = _texte.getLocalBounds().width;
            
            taille_phrase += taille;
            
            numero_de_couleur += 0.1;
        }
    }
}




// Justification du texte.

void GTexte::justifyText()
{
    string mot;
    
    int nb_espace_a_ajouter = 0;
    
    __phrases_justifiees.clear();
    
    for (int i = 0; i < _nombre_de_phrases; i++)
    {
        __phrases_justifiees.push_back(vector <string> (0));
        
        Text ligne(__phrases[i], _police, _taille_police);
        
        // On calcule la marge comprise entre la fin de la phrase et le seuil.
        // On récupère la taille en pixel du caractère espace.
        // Et on en déduit le nombre d'espace à ajouter.
        
        if (ligne.getLocalBounds().width > 0 && ligne.getLocalBounds().width < 1000 - 50)
        {
            Text espace(' ', _police, _taille_police);
            
            int difference = 1000 - 50 - ligne.getLocalBounds().width;
            
            nb_espace_a_ajouter = difference / (espace.getLocalBounds().width);
        }
        
        // Decoupage de la phrase à chaque espace pour isoler les mots.
        
        istringstream iss(__phrases[i]);
        
        while (getline(iss, mot, ' '))
        {
            __phrases_justifiees[i].push_back(mot + ' ');
        }
        
        if (i < _nombre_de_phrases - 1)
        {
            for (int j = 1; j < nb_espace_a_ajouter; j++)
            {
                __phrases_justifiees[i][j % __phrases_justifiees[i].size()] += ' ';
            }
        }
    }
}




// Construction d'un texte affiché sur plusieurs lignes.

void GTexte::textOnDifferentLines()
{
    string ligne = "";
    
    __phrases.clear();
    
    _nombre_de_phrases = 0;
    
    for (int i = 0; i < _texte_source.size(); i++)
    {
        _texte.setString(ligne);
        
        // Si la taille du texte dépasse un certain seuil, on l'affiche sur plusieurs lignes.

        if(_texte.getLocalBounds().width > 1000 - 50)
        {
            // On cherche le dernier espace.
            // On vérifie également que ce n'est pas le dernier caractère de la ligne,
            // afin qu'il ne se trouve pas au début de la ligne suivante.
            
            for (int i = (int) ligne.size() - 1; i >= 0; i--)
            {
                if (ligne[i] == ' ' && i < ligne.size() - 1)
                {
                    // On sauvegarde la partie qui ne dépasse pas.
                    
                    __phrases.push_back(ligne.substr(0, i));
                    
                    // La nouvelle ligne est formée de ce qui dépasse.
                    
                    ligne = ligne.substr(i + 1);
                    
                    _nombre_de_phrases++;
                    
                    break;
                }
            }
        }
        
        ligne += _texte_source[i];
    }

    _nombre_de_phrases++;
    
    __phrases.push_back(ligne);
}




void GTexte::displayText(RenderTexture & texture, string texte)
{
    _texture = &texture;
    
    _texte_source = texte;
    
    textOnDifferentLines();
    
    justifyText();
    
    displaySentences();
}
