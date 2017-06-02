//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(vector <string> mots_source, string langue_source, string langue_sortie)
{
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
                    Mot & mot = groupes[i].recuperer_famille(j).recuperer_sens_sortie(k);
                    
                    
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
        __champs_lexicaux = __champs_lexicaux + famille.recuperer_sens_sortie(i).recuperer_champs_lexicaux();
    }
}




Groupe Phrase::traduction(string mot)
{
    Groupe groupe(mot);

    
    // Initialisation des différents parseurs.
    
    ParseurExpression parseur_expression(_langue_source, _langue_sortie);
    
    PronomPersonnel pronom_personnel(_langue_source, _langue_sortie);
    
    Parseur parseur(_langue_source, _langue_sortie);
    
    ParseurVerbe parseur_verbe(_langue_source, _langue_sortie);

    
    
    // On recherche s'il existe une expression.
    
    if (parseur_expression.parser_fichier(mot, __groupes))
    {
        Famille famille;
        
        famille.ajouter_sens_sortie(parseur_expression.recuperer_expression());
        
        groupe.ajouter_famille(famille);
    }

    // On recherche s'il existe un pronom personnel.

    else if (pronom_personnel.le_mot_est_un_pronom_personnel(mot))
    {
        Famille famille;
        
        famille.ajouter_sens_sortie(pronom_personnel.recuperer_pronom_personnel());
        
        groupe.ajouter_famille(famille);
    }
    
    // On recherche les différents mots.

    else
    {
        size_t nombre_fichiers = parseur.recuperer_nombre_fichiers();
        
        
        for (int i = 0; i < nombre_fichiers; i++)
        {
            if (parseur.parser_fichier(parseur.recuperer_fichier(i), mot))
            {
                Famille famille;
                
                famille.ajouter_sens_sortie(parseur.recuperer_sens_sortie());
                
                famille.definir_les_champs_lexicaux_des_mots(parseur.recuperer_champs_lexicaux());
                
                incrementer_les_champs_lexicaux(famille);
                
                groupe.ajouter_famille(famille);
            }
        }
        
        // On étudie le cas des verbes à part.
        
        if (parseur_verbe.parser_fichier(mot, __groupes))
        {
            Famille famille;
            
            famille.ajouter_sens_sortie(parseur_verbe.recuperer_verbes_sortie());
            
            famille.definir_les_champs_lexicaux_des_mots(parseur_verbe.recuperer_champs_lexicaux());
            
            incrementer_les_champs_lexicaux(famille);
            
            groupe.ajouter_famille(famille);
        }
    }
    
    return groupe;
}




void Phrase::construire_les_sous_phrases()
{
    string mot,
           phrase;
    
    
    for (int i = 0; i < __mots_source.size(); i++)
    {
        char ponctuation = '\0';

        string mot = __mots_source[i];
        
        
        // Il y a la présence d'une virgule, on l'enlève temporairement.
        
        if (mot[mot.size() - 1] == ',')
        {
            mot.erase(mot.size() - 1);
            
            ponctuation = ',';
        }
        
        __groupes.push_back(traduction(mot));
    }
    
    __sous_phrases_sources.push_back(__groupes);
}




void Phrase::construire_la_phrase()
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
