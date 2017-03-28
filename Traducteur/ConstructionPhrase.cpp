//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"
#include "Adjectif.h"
#include "Expression.h"
#include "NomPropre.hpp"
#include "NomCommun.hpp"
#include "Invariable.h"
#include "ChampsLexicaux.hpp"
#include "AffinagePhrase.hpp"
#include "PronomPersonnel.hpp"
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




// Choix du mot approprié s'il possède plusieurs sens possibles.

void Phrase::choix_des_mots_selon_champ_lexical()
{
    int max = -1,
        valeur_champ_lexical = 0,
        max_valeur_champ_lexical = 0;
    
    
    for (int i = 0; i < __mots.size(); i++)
    {
        for (int j = 0; j < __mots[i].size(); j++)
        {
            __phrase.push_back(vector <string> (0));
            
            // Pour tous les sens d'un mot.
            
            int nombre_de_sens = __mots[i][j].recuperer_nombre_de_sens_sortie();
            
            for (int k = 0; k < nombre_de_sens; k++)
            {
                // Pour tous les champs lexicaux d'un sens.
                
                int nombre_de_champs_lexicaux = __mots[i][j].recuperer_nombre_de_champs_lexicaux(k);

                for (int l = 0; l < nombre_de_champs_lexicaux; l++)
                {
                    // On récupère la plus grande valeur parmi tous les champs lexicaux associés à un sens du mot.
                    
                    valeur_champ_lexical = __champ_lexical.recuperation_valeur_champ_lexical(__mots[i][j].recuperer_champs_lexicaux(k, l));
                    
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
                    __phrase[__phrase.size() - 1].push_back(__mots[i][j].recuperer_sens_sortie(k));
                }
                
                else if (max_valeur_champ_lexical == max)
                {
                    __phrase[__phrase.size() - 1].push_back(__mots[i][j].recuperer_sens_sortie(k));
                }
                
                max_valeur_champ_lexical = 0;
            }
            
            max = -1;
        }
    }
}




// Traduction des mots selon leur nature (noms, verbes, adjectifs, expressions...).

void Phrase::traduction_des_mots(vector <string> phrase, bool virgule)
{
    int nombre_de_verbes,
        nombre_de_adjectifs,
        nombre_de_noms_communs,
        nombre_de_noms_propres,
        nombre_de_mots_invariables;
    
    bool p_personnel = false;

    for (int i = 0; i < phrase.size(); i++)
    {
        NomPropre nom_propre;
        Verbe verbe(_langue_source, _langue_sortie);
        Adjectif adjectif(_langue_source, _langue_sortie);
        NomCommun nom_commun(_langue_source, _langue_sortie);
        Invariable invariable(_langue_source, _langue_sortie);
        Expression expression(_langue_source, _langue_sortie);
        PronomPersonnel pronom_personnel(_langue_source, _langue_sortie);


        // Expression.
        
        expression.determine_si_existe_une_expression_dans_la_phrase(i, phrase);
        
        if (expression.expression_existe())
        {
            __mots[_indice_sous_phrase].push_back((Mot) expression.recuperer_expression());
            
            // On passe l'expression.
            
            i += expression.recuperer_taille_expression_source() - 1;
        }
        
        else
        {
            // Pronom personnel.
            
            pronom_personnel.le_mot_est_un_pronom_personnel(phrase[i]);
            
            if (pronom_personnel.existe())
            {
                __mots[_indice_sous_phrase].push_back(pronom_personnel);
            }
            
            else
            {
                // Lecture de tous les fichiers.
                // Un mot peut avoir plusieurs significations de natures différentes.
                
                // Si le mot est contenu dans les fichiers :
                //      - On l'ajoute dans un tableau contenant les mots traduits.
                //      - On ajoute son champ lexical dans un autre tableau.
                

                
                // Nom commun masculin ou féminin.
                
                nom_commun.le_mot_est_un_nom_commun(phrase[i]);
                
                nombre_de_noms_communs = nom_commun.recuperer_nombre_de_sens_sortie();
                                                
                if (nombre_de_noms_communs > 0)
                {
                    __mots[_indice_sous_phrase].push_back(nom_commun);
                                        
                    for (int j = 0; j < nombre_de_noms_communs; j++)
                    {
                        for (int k = 0; k < nom_commun.recuperer_nombre_de_champs_lexicaux(j); k++)
                        {
                            __champ_lexical.incrementation_des_champs_lexicaux(nom_commun.recuperer_champs_lexicaux(j, k));
                        }
                    }
                }
                
                
                
                // Nom propre masculin ou féminin.
                
                nom_propre.le_mot_est_un_nom_propre(phrase[i]);
                
                nombre_de_noms_propres = nom_propre.recuperer_nombre_de_sens_sortie();
                
                if (nombre_de_noms_propres > 0)
                {
                    __mots[_indice_sous_phrase].push_back(nom_propre);
                    
                    for (int j = 0; j < nombre_de_noms_propres; j++)
                    {
                        for (int k = 0; k < nom_commun.recuperer_nombre_de_champs_lexicaux(j); k++)
                        {
                            __champ_lexical.incrementation_des_champs_lexicaux(nom_propre.recuperer_champs_lexicaux(j, k));
                        }
                    }
                }
                
               
                
                // Mot invariable.
                
                invariable.le_mot_est_invariable(phrase[i]);
                
                nombre_de_mots_invariables = invariable.recuperer_nombre_de_sens_sortie();
                
                if (nombre_de_mots_invariables > 0)
                {
                    __mots[_indice_sous_phrase].push_back(invariable);
                    
                    for (int j = 0; j < nombre_de_mots_invariables; j++)
                    {
                        for (int k = 0; k < invariable.recuperer_nombre_de_champs_lexicaux(j); k++)
                        {
                            __champ_lexical.incrementation_des_champs_lexicaux(invariable.recuperer_champs_lexicaux(j, k));
                        }
                    }
                }
                
                
                
                // Adjectif.
                
                adjectif.le_mot_est_un_adjectif(phrase[i]);
                
                nombre_de_adjectifs = adjectif.recuperer_nombre_de_sens_sortie();
                
                if (nombre_de_adjectifs > 0)
                {
                    __mots[_indice_sous_phrase].push_back(adjectif);
                    
                    for (int j = 0; j < nombre_de_adjectifs; j++)
                    {
                        for (int k = 0; k < adjectif.recuperer_nombre_de_champs_lexicaux(j); k++)
                        {
                            __champ_lexical.incrementation_des_champs_lexicaux(adjectif.recuperer_champs_lexicaux(j, k));
                        }
                    }
                }
                
                
                
                // Verbe.
                
                verbe.determine_si_existe_un_verbe_dans_la_phrase(i, phrase, __mots[_indice_sous_phrase]);
                
                nombre_de_verbes = verbe.recuperer_nombre_de_sens_sortie();
                
                if (nombre_de_verbes > 0)
                {
                    __mots[_indice_sous_phrase].push_back(verbe);
                    
                    for (int j = 0; j < nombre_de_verbes; j++)
                    {
                        for (int k = 0; k < verbe.recuperer_nombre_de_champs_lexicaux(j); k++)
                        {
                            __champ_lexical.incrementation_des_champs_lexicaux(verbe.recuperer_champs_lexicaux(j, k));
                        }
                    }
                    
                    // On passe le verbe.
                    
                    i += verbe.recuperer_taille_verbe_source() - 1;
                }

                
                // Le mot n'est pas répertorié dans la base de données.
                
                if (nombre_de_noms_communs == 0
                    && nombre_de_noms_propres == 0
                    && nombre_de_mots_invariables == 0
                    && nombre_de_adjectifs == 0
                    && nombre_de_verbes == 0)
                {
                    __mots[_indice_sous_phrase].push_back((Mot) phrase[i]);
                }
            }
        }
        
        p_personnel = false;
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
            
            __mots.push_back(vector <Mot> ());
            
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
