//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string phrase_traduite, string langue_source, string langue_sortie)
{
    _traduite = true;
    
    _phrase_sortie = phrase_traduite;
    
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




Phrase::Phrase(vector <string> mots_source, string langue_source, string langue_sortie)
{
    _traduite = false;
    
    __mots_source = mots_source;
    
    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




void Phrase::choix_des_mots_selon_les_champs_lexicaux(vector <Groupe> & groupes, int indice)
{
    string mots;

    int max = -1,
        valeur_champ_lexical = -1;
    
    size_t nombre_de_sens,
           nombre_de_familles;
    
    __sous_phrases_sorties.push_back(vector <Mot> ());

    
    // Pour toutes les groupes d'une sous-phrase.

    for (int i = 0; i < groupes.size(); i++)
    {
        nombre_de_familles = groupes[i].recuperer_nombre_de_familles();
        
        // Le mot est inconnu s'il n'y a pas de famille.
        
        if (nombre_de_familles == 0)
        {
            Mot mot_inconnu(groupes[i].recuperer_mot_source());
            
            __sous_phrases_sorties[indice].push_back(mot_inconnu);
        }
        
        else
        {
            // Pour chaque famille.
            
            for (int j = 0; j < nombre_de_familles; j++)
            {
                // Pour chaque sens.
                
                nombre_de_sens = groupes[i].recuperer_famille(j).recuperer_nombre_de_sens_sortie();
                
                for (int k = 0; k < nombre_de_sens; k++)
                {
                    Mot & mot = groupes[i].recuperer_famille(j).recuperer_mots()[k];
                    
                    
                    // On récupère le champ lexical dominant de la phrase.
                    // On n'effectue pas cela entre tous les champs lexicaux, mais seulement entre ceux qui sont communs avec le mot.
                    
                    valeur_champ_lexical = __champs_lexicaux.recuperation_plus_grand_champ_lexical_commun(mot.recuperer_champs_lexicaux()).first;
                    
                    if (valeur_champ_lexical > max)
                    {
                        max = valeur_champ_lexical;
                        
                        mots = mot.recuperer_mot();
                    }
                    
                    else if (valeur_champ_lexical == max)
                    {
                        mots += '/' + mot.recuperer_mot();
                    }
                }
            }
            
            Mot mot(mots);
            
            __sous_phrases_sorties[indice].push_back(mot);
            
            
            max = -1;
            
            mots = "";
        }
    }
}




void Phrase::incrementer_les_champs_lexicaux(Famille & famille)
{
    size_t nombre_de_sens = famille.recuperer_nombre_de_sens_sortie();
    
    for (int i = 0; i < nombre_de_sens; i++)
    {
        __champs_lexicaux = __champs_lexicaux + famille.recuperer_mots()[i].recuperer_champs_lexicaux();
    }
}




Groupe Phrase::traduction(string mot)
{
    Groupe groupe(mot);
    
    
    size_t nombre_familles = 0;
    
    Parseur parseur(_langue_source, _langue_sortie, "./Resources/Dictionnaire/mots.txt");
    
    
    if (parseur.parser(mot, __groupes))
    {
        nombre_familles = parseur.recuperer_donnees().recuperer_nombre_familles(_langue_sortie);
    }
    
    for (int i = 0; i < nombre_familles; i++)
    {
        Famille famille = parseur.recuperer_donnees().recuperer_famille(_langue_sortie, i);
        
        
        incrementer_les_champs_lexicaux(famille);
        
        groupe.ajouter_famille(famille);
    }
    
    return groupe;
}




void Phrase::construire_les_sous_phrases()
{
    string mot,
           phrase;
    
    
    for (int i = 0; i < __mots_source.size(); i++)
    {
        string mot = __mots_source[i];
        
        
        // Il y a la présence d'une virgule, on l'enlève temporairement.
        
        if (mot[mot.size() - 1] == ',')
        {
            mot.erase(mot.size() - 1);
        }
        
        __groupes.push_back(traduction(mot));
    }
    
    __sous_phrases_sources.push_back(__groupes);
}




void Phrase::construire_la_phrase()
{
    if (!_traduite)
    {
        construire_les_sous_phrases();
        
        for (int i = 0; i < __sous_phrases_sources.size(); i++)
        {
            choix_des_mots_selon_les_champs_lexicaux(__sous_phrases_sources[i], i);
        }
        
        // Construction de la phrase finale traduite.
        
        for (int i = 0; i < __sous_phrases_sorties.size(); i++)
        {
            for (int j = 0; j < __sous_phrases_sorties[i].size(); j++)
            {
                _phrase_sortie += __sous_phrases_sorties[i][j].recuperer_mot() + ' ';
            }
        }
        
        _phrase_sortie.erase(_phrase_sortie.size() - 1);
    }
}
