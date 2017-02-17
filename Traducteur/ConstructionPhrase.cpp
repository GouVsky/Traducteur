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
#include "ConstructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string source, string sortie, string texte)
{    
    _langue_source = source;
    _langue_sortie = sortie;
    
    _phrase_source = texte;
    
    presence_verbe = false;
    
    indice_mot = 0;
    indice_sous_phrase = 0;
    
    structure_du_texte_source.push_back(vector <vector <string>> ());
    structure_du_texte_sortie.push_back(vector <vector <string>> ());
    
    tableau_contenant_significations_mot.push_back(vector <vector <string>> ());
    tableau_contenant_champs_lexicaux.push_back(vector <vector <vector <string>>> ());
}




// Retourne la structure du texte traduit.

vector <string> Phrase::recuperer_structure_texte_traduit()
{
    return t_structure;
}




// Retourne le texte traduite.

string Phrase::recuperer_phrase()
{
    return _phrase_sortie;
}




// Choix du mot approprié s'il possède plusieurs sens possibles.

void Phrase::choix_des_mots_selon_champ_lexical()
{
    string  le_mot = "", le_type = "";
    
    int max = 0,
        max_valeur_champ_lexical = 0,
        valeur_champ_lexical = 0;
    
    for (int i = 0; i < tableau_contenant_champs_lexicaux.size(); i++)
    {
        for (int j = 0; j < tableau_contenant_champs_lexicaux[i].size(); j++)
        {
            for (int k = 0; k < tableau_contenant_champs_lexicaux[i][j].size(); k++)
            {
                for (int l = 0; l < tableau_contenant_champs_lexicaux[i][j][k].size(); l++)
                {
                    // On récupère la plus grande valeur parmi tous les champs lexicaux associés à une significations du mot.
                    
                    valeur_champ_lexical = champ_lexical.recuperation_tableau(tableau_contenant_champs_lexicaux[i][j][k][l]);
                    
                    if (valeur_champ_lexical > max_valeur_champ_lexical)
                    {
                        max_valeur_champ_lexical = valeur_champ_lexical;
                    }
                }
                
                // Puis, entre toutes les significations, on choisit la signification dont le champ lexical associé est le plus répandu.
                // Si plusieurs valeurs sont identiques, on les affiche toutes.
                
                if (max_valeur_champ_lexical > max || max_valeur_champ_lexical == 0)
                {
                    max = max_valeur_champ_lexical;
                    
                    le_type = structure_du_texte_sortie[i][j][k];
                    le_mot = tableau_contenant_significations_mot[i][j][k];
                }
                
                else if (max_valeur_champ_lexical == max)
                {
                    le_type += '/' + structure_du_texte_sortie[i][j][k];
                    le_mot += '/' + tableau_contenant_significations_mot[i][j][k];
                }
                
                max_valeur_champ_lexical = 0;
            }

            // Au final, on ne garde que la traduction dont le champ lexical est majoritaire.
            // C'est-à-dire celle qui correspond au contexte.
            
            if (le_mot.size() > 0 && le_type.size() > 0)
            {
                _phrase_sortie += le_mot + ' ';
                
                // On ajoute la structure autant de fois que le nombre de mots qui composent la structure.
                // Cela s'applique en particulier pour les expressions et les verbes.
                
                for (int k = le_type[le_type.size() - 1] - '0'; k--;)
                {
                    t_structure.push_back(le_type);
                }
            }
            
            max = 0;
            le_mot = "";
            le_type = "";
        }
    }
    
    // On efface le dernier espace.
    
    if (!_phrase_sortie.empty())
    {
        _phrase_sortie.erase(_phrase_sortie.size() - 1);
    }
}




// Traduction des mots selon leur nature (noms, verbes, adjectifs, expressions...).

void Phrase::traduction_des_mots(vector <string> phrase, bool virgule)
{
    NomPropre nom_propre;
    Verbe verbe(_langue_source, _langue_sortie);
    Adjectif adjectif(_langue_source, _langue_sortie);
    NomCommun nom_commun(_langue_source, _langue_sortie);
    Expression expression(_langue_source, _langue_sortie);
    Invariable invariable(_langue_source, _langue_sortie);
    
    bool p_personnel = false;
    vector <vector <string>> champs_lexicaux;
    vector <string> s_source, s_sortie, significations;
    

    for (int i = 0; i < phrase.size(); i++)
    {
        // Expression.
        
        expression.determine_si_existe_une_expression_dans_la_phrase(i, phrase);
        
        int taille_source = expression.recuperer_taille_expression_source();
        int taille_sortie = expression.recuperer_taille_expression_sortie();
        
        if (expression.recuperer_taille_expression_sortie() > 0)
        {
            s_source.push_back("expression_" + to_string(taille_source));
            s_sortie.push_back("expression_" + to_string(taille_sortie));
            
            // On stocke l'expression.
            
            significations.push_back(expression.recuperer_expression());
            
            champs_lexicaux.push_back(vector <string> ());
            
            champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
            
            i += taille_source - 1;
        }
        
        else
        {
            // Pronom personnel.
            
            string pp_a[9] = {"i", "you", "he", "she", "it", "we", "you", "they", "they"};
            string pp_f[9] = {"je", "tu", "il", "elle", "on", "nous", "vous", "ils", "elles"};
            
            pronom_personnel["A"] = pp_a;
            pronom_personnel["F"] = pp_f;
            
            for (int j = 8; j--;)
            {
                if (pronom_personnel[_langue_source][j] == phrase[i])
                {
                    p_personnel = true;
                    
                    s_source.push_back("pronom_" + pronom_personnel["F"][j] + "_1");
                    s_sortie.push_back("pronom_" + pronom_personnel["F"][j] + "_1");
                    
                    significations.push_back(pronom_personnel[_langue_sortie][j]);
                    
                    champs_lexicaux.push_back(vector <string>());

                    champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                    
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
                
                nom_commun.le_mot_est_un_nom_commun(phrase[i], &champ_lexical);
                
                int nombre_de_noms_communs = nom_commun.recuperer_nombre_de_significations();
                                
                for (int j = 0; j < nombre_de_noms_communs; j++)
                {
                    int nombre_de_champs_lexicaux = nom_commun.recuperer_nombre_de_champs_lexicaux_pour_chaque_mot(j);

                    // On stocke le genre et le nombre.
                    
                    s_source.push_back(nom_commun.recuperer_genre(j) + '_' + nom_commun.recuperer_nombre(j) + "_1");
                    s_sortie.push_back(nom_commun.recuperer_genre(j) + '_' + nom_commun.recuperer_nombre(j) + "_1");
                    
                    // On stocke le mots.
                    
                    significations.push_back(nom_commun.recuperer_mot(j));
                    
                    // On stocke les champs lexicaux.
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    for (int k = 0; k < nombre_de_champs_lexicaux; k++)
                    {
                        champs_lexicaux[champs_lexicaux.size() - 1].push_back(nom_commun.recuperer_champ_lexical(j, k));
                    }
                }
                
                
                // Nom propre masculin ou féminin.
                
                nom_propre.le_mot_est_un_nom_propre(phrase[i]);
                
                int nombre_de_noms_propres = nom_propre.recuperer_nombre_de_mots();
                
                for (int j = 0; j < nombre_de_noms_propres; j++)
                {
                    // On stocke le genre.
                    
                    s_source.push_back(nom_propre.recuperer_genre(j) + "_1");
                    s_sortie.push_back(nom_propre.recuperer_genre(j) + "_1");
                    
                    // On stocke les mots.
                    
                    significations.push_back(nom_propre.recuperer_mot(j));
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                }
                
                
                // Mot invariable.
                
                invariable.le_mot_est_invariable(phrase[i]);
                
                int nombre_de_mots_invariables = invariable.recuperer_nombre_de_mots();
                
                if (nombre_de_mots_invariables > 0)
                {
                    string mot_invariable = invariable.recuperer_mot();
                    
                    // La conjonction "et" est un cas spécial :
                    // - Elle peut être utilisée comme conjonction de coordination entre deux phrase.
                    // - Ou pour former un sujet complexe.
                    
                    // (Se reporter à la classe "Sujet")
                    
                    if (mot_invariable == "and" || mot_invariable == "et")
                    {
                        s_source.push_back("conjonction_et_1");
                        s_sortie.push_back("conjonction_et_1");
                    }
                    
                    else
                    {
                        s_source.push_back("invariable_1");
                        s_sortie.push_back("invariable_1");
                    }
                    
                    significations.push_back(mot_invariable);
                    
                    champs_lexicaux.push_back(vector <string> ());

                    champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                }
                
                
                // Adjectif.
                
                adjectif.le_mot_est_un_adjectif(phrase[i], &champ_lexical);
                
                int nombre_de_adjectifs = adjectif.recuperer_nombre_de_adjectifs();
                
                if (nombre_de_adjectifs > 0)
                {
                    s_source.push_back("adjectif_1");
                    s_sortie.push_back("adjectif_1");
                    
                    // On stocke l'adjectif.
                    
                    significations.push_back(adjectif.recuperer_adjectif());
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back(adjectif.recuperer_champ_lexical());
                }
                
                
                // Verbe.

                verbe.determine_si_existe_un_verbe_dans_la_phrase(i, phrase, structure_du_texte_source[indice_sous_phrase], &champ_lexical);
                
                int taille_du_verbe = verbe.recuperer_taille_verbe_sortie();
                
                if (taille_du_verbe > 0)
                {
                    presence_verbe = true;
                    
                    s_source.push_back("verbe_" + to_string(verbe.recuperer_taille_verbe_source()));
                    s_sortie.push_back("verbe_" + to_string(verbe.recuperer_taille_verbe_sortie()));
                    
                    // On stocke le verbe.
                    
                    significations.push_back(verbe.recuperer_verbe());
                    
                    // On stocke les champs lexicaux.
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back(verbe.recuperer_champ_lexical());
                    
                    // On passe les termes qui composent le verbe.
                    
                    i += verbe.recuperer_taille_verbe_source() - 1;
                }
                
                
                // Le mot n'est pas répertorié dans la base de données.
                
                if (nombre_de_noms_communs == 0 && nombre_de_noms_propres == 0 && nombre_de_mots_invariables == 0 && nombre_de_adjectifs == 0
                    && taille_du_verbe == 0)
                {
                    s_source.push_back("inconnu_1");
                    s_sortie.push_back("inconnu_1");
                    
                    significations.push_back(phrase[i]);
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                }
            }
        }

        for (int j = 0; j < s_source.size(); j++)
        {
            // S'il y a une virgule après le mot, on l'ajoute.
            
            if (i == phrase.size() - 1 && virgule == true)
            {
                significations[j] += ',';
            }
            
            structure_du_texte_source[indice_sous_phrase].push_back(vector <string> ());
            structure_du_texte_sortie[indice_sous_phrase].push_back(vector <string> ());
            
            tableau_contenant_significations_mot[indice_sous_phrase].push_back(vector <string> ());
            tableau_contenant_champs_lexicaux[indice_sous_phrase].push_back(vector <vector <string>> ());
            
            // Ajout des mots.
                        
            structure_du_texte_source[indice_sous_phrase][indice_mot].push_back(s_source[j]);
            structure_du_texte_sortie[indice_sous_phrase][indice_mot].push_back(s_sortie[j]);
            
            tableau_contenant_significations_mot[indice_sous_phrase][indice_mot].push_back(significations[j]);
            tableau_contenant_champs_lexicaux[indice_sous_phrase][indice_mot].push_back(vector <string> ());
            
            // Ajout des champs lexicaux.
            
            for (int k = 0; k < champs_lexicaux[j].size(); k++)
            {
                tableau_contenant_champs_lexicaux[indice_sous_phrase][indice_mot][j].push_back(champs_lexicaux[j][k]);
            }
        }
        
        // Réinitialisation.
        
        s_source.clear();
        s_sortie.clear();
        significations.clear();
        champs_lexicaux.clear();
        
        p_personnel = false;

        indice_mot++;
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
            
            // Traduction des phrases.
            
            traduction_des_mots(tableau, virgule);
                        
            // S'il y a un verbe dans le morceau de phrase, on considère qu'elle est indépendante du reste.

            if (presence_verbe == true)
            {
                presence_verbe = false;
                
                indice_mot = 0;
                indice_sous_phrase++;
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
