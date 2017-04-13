//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string phrase, string langue_source, string langue_sortie)
{
    _phrase_source = phrase;

    _langue_source = langue_source;
    _langue_sortie = langue_sortie;
}




void Phrase::choix_des_mots_selon_les_champs_lexicaux(int numero_sous_phrase)
{
    int max = -1,
        valeur_champ_lexical = -1,
        max_valeur_champ_lexical = -1;
    
    int nombre_de_sens,
        nombre_de_familles,
        nombre_de_champs_lexicaux;
    
    string mots;
    
    
    // Pour toutes les groupes.
    
    for (int i = 0; i < __sous_phrases_sources[numero_sous_phrase].size(); i++)
    {
        // Pour chaque famille.
        
        nombre_de_familles = __sous_phrases_sources[numero_sous_phrase][i].recuperer_nombre_de_familles();
        
        // Le mot est inconnu s'il n'y a pas de famille.
        
        if (nombre_de_familles == 0)
        {
            __sous_phrases_sorties.push_back(__sous_phrases_sources[numero_sous_phrase][i].recuperer_mot_source());
        }
        
        for (int j = 0; j < nombre_de_familles; j++)
        {
            // Pour chaque sens.
            
            nombre_de_sens = __sous_phrases_sources[numero_sous_phrase][i].recuperer_famille(j).recuperer_nombre_de_sens_sortie();
            
            for (int k = 0; k < nombre_de_sens; k++)
            {
                Mot mot = __sous_phrases_sources[numero_sous_phrase][i].recuperer_famille(j).recuperer_sens_sortie(k);
                
                // Pour chaque champ lexical.
                
                nombre_de_champs_lexicaux = mot.recuperer_nombre_de_champs_lexicaux();
                
                for (int l = 0; l < nombre_de_champs_lexicaux; l++)
                {
                    string champ_lexical = mot.recuperer_champs_lexicaux(l);
                    
                    // On récupère la plus grande valeur parmi tous les champs lexicaux associés à un sens du mot.
                    
                    valeur_champ_lexical = __champs_lexicaux.recuperation_valeur_champ_lexical(champ_lexical);
                    
                    if (valeur_champ_lexical > max_valeur_champ_lexical)
                    {
                        max_valeur_champ_lexical = valeur_champ_lexical;
                    }
                }

                // Puis, entre tous les sens, on choisit celui dont le champ lexical associé est le plus répandu.
                // Si plusieurs valeurs sont identiques, on les affiche tous.
                
                if (max_valeur_champ_lexical > max)
                {
                    max = max_valeur_champ_lexical;
                    
                    mots = mot.recuperer_mot();
                }
                
                else if (max_valeur_champ_lexical == max)
                {
                    mots += '/' + mot.recuperer_mot();
                }
                
                max_valeur_champ_lexical = -1;
            }
        }
        
        __sous_phrases_sorties.push_back(mots);
        
        max = -1;
        
        mots = "";
    }
}




void Phrase::incrementer_les_champs_lexicaux(Famille & famille)
{
    int nombre_de_sens = famille.recuperer_nombre_de_sens_sortie();
    
    for (int i = 0; i < nombre_de_sens; i++)
    {
        int nombre_de_champs_lexicaux_par_mot = famille.recuperer_sens_sortie(i).recuperer_nombre_de_champs_lexicaux();
        
        for (int j = 0; j < nombre_de_champs_lexicaux_par_mot; j++)
        {
            __champs_lexicaux.incrementation_des_champs_lexicaux(famille.recuperer_sens_sortie(i).recuperer_champs_lexicaux(j));
        }
    }
}




Groupe Phrase::traduction(string mot)
{
    Groupe groupe(mot);
    
    Parseur parseur(_langue_source, _langue_sortie);
    ParseurVerbe parseur_verbe(_langue_source, _langue_sortie);
    
    
    int nombre_fichiers = parseur.recuperer_nombre_fichiers();
    
    
    for (int i = 0; i < nombre_fichiers; i++)
    {
        parseur.parser_fichier(parseur.recuperer_fichier(i), mot);

        if (parseur.le_mot_est_present_dans_fichier())
        {
            // Création d'une nouvelle famille de mots.
            
            Famille famille;
            
            famille.definir_les_differents_sens_sortie(parseur.recuperer_sens_sortie());
            
            famille.definir_les_champs_lexicaux_des_mots(parseur.recuperer_champs_lexicaux());
            
            famille.definir_le_type(i);
            
            incrementer_les_champs_lexicaux(famille);
            
            // Ajout de la famille dans le groupe.
            
            groupe.ajouter_famille(famille);
        }
    }
    
    
    
    // On étudie le cas des verbes à part.
    
    parseur_verbe.parser_fichier(mot, __groupes);
    
    if (parseur_verbe.le_verbe_est_present())
    {
        // Création d'une nouvelle famille de mots.
        
        Famille famille;
        
        famille.definir_les_differents_sens_sortie(parseur_verbe.recuperer_verbes_sortie());
        
        famille.definir_les_champs_lexicaux_des_mots(parseur_verbe.recuperer_champs_lexicaux());
        
        incrementer_les_champs_lexicaux(famille);
        
        // Ajout de la famille dans le groupe.
        
        groupe.ajouter_famille(famille);
    }
    
    return groupe;
}




void Phrase::construire_les_sous_phrases()
{
    string mot,
           phrase;
    
    istringstream flux(_phrase_source);

    while (getline(flux, phrase, ','))
    {
        istringstream flux_traduction(phrase);
        
        while (getline(flux_traduction, mot, ' '))
        {
            __groupes.push_back(traduction(mot));
        }
        
        // Si un verbe est présent dans un des groupes,
        // On considère qu'il s'agit d'une sous-phrase.
        
        /* if (un verbe)
        {
            __sous_phrases.push_back(__groupes);
        }
        
        else
        {
            
        } */
        
        __sous_phrases_sources.push_back(__groupes);
        
        __groupes.clear();
    }

    __sous_phrases_sources.push_back(__groupes);
}




void Phrase::construire_la_phrase()
{
    construire_les_sous_phrases();
    
    for (int i = 0; i < __sous_phrases_sources.size(); i++)
    {
        choix_des_mots_selon_les_champs_lexicaux(i);
        
        for (int j = 0; j < __sous_phrases_sorties.size(); j++)
        {
            _phrase_sortie += __sous_phrases_sorties[j] + ' ';
        }
        
        __sous_phrases_sorties.clear();
    }
    
    _phrase_sortie.erase(_phrase_sortie.size() - 1);
}
