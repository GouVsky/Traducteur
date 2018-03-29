//
//  ConstructionTexte.cpp
//  Traducteur
//
//  Created by Grégoire on 17/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "ConstructeurPhrase.hpp"

using namespace std;


ConstructeurPhrase::ConstructeurPhrase(string source, string sortie) : constructeur_expression(source, sortie)
{
    _langue_source = source;
    
    _langue_sortie = sortie;
}




void ConstructeurPhrase::assembler_sous_phrases_traduites(size_t nombre_phrases)
{
    size_t nombre_mots,
           nombre_sous_phrases;
    
    string phrase_assemblee;
    
    
    for (int phrase = 0; phrase < nombre_phrases; phrase++)
    {
        // On récupère les sous-phrases de chaque phrase.
        
        nombre_sous_phrases = __phrases[phrase].recuperer_nombre_sous_phrases();
        
        
        for (int sous_phrase = 0; sous_phrase < nombre_sous_phrases; sous_phrase++)
        {
            nombre_mots = __phrases[phrase].recuperer_nombre_mots(sous_phrase);
            
            
            for (int mot = 0; mot < nombre_mots; mot++)
            {
                phrase_assemblee += ' ' + __phrases[phrase].recuperer_mot(sous_phrase, mot).recuperer_mot();
            }
        }
        
        phrase_assemblee += __ponctuation[phrase];
        
        // On efface le caractère espace du début.
        
        phrase_assemblee.erase(0, 1);
        
        __phrases_sorties.push_back(phrase_assemblee);
        
        phrase_assemblee = "";
    }
}




void ConstructeurPhrase::traduction_multithreading(size_t nombre_phrases)
{
    vector <thread> phrases_traduites;

    
    for (int i = 0; i < nombre_phrases; i++)
    {
        phrases_traduites.push_back(thread(&Phrase::traduire, &__phrases[i]));
    }
    
    for (int i = 0; i < nombre_phrases; i++)
    {
        phrases_traduites[i].join();
    }
}




Phrase ConstructeurPhrase::decouper_en_mots(string phrase)
{
    string mot;
    
    istringstream chaine(phrase);

    
    // Suppression de la casse de la phrase pour les traitements.
    
    transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
    
    
    vector <string> mots;
    
    while (getline(chaine, mot, ' '))
    {
        mots.push_back(mot);
    }
    
    return Phrase(mots, _langue_source, _langue_sortie);
}




void ConstructeurPhrase::decouper_par_ponctuation(string texte)
{
    string phrase;
    
    
    for (int i = 0; i < texte.size(); i++)
    {
        // On découpe le texte à chaque ponctuation.
        
        if (texte[i] == '.' || texte[i] == '!' || texte[i] == '?' || texte[i] == ';' || texte[i] == ':' || texte[i] == '\0')
        {
            __phrases_sources.push_back(phrase);
            
            // On sauvegarde la ponctuation.
            
            __ponctuation.push_back(texte[i]);
            
            // On saute tous les caractères blancs situés entre la ponctuation et le mot suivant.
            
            while (texte[i + 1] == ' ')
            {
                i++;
            }
            
            phrase = "";
        }
        
        else
        {
            phrase += texte[i];
        }
    }
}




void ConstructeurPhrase::construire_phrases(string texte)
{
    size_t nombre_phrases;
    
    
    decouper_par_ponctuation(texte);
    
    
    nombre_phrases = __phrases_sources.size();
    
    
    for (int i = 0; i < nombre_phrases; i++)
    {
        __phrases.push_back(decouper_en_mots(__phrases_sources[i]));
    }
    
    
    traduction_multithreading(nombre_phrases);
    
    assembler_sous_phrases_traduites(nombre_phrases);
}
