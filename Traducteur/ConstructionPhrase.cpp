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
#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string source, string sortie, string texte)
{    
    _langue_source = source;
    _langue_sortie = sortie;
    
    _phrase_source = texte;
    
    _presence_verbe = false;
    
    _indice_mot = 0;
    _indice_sous_phrase = 0;
}




// Stocke les différents champs lexicaux associés au mot sélectionné.

void Phrase::ajouter_le_champ_lexical(vector <vector <string>> champs_lexicaux, int nombre_de_champs_lexicaux, int numero_du_mot)
{
    __tableau_contenant_champs_lexicaux[_indice_sous_phrase].push_back(vector <vector <string>> ());
    
    __tableau_contenant_champs_lexicaux[_indice_sous_phrase][_indice_mot].push_back(vector <string> ());
    
    for (int j = 0; j < nombre_de_champs_lexicaux; j++)
    {
        __tableau_contenant_champs_lexicaux[_indice_sous_phrase][_indice_mot][numero_du_mot].push_back(champs_lexicaux[numero_du_mot][j]);
        
        __champ_lexical.incrementation_des_champs_lexicaux(champs_lexicaux[numero_du_mot][j]);
    }
}




// Stocke le champ lexical associé au mot.

void Phrase::ajouter_le_champ_lexical(string champ_lexical)
{
    __tableau_contenant_champs_lexicaux[_indice_sous_phrase].push_back(vector <vector <string>> ());
    
    __tableau_contenant_champs_lexicaux[_indice_sous_phrase][_indice_mot].push_back(vector <string> ());
    
    __tableau_contenant_champs_lexicaux[_indice_sous_phrase][_indice_mot][0].push_back(champ_lexical);
    
    __champ_lexical.incrementation_des_champs_lexicaux(champ_lexical);
}




// Stocke le type du mot traduit.

void Phrase::ajouter_le_type_sortie(string type)
{
    __structure_du_texte_sortie[_indice_sous_phrase].push_back(vector <string> ());
    
    __structure_du_texte_sortie[_indice_sous_phrase][_indice_mot].push_back(type);
}




// Stocke le type du mot d'origine.

void Phrase::ajouter_le_type_source(string type)
{
    __structure_du_texte_source[_indice_sous_phrase].push_back(vector <string> ());
    
    __structure_du_texte_source[_indice_sous_phrase][_indice_mot].push_back(type);
}




// Stocke le mot traduit.

void Phrase::ajouter_le_mot_sortie(string mot)
{
    __tableau_contenant_significations_mot[_indice_sous_phrase].push_back(vector <string> ());
    
    __tableau_contenant_significations_mot[_indice_sous_phrase][_indice_mot].push_back(mot);
}




// Choix du mot approprié s'il possède plusieurs sens possibles.

void Phrase::choix_des_mots_selon_champ_lexical()
{
    int max = -1,
        valeur_champ_lexical = 0,
        max_valeur_champ_lexical = 0;
    
    for (int i = 0; i < __tableau_contenant_champs_lexicaux.size(); i++)
    {
        for (int j = 0; j < __tableau_contenant_champs_lexicaux[i].size(); j++)
        {
            __phrase.push_back(vector <string> (0));
            
            __structure.push_back(vector <string> (0));
            
            for (int k = 0; k < __tableau_contenant_champs_lexicaux[i][j].size(); k++)
            {
                for (int l = 0; l < __tableau_contenant_champs_lexicaux[i][j][k].size(); l++)
                {
                    // On récupère la plus grande valeur parmi tous les champs lexicaux associés à une significations du mot.
                    
                    valeur_champ_lexical = __champ_lexical.recuperation_valeur_champ_lexical(__tableau_contenant_champs_lexicaux[i][j][k][l]);
                                        
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
                    __phrase[__phrase.size() - 1].push_back(__tableau_contenant_significations_mot[i][j][k]);
                    
                    __structure[__structure.size() - 1].clear();
                    __structure[__structure.size() - 1].push_back(__structure_du_texte_sortie[i][j][k]);
                }
                
                else if (max_valeur_champ_lexical == max)
                {
                    __phrase[__phrase.size() - 1].push_back(__tableau_contenant_significations_mot[i][j][k]);
                    
                    __structure[__structure.size() - 1].push_back(__structure_du_texte_sortie[i][j][k]);
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

        
        // Expression.
        
        expression.determine_si_existe_une_expression_dans_la_phrase(i, phrase);
        
        int taille_source = expression.recuperer_taille_expression_source();
        int taille_sortie = expression.recuperer_taille_expression_sortie();
        
        if (expression.expression_existe())
        {
            ajouter_le_type_source("expression_" + to_string(taille_source));
            ajouter_le_type_sortie("expression_" + to_string(taille_sortie));
            
            // On stocke l'expression.
            
            ajouter_le_mot_sortie(expression.recuperer_expression());
            
            ajouter_le_champ_lexical("-");
            
            i += taille_source - 1;
        }
        
        else
        {
            // Pronom personnel.
            
            vector <string> pp_a = {"i", "you", "he", "she", "it", "we", "you", "they"};
            vector <string> pp_f = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
            
            __pronom_personnel["A"] = pp_a;
            __pronom_personnel["F"] = pp_f;
            
            for (int j = 0; j < __pronom_personnel[_langue_source].size(); j++)
            {
                if (__pronom_personnel[_langue_source][j] == phrase[i])
                {
                    p_personnel = true;
                    
                    ajouter_le_type_source("pronom_" + __pronom_personnel["F"][j] + "_1");
                    ajouter_le_type_sortie("pronom_" + __pronom_personnel["F"][j] + "_1");
                    
                    ajouter_le_mot_sortie(__pronom_personnel[_langue_sortie][j]);
                    
                    ajouter_le_champ_lexical("-");
                    
                    break;
                }
            }

            // Le mot n'est pas un pronom.
            
            if (p_personnel == false)
            {
                // Lecture de tous les fichiers.
                // Un mot peut avoir plusieurs significations de natures différentes.
                
                // Si le mot est contenu dans les fichiers :
                //      - On l'ajoute dans un tableau contenant les mots traduits.
                //      - On ajoute son champ lexical dans un autre tableau.
                
                
                
                // Nom commun masculin ou féminin.
                
                nom_commun.le_mot_est_un_nom_commun(phrase[i]);
                
                nombre_de_noms_communs = nom_commun.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_noms_communs; j++)
                {
                    int nombre_de_champs_lexicaux = nom_commun.recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(j);
                    
                    ajouter_le_type_source(nom_commun.recuperer_genre() + '_' + nom_commun.recuperer_nombre() + "_1");
                    ajouter_le_type_sortie(nom_commun.recuperer_genre() + '_' + nom_commun.recuperer_nombre() + "_1");
                    
                    ajouter_le_mot_sortie(nom_commun.recuperer_mot(j));
                    
                    ajouter_le_champ_lexical(nom_commun.recuperer_champs_lexicaux(), nombre_de_champs_lexicaux, j);
                }
                
                
                
                // Nom propre masculin ou féminin.
                
                nom_propre.le_mot_est_un_nom_propre(phrase[i]);
                
                nombre_de_noms_propres = nom_propre.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_noms_propres; j++)
                {
                    ajouter_le_type_source(nom_propre.recuperer_genre() + "_singulier_1");
                    ajouter_le_type_sortie(nom_propre.recuperer_genre() + "_singulier_1");
                    
                    ajouter_le_mot_sortie(nom_propre.recuperer_mot(j));
                    
                    ajouter_le_champ_lexical("-");
                }
                
                
                
                // Mot invariable.
                
                invariable.le_mot_est_invariable(phrase[i]);
                
                nombre_de_mots_invariables = invariable.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_mots_invariables; j++)
                {
                    int nombre_de_champ_lexicaux = invariable.recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(j);
                    
                    string mot_invariable = invariable.recuperer_mot(j);
                    
                    // La conjonction "et" est un cas spécial :
                    // - Elle peut être utilisée comme conjonction de coordination entre deux phrase.
                    // - Ou pour former un sujet complexe.
                    
                    // (Se reporter à la classe "Sujet")
                    
                    if (mot_invariable == "and" || mot_invariable == "et")
                    {
                        ajouter_le_type_source("conjonction_et_1");
                        ajouter_le_type_sortie("conjonction_et_1");
                    }
                    
                    else
                    {
                        ajouter_le_type_source("invariable_1");
                        ajouter_le_type_sortie("invariable_1");
                    }
                    
                    ajouter_le_mot_sortie(mot_invariable);
                    
                    ajouter_le_champ_lexical(invariable.recuperer_champs_lexicaux(), nombre_de_champ_lexicaux, j);
                }
                
                
                
                // Adjectif.
                
                adjectif.le_mot_est_un_adjectif(phrase[i]);
                
                nombre_de_adjectifs = adjectif.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_adjectifs; j++)
                {
                    int nombre_de_champs_lexicaux = adjectif.recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(j);
                    
                    ajouter_le_type_source("adjectif_1");
                    ajouter_le_type_sortie("adjectif_1");
                    
                    ajouter_le_mot_sortie(adjectif.recuperer_mot(j));
                    
                    ajouter_le_champ_lexical(adjectif.recuperer_champs_lexicaux(), nombre_de_champs_lexicaux, j);
                }
                
                
                
                // Verbe.

                verbe.determine_si_existe_un_verbe_dans_la_phrase(i, phrase, __structure_du_texte_source[_indice_sous_phrase]);
                
                nombre_de_verbes = verbe.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_verbes; j++)
                {
                    int nombre_de_champs_lexicaux = verbe.recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(j);
                    
                    _presence_verbe = true;
                    
                    ajouter_le_type_source("verbe_" + to_string(verbe.recuperer_taille_verbe_source()));
                    ajouter_le_type_sortie("verbe_" + to_string(verbe.recuperer_taille_verbe_sortie()));
                    
                    ajouter_le_mot_sortie(verbe.recuperer_mot(j));
                    
                    ajouter_le_champ_lexical(verbe.recuperer_champs_lexicaux(), nombre_de_champs_lexicaux, j);
                    
                    // On passe les termes qui composent le verbe.
                    
                    i += verbe.recuperer_taille_verbe_source() - 1;
                }
                

                
                // Le mot n'est pas répertorié dans la base de données.
                
                if (nombre_de_noms_communs == 0
                    && nombre_de_noms_propres == 0
                    && nombre_de_mots_invariables == 0
                    && nombre_de_adjectifs == 0
                    && nombre_de_verbes == 0)
                {
                    ajouter_le_type_source("inconnu_1");
                    ajouter_le_type_sortie("inconnu_1");
                    
                    ajouter_le_mot_sortie(phrase[i]);
                    
                    ajouter_le_champ_lexical("-");
                }
            }
        }
        
        p_personnel = false;

        _indice_mot++;
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
            
            __structure_du_texte_source.push_back(vector <vector <string>> ());
            __structure_du_texte_sortie.push_back(vector <vector <string>> ());
            
            __tableau_contenant_significations_mot.push_back(vector <vector <string>> ());
            __tableau_contenant_champs_lexicaux.push_back(vector <vector <vector <string>>> ());
            
            // Traduction des phrases.
            
            traduction_des_mots(tableau, virgule);
                        
            // S'il y a un verbe dans le morceau de phrase, on considère qu'elle est indépendante du reste.

            if (_presence_verbe == true)
            {
                _presence_verbe = false;
                
                _indice_mot = 0;
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
    
    Affinage phrase(_langue_sortie, &__phrase, &__structure);
    
    phrase.affiner_phrases();
    
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
