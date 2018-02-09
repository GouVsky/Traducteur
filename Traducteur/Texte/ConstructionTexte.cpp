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
}




// Découpe les phrases à chaque conjonction de coordination si elles existent.

void Texte::recherche_conjonction_coordination(vector <string> tableau)
{
    bool conjonction = false;
    
    vector <string> mots_source;
    
    vector <string> cc_a = {"but", "where", "so", "because", "when", "if"};
    vector <string> cc_f = {"mais", "où", "donc", "or", "ni", "car", "parce-que", "quand"};
    
    __conjonction_coordination["A"] = cc_a;
    __conjonction_coordination["F"] = cc_f;
    
    
    for (int i = 0; i < tableau.size(); i++)
    {
        // On cherche si le mot est une conjonction de coordination ou non.
        
        for (int j = 0; j < __conjonction_coordination[_langue_source].size(); j++)
        {
            if (tableau[i] == __conjonction_coordination[_langue_source][j])
            {
                conjonction = true;
                
                break;
            }
        }
        
        mots_source.push_back(tableau[i]);
        
        
        // Chaque portion de la phrase comprise entre :
        //
        // - le début et une conjonction
        // - deux conjonctions
        // - une conjonction et la fin
        
        // est considérée comme étant une sous-phrase indépendante des autres.
        
        if (conjonction == true || i == (int) tableau.size() - 1)
        {
            // Ajout d'une nouvelle phrase.
            
            Phrase phrase(mots_source, _langue_source, _langue_sortie);
            
            __phrase.push_back(phrase);
            
            
            if (conjonction == true)
            {
                __ponctuation.push_back(0);
            }
            
            conjonction = !conjonction;
                        
            mots_source.clear();
        }
    }
}




bool Texte::recherche_expression(vector <string> mots)
{
    bool expression = false;
    
    ifstream monFichierExpressions("./Resources/Dictionnaire/expressions.txt");
    
    
    while (!monFichierExpressions.eof())
    {
        monFichierExpressions >> __expression["A"] >> __expression["F"];
        
        
        int taille_expression = (int) count(__expression[_langue_source].begin(), __expression[_langue_source].end(), ';');
        
        string expression_de_la_phrase;
        
        // Comparaison de l'expression avec celle de la phrase.
        
        for (int i = 0; i < min(taille_expression, (int) (mots.size())); i++)
        {
            expression_de_la_phrase += mots[i] + ';';
        }
        
        
        if (expression_de_la_phrase == __expression[_langue_source])
        {
            expression = true;
            
            replace(__expression[_langue_sortie].begin(), __expression[_langue_sortie].end(), ';', ' ');
            
            Phrase phrase(__expression[_langue_sortie], _langue_source, _langue_sortie);
            
            __phrase.push_back(phrase);
            
            break;
        }
    }
    
    monFichierExpressions.close();
    
    return expression;
}




// Séparation du texte en plusieurs phrases selon la ponctuation.

void Texte::decouper_en_phrases(string texte)
{
    vector <string> mots;
    
    string mot = "",
           phrase = "";
    

    // On récupère le texte caractère par caractère.

    for (int i = 0; i < texte.size(); i++)
    {
        // On découpe le texte à chaque ponctuation.

        if (texte[i] == '.' || texte[i] == '!' || texte[i] == '?' || texte[i] == ';' || texte[i] == ':' || texte[i] == '\0')
        {
            transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
            
            // On isole chaque mot constituant la phrase.
            
            istringstream iss(phrase);
            
            while (getline(iss, mot, ' '))
            {
                mots.push_back(mot);
            }

            if (!recherche_expression(mots))
            {
                recherche_conjonction_coordination(mots);
            }
            
            // On ajoute la ponctuation.
            
            __ponctuation.push_back(texte[i]);
            
            // S'il existe, et tant qu'il est présent,
            // on saute le caractère espace situé entre la ponctuation et la première lettre du mot suivant.
            
            while (texte[i + 1] == ' ')
            {
                i++;
            }
            
            
            phrase = "";
            mots.clear();
        }
        
        else
        {
            phrase += texte[i];
        }
    }
}




// Découpe le texte en plusieurs phrases.

void Texte::construire_texte(string texte)
{
    vector <thread> phrases;
    

    decouper_en_phrases(texte);

    // Création d'un thread par phrase.
    
    size_t nombre_de_phrases = __phrase.size();
    

    for (int i = 0; i < nombre_de_phrases; i++)
    {
        phrases.push_back(thread(&Phrase::construire_la_phrase, &__phrase[i]));
    }
    
    for (int i = 0; i < nombre_de_phrases; i++)
    {
        phrases[i].join();
    }

    // On assemble les phrases.
    
    for (int i = 0; i < nombre_de_phrases; i++)
    {
        _texte_traduit += __phrase[i].recuperer_phrase_traduite() + __ponctuation[i] + ' ';
    }

    _texte_traduit.erase(_texte_traduit.size() - 1);
}
