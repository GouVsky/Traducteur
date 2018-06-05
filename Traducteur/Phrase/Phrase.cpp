//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Phrase.hpp"

using namespace std;


Phrase::Phrase(vector <string> mots_source)
{
    __mots_source = mots_source;
}




void Phrase::choix_des_mots_selon_les_champs_lexicaux(vector <Groupe> & groupes, int indice)
{
    size_t nombre_de_familles;
    
    __phrases_sortie_sens_unique.push_back(vector <Mot> ());

    
    // Pour tous les groupes d'une sous-phrase.

    for (int groupe = 0; groupe < groupes.size(); groupe++)
    {
        nombre_de_familles = groupes[groupe].recuperer_nombre_de_familles();
        

        for (int famille = 0; famille < nombre_de_familles; famille++)
        {
            groupes[groupe].recuperer_famille(famille).determiner_mot_dominant(__champs_lexicaux);
        }
        
        // On détermine la famille dominante de chaque groupe.
        // Une famille dominante est celle qui possède le mot dominant le plus dominant.
        
        groupes[groupe].determiner_famille_dominante();
        
        __phrases_sortie_sens_unique[indice].push_back(groupes[groupe].recuperer_famille_dominante().recuperer_mot_dominant());
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




Groupe Phrase::traduire_mot(string mot)
{
    Groupe groupe(mot);
    
    
    size_t nombre_familles = 0;
    
    Parseur parseur(config::fichier_mots);
    
    
    if (parseur.parser(mot, __groupes))
    {
        nombre_familles = parseur.recuperer_donnees_mot().recuperer_nombre_familles(config::langue_sortie);
        
        
        for (int i = 0; i < nombre_familles; i++)
        {
            Famille famille = parseur.recuperer_donnees_mot().recuperer_famille(config::langue_sortie, i);
            
            
            famille.ajouter_type(parseur.recuperer_donnees_mot().recuperer_type(i));
            
            famille.ajouter_champs_lexicaux(parseur.recuperer_donnees_mot().recuperer_champs_lexicaux(config::langue_sortie, i));
            
            incrementer_les_champs_lexicaux(famille);
            
            
            // Si le mot faisait parti d'une forme verbale, on supprime tous les groupes créés précédemment.

            if (famille.recuperer_type().classe() == "VERBE")
            {
                size_t indice = parseur.recuperer_donnees_verbe().recuperer_indice_groupe_debut_verbe();

                __groupes.erase(__groupes.end() - indice, __groupes.end());
            }
            
            
            groupe.ajouter_famille(famille);
        }
    }
    
    // Le mot n'est pas répertorié dans la base de données.
    
    else
    {
        Famille inconnue(mot);
        
        groupe.ajouter_famille(inconnue);
    }
    
    
    return groupe;
}




void Phrase::traduire()
{
    size_t nombre_mots = __mots_source.size();
    
    
    for (int i = 0; i < nombre_mots; i++)
    {
        
        
        __groupes.push_back(traduire_mot(__mots_source[i]));
    }
    
    __phrases_sortie_plusieurs_sens.push_back(__groupes);
    
    
    // On sélectionne la traduction correcte des mots possédant plusieurs significations.
    
    size_t nombre_sous_phrases = __phrases_sortie_plusieurs_sens.size();
    
    for (int i = 0; i < nombre_sous_phrases; i++)
    {
        choix_des_mots_selon_les_champs_lexicaux(__phrases_sortie_plusieurs_sens[i], i);
    }
}
