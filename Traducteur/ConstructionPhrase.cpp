//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string source, string sortie, string texte)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _phrase_source = texte;
    
    _presence_verbe = false;
    
    _indice_sous_phrase = 0;
}




void Phrase::incrementer_champ_lexical(Famille & famille)
{
    int nombre_de_sens = famille.recuperer_nombre_de_sens_sortie();
    
    for (int i = 0; i < nombre_de_sens; i++)
    {
        int nombre_de_champs_lexicaux_par_mot = famille.recuperer_sens_sortie(i).recuperer_nombre_de_champs_lexicaux();
        
        for (int j = 0; j < nombre_de_champs_lexicaux_par_mot; j++)
        {
            __champ_lexical.incrementation_des_champs_lexicaux(famille.recuperer_sens_sortie(i).recuperer_champs_lexicaux(j));
        }
    }
}




// Choix du mot approprié s'il possède plusieurs sens possibles.

void Phrase::choix_des_mots_selon_champ_lexical()
{
    int max = -1,
        valeur_champ_lexical = 0,
        max_valeur_champ_lexical = 0;
    
    int nombre_de_familles,
        nombre_de_sens,
        nombre_de_champs_lexicaux;
    
    
    // Pour toutes les sous-phrases.
    
    for (int i = 0; i < __mots.size(); i++)
    {
        // Pour toutes les groupes.

        for (int j = 0; j < __mots[i].size(); j++)
        {
            __phrase.push_back(vector <string> ());

            
            // Pour chaque famille.

            nombre_de_familles = __mots[i][j].recuperer_nombre_de_familles();
            
            // Le mot est inconnu s'il n'y a pas de famille.
            
            if (nombre_de_familles == 0)
            {
                __phrase[__phrase.size() - 1].push_back(__mots[i][j].recuperer_mot_source());
            }
            
            for (int k = 0; k < nombre_de_familles; k++)
            {
                // Pour chaque sens.
                
                nombre_de_sens = __mots[i][j].recuperer_famille(k).recuperer_nombre_de_sens_sortie();
                
                for (int l = 0; l < nombre_de_sens; l++)
                {
                    Mot mot_tmp = __mots[i][j].recuperer_famille(k).recuperer_sens_sortie(l);
                    
                    // Pour chaque champ lexical.
                    
                    nombre_de_champs_lexicaux = mot_tmp.recuperer_nombre_de_champs_lexicaux();
                    
                    for (int m = 0; m < nombre_de_champs_lexicaux; m++)
                    {
                        string champ_lexical = mot_tmp.recuperer_champs_lexicaux(m);
                        
                        // On récupère la plus grande valeur parmi tous les champs lexicaux associés à un sens du mot.
                        
                        valeur_champ_lexical = __champ_lexical.recuperation_valeur_champ_lexical(champ_lexical);
                        
                        if (valeur_champ_lexical > max_valeur_champ_lexical)
                        {
                            max_valeur_champ_lexical = valeur_champ_lexical;
                        }
                    }
                    
                    // Puis, entre toutes les significations, on choisit la signification dont le champ lexical associé est le plus répandu.
                    // Si plusieurs valeurs sont identiques, on les affiche toutes.
                    
                    if (max_valeur_champ_lexical > max)
                    {
                        max = max_valeur_champ_lexical;
                        
                        __phrase[__phrase.size() - 1].clear();
                        __phrase[__phrase.size() - 1].push_back(mot_tmp.recuperer_mot());
                    }
                    
                    else if (max_valeur_champ_lexical == max)
                    {
                        __phrase[__phrase.size() - 1].push_back(mot_tmp.recuperer_mot());
                    }
                    
                    max_valeur_champ_lexical = -1;
                }
            }
            
            max = -1;
        }
    }
}




// Traduction des mots selon leur nature (noms, verbes, adjectifs, expressions...).

void Phrase::traduction_des_mots(vector <string> phrase, bool virgule)
{
    vector <string> fichiers = {"adjectifs.txt",
                                "invariables.txt",
                                "noms_feminins.txt",
                                "noms_masculins.txt",
                                "noms_propres_feminins.txt",
                                "noms_propres_masculins.txt"};
    
    
    for (int i = 0; i < phrase.size(); i++)
    {
        Groupe groupe(phrase[i]);
        
        
        Parseur parseur(_langue_source, _langue_sortie);
        ParseurVerbe parseur_verbe(_langue_source, _langue_sortie);
        

        int nombre_fichiers = fichiers.size();
        
        for (int j = 0; j < nombre_fichiers; j++)
        {
            parseur.parser_fichier(fichiers[j], phrase[i]);
            
            if (parseur.le_mot_est_present_dans_fichier())
            {                
                // Création d'une nouvelle famille de mots.
                
                Famille famille;
                
                famille.definir_les_differents_sens_sortie(parseur.recuperer_sens_sortie());
                
                famille.definir_les_champs_lexicaux_des_mots(parseur.recuperer_champs_lexicaux());
                
                famille.definir_le_type(j);
                
                incrementer_champ_lexical(famille);
                
                // Ajout de la famille dans le groupe.
                
                groupe.ajouter_famille(famille);
            }
        }
        
        
        // Le cas des verbes est plus complexe, on l'étudie à part.

        parseur_verbe.parser_fichier(i, phrase);

        if (parseur_verbe.le_verbe_est_present())
        {
            Famille famille;
            
            famille.definir_les_differents_sens_sortie(parseur_verbe.recuperer_verbes_sortie());
            
            famille.definir_les_champs_lexicaux_des_mots(parseur_verbe.recuperer_champs_lexicaux());
            
            famille.definir_le_type(6);
            
            incrementer_champ_lexical(famille);
            
            // Ajout de la famille dans le groupe.
            
            groupe.ajouter_famille(famille);
            
            // On saute le verbe.
            
            i += 0;
        }
        
        
        // On ajoute le groupe.
        
        __mots[_indice_sous_phrase].push_back(groupe);
    }
}




// Recherche des virgules dans les phrases.

void Phrase::recherche_virgule()
{
    bool virgule  = false;
    vector <string> tableau;
    string phrase = "", mot = "";
    
    for (int i = 0; i < _phrase_source.size(); i++)
    {
        if (_phrase_source[i] == ',' || i == _phrase_source.size() - 1)
        {
            if (_phrase_source[i] != ',')
            {
                phrase += _phrase_source[i];
            }
            
            else
            {
                virgule = true;
            }
            
            // Séparation des mots.
            
            istringstream iss(phrase);
            
            while (getline(iss, mot, ' '))
            {
                tableau.push_back(mot);
            }
            
            __mots.push_back(vector <Groupe> ());
            
            // Traduction des phrases.
            
            traduction_des_mots(tableau, virgule);
            
            // S'il y a un verbe dans le morceau de phrase, on considère qu'elle est indépendante du reste.
            
            if (_presence_verbe == true)
            {
                _presence_verbe = false;
                
                _indice_sous_phrase++;
            }
            
            phrase = "";
            virgule = false;
            tableau.clear();
            
            while (_phrase_source[i + 1] == ' ')
            {
                i++;
            }
        }
        
        else
        {
            phrase += _phrase_source[i];
        }
    }
}




void Phrase::construire_la_phrase()
{
    recherche_virgule();
    
    choix_des_mots_selon_champ_lexical();
    
    // Affinage de la phrase afin de la rendre grammaticalement correcte.
    
    /*Affinage phrase(_langue_sortie, __phrase, __structure);
     
     phrase.affiner_phrases();*/
    
    // Construction de la phrase finale.
    
    for (int i = 0; i < __phrase.size(); i++)
    {
        for (int j = 0; j < __phrase[i].size(); j++)
        {
            _phrase_sortie += __phrase[i][j] + '/';
        }
        
        _phrase_sortie.erase(_phrase_sortie.size() - 1);
        
        _phrase_sortie += ' ';
    }

    _phrase_sortie.erase(_phrase_sortie.size() - 1);
}
