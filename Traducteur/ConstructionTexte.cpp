//
//  ConstructionTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 17/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ConstructionTexte.hpp"

using namespace std;


Texte::Texte(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _nombre_de_phrases = 0;
}




// Retourne le texte traduit.

string Texte::recuperer_texte_traduit()
{
    return _texte_traduit;
}




// Assemble les phrases traduites.

void Texte::assembler_les_phrases()
{
    if (_nombre_de_phrases > 0)
    {
        for (int i = 0; i < _nombre_de_phrases; i++)
        {
            _texte_traduit += _phrase[i].recuperer_phrase() + _ponctuation[i] + ' ';
        }
        
        // On efface le dernier espace.
        
        _texte_traduit.erase(_texte_traduit.size() - 1);
    }
}




// Découpe les phrases à chaque conjonction de coordination si elles existent.

void Texte::recherche_conjonction_coordination(vector <string> tableau)
{
    string phrase_tmp = "";
    bool conjonction = false;
    
    string cc_a[6] = {"but", "where", "so", "because", "when", "if"};
    string cc_f[8] = {"mais", "où", "donc", "or", "ni", "car", "parce-que", "quand"};
    
    _conjonction_coordination["A"] = cc_a;
    _conjonction_coordination["F"] = cc_f;
    
    for (int i = 0; i < tableau.size(); i++)
    {
        // On cherche si le mot est une conjonction de coordination ou non.
        
        for (int j = sizeof(_conjonction_coordination[_langue_source]) / sizeof(* _conjonction_coordination[_langue_source]); j--;)
        {
            if (tableau[i] == _conjonction_coordination[_langue_source][j])
            {
                conjonction = true;
                
                break;
            }
        }
        
        phrase_tmp += tableau[i] + ' ';
        
        // Chaque portion de la phrase comprise entre :
        //
        // - le début et une conjonction
        // - deux conjonctions
        // - une conjonction et la fin
        
        // est considérée comme étant une sous-phrase indépendante des autres.
        
        if (conjonction == true || i == (int) tableau.size() - 1)
        {
            phrase_tmp.erase(phrase_tmp.size() - 1);
            
            // Ajout d'une nouvelle phrase.
            
            Phrase phrase(_langue_source, _langue_sortie, phrase_tmp);
            
            _phrase.push_back(phrase);
            
            _nombre_de_phrases++;
            
            if (conjonction == true)
            {
                _ponctuation.push_back(0);
            }
            
            conjonction = !conjonction;
            
            phrase_tmp = "";
        }
    }
}




// Séparation du texte en plusieurs phrases selon la ponctuation.

void Texte::recherche_de_la_ponctuation(string t)
{
    vector <string> tableau;
    string mot = "", phrase = "";

    // On récupère le texte caractère par caractère.
    
    for (int i = 0; i < t.size(); i++)
    {
        // On découpe le texte à chaque ponctuation.
        
        if (t[i] == '.' || t[i] == '!' || t[i] == '?' || t[i] == ';' || t[i] == ':' || t[i] == '\0')
        {
            transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
            
            // On isole chaque mot constituant la phrase.
            
            istringstream iss(phrase);
            
            while (getline(iss, mot, ' '))
            {
                tableau.push_back(mot);
            }
            
            recherche_conjonction_coordination(tableau);
            
            // On ajoute la ponctuation.
            
            _ponctuation.push_back(t[i]);
            
            // S'il existe, et tant qu'il est présent,
            // on saute le caractère espace situé entre la ponctuation et la première lettre du mot suivant.
            
            while (t[i + 1] == ' ')
            {
                i++;
            }
            
            // Réinitialisation.
            
            phrase = "";
            tableau.clear();
        }
        
        else
        {
            phrase += t[i];
        }
    }
}




// Découpe le texte en plusieurs phrases.

void Texte::construction_du_texte(string texte)
{
    vector <thread> phrases;

    recherche_de_la_ponctuation(texte);
    
    // Création d'un thread par phrase.
    
    for (int i = 0; i < _nombre_de_phrases; i++)
    {
        phrases.push_back(thread(&Phrase::recherche_virgule, &_phrase[i]));
    }
    
    for (int i = 0; i < _nombre_de_phrases; i++)
    {
        phrases[i].join();
    }
    
    for (int i = 0; i < _nombre_de_phrases; i++)
    {
        _phrase[i].choix_des_mots_selon_champ_lexical();
    }
    
    assembler_les_phrases();
}