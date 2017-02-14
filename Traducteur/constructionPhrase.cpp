//
//  constructionPhrase.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 18/11/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "verbe.hpp"
#include "adjectif.h"
#include "expression.h"
#include "nomPropre.hpp"
#include "nomCommun.hpp"
#include "motInvariable.h"
#include "champsLexicaux.hpp"
#include "constructionPhrase.hpp"

using namespace std;


Phrase::Phrase(string source, string sortie)
{    
    langue_source = source;
    langue_sortie = sortie;
}




Phrase::~Phrase()
{
    t_final.clear();
    
    t_structure.clear();
    
    indice_mot.clear();
    indice_sous_phrase.clear();
    
    presence_verbe.clear();
    
    structure_du_texte_source.clear();
    structure_du_texte_sortie.clear();
    
    tableau_contenant_significations_mot.clear();
    tableau_contenant_champs_lexicaux.clear();
}




// Retourne la structure du texte traduit.

vector <string> Phrase::recuperer_structure_texte_traduit()
{
    return t_structure;
}




// Retourne le texte traduite.

string Phrase::recuperer_texte_traduit()
{
    return phrase_finale;
}




// Assemblage de chaque phrases traduites séparément.

void Phrase::assemblage_des_phrases()
{
    bool et_bill = false; // Premier mot.
    
    for (int i = 0; i < min(t_final.size(), t_ponctuation.size()); i++)
    {
        for (int j = 0; j < t_final[i].size(); j++)
        {
            // On met une majuscule au premier mot de la phrase.
            
            if (et_bill == false)
            {
                t_final[i][j][0] = toupper(t_final[i][j][0]);
                
                et_bill = !et_bill;
            }
            
            phrase_finale += ' ' + t_final[i][j];
        }
        
        // On ajoute la ponctuation.
        
        if (t_ponctuation[i] != 0)
        {
            phrase_finale += t_ponctuation[i];
        
            et_bill = !et_bill;
        }
    }
    
    // On efface le premier espace.
    
    phrase_finale.erase(0, 1);
}




// Choix du mot approprié s'il possède plusieurs sens possibles.

void Phrase::choix_des_mots_selon_champ_lexical(int indice)
{
    string  le_mot = "", le_type = "";
    int max = 0, max_valeur_champ_lexical = 0, valeur_champ_lexical = 0;
    
    for (int i = 0; i < tableau_contenant_champs_lexicaux[indice].size(); i++)
    {
        for (int j = 0; j < tableau_contenant_champs_lexicaux[indice][i].size(); j++)
        {
            for (int k = 0; k < tableau_contenant_champs_lexicaux[indice][i][j].size(); k++)
            {
                for (int l = 0; l < tableau_contenant_champs_lexicaux[indice][i][j][k].size(); l++)
                {
                    // On récupère la plus grande valeur parmi tous les champs lexicaux associés à une significations du mot.
                    
                    valeur_champ_lexical = champ_lexical.recuperation_tableau(tableau_contenant_champs_lexicaux[indice][i][j][k][l]);
                                        
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
                    
                    le_type = structure_du_texte_sortie[indice][i][j][k];
                    le_mot = tableau_contenant_significations_mot[indice][i][j][k];
                }
                
                else if (max_valeur_champ_lexical == max)
                {
                    le_type += '/' + structure_du_texte_sortie[indice][i][j][k];
                    le_mot += '/' + tableau_contenant_significations_mot[indice][i][j][k];
                }
                
                max_valeur_champ_lexical = 0;
            }
            
            // Au final, on ne garde que la traduction dont le champ lexical est majoritaire.
            // C'est-à-dire celle qui correspond au contexte.
            
            if (le_mot.size() > 0 && le_type.size() > 0)
            {
                t_final[indice].push_back(le_mot);
                
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
}




// Traduction des mots selon leur nature (noms, verbes, adjectifs, expressions...).

void Phrase::traduction_des_mots(vector <string> phrase, int indice, bool virgule)
{
    NomPropre nom_propre;
    Verbe verbe(langue_source, langue_sortie);
    Adjectif adjectif(langue_source, langue_sortie);
    NomCommun nom_commun(langue_source, langue_sortie);
    Expression expression(langue_source, langue_sortie);
    Invariable invariable(langue_source, langue_sortie);
    
    bool p_personnel = false;
    vector <vector <string>> champs_lexicaux;
    vector <string> s_source, s_sortie, significations;
    

    for (int i = 0; i < phrase.size(); i++)
    {
        // Expression.
        
        tuple <string, int, int> resultat_expression = expression.determine_si_existe_une_expression_dans_la_phrase(i, phrase);
        
        if (get <0> (resultat_expression) != "MEM2!65oG")
        {
            s_source.push_back("expression_" + to_string(get <1> (resultat_expression)));
            s_sortie.push_back("expression_" + to_string(get <2> (resultat_expression)));
            
            significations.push_back(get <0> (resultat_expression));
            
            champs_lexicaux.push_back(vector <string> ());
            
            champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
            
            i += get <1> (resultat_expression) - 1;
        }
        
        else
        {
            // Pronom personnel.
            
            pronom_personnel["A"] = pp_a;
            pronom_personnel["F"] = pp_f;
            
            for (int j = 8; j--;)
            {
                if(pronom_personnel[langue_source][j] == phrase[i])
                {
                    p_personnel = true;
                    
                    s_source.push_back("pronom_" + pronom_personnel["F"][j] + "_1");
                    s_sortie.push_back("pronom_" + pronom_personnel["F"][j] + "_1");
                    
                    significations.push_back(pronom_personnel[langue_sortie][j]);
                    
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
                
                tuple <vector <string>, vector <vector <string>>, vector <string>, string> mot_commun = nom_commun.le_mot_est_un_nom_commun(phrase[i], &champ_lexical);
                                
                if (!(get <0> (mot_commun)).empty())
                {
                    for (int j = 0; j < (get <0> (mot_commun)).size(); j++)
                    {
                        // On stocke le genre et le nombre.
                        
                        s_source.push_back(get <2> (mot_commun)[j] + "_" + get <3> (mot_commun) + "_1");
                        s_sortie.push_back(get <2> (mot_commun)[j] + "_" + get <3> (mot_commun) + "_1");
                        
                        significations.push_back(get <0> (mot_commun)[j]);
                        
                        champs_lexicaux.push_back(vector <string> ());
                                                
                        for (int k = 0; k < get <1> (mot_commun)[j].size(); k++)
                        {
                            champs_lexicaux[champs_lexicaux.size() - 1].push_back(get <1> (mot_commun)[j][k]);
                        }
                    }
                }
                
                
                // Nom propre masculin ou féminin.
                
                tuple <string, vector <string>> mot_propre = nom_propre.le_mot_est_un_nom_propre(phrase[i]);
                
                if (!(get <1> (mot_propre)).empty())
                {
                    for (int j = 0; j < (get <1> (mot_propre)).size(); j++)
                    {
                        // On stocke le genre.
                        
                        s_source.push_back(get <1> (mot_propre)[j] + "_1");
                        s_sortie.push_back(get <1> (mot_propre)[j] + "_1");
                        
                        significations.push_back(get <0> (mot_propre));
                        
                        champs_lexicaux.push_back(vector <string> ());
                        
                        champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                    }
                }
                
                
                // Mot invariable.
                
                string mot_invariable = invariable.le_mot_est_invariable(phrase[i]);
                
                if (mot_invariable != "MEM2!65oG")
                {
                    // La conjonction "et" est un cas spécial :
                    // - Elle peut être utilisée comme conjonction de coordination entre deux phrase.
                    // - Ou pour former un sujet complexe.
                    
                    // (Se reporter à la classe "Sujet")
                    
                    if(mot_invariable == "and" || mot_invariable == "et")
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
                
                tuple <string, string> mot_adjectif = adjectif.le_mot_est_un_adjectif(phrase[i], &champ_lexical);
                
                if (get <0> (mot_adjectif) != "MEM2!65oG")
                {
                    s_source.push_back("adjectif_1");
                    s_sortie.push_back("adjectif_1");
                    
                    significations.push_back(get <0> (mot_adjectif));
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back(get <1> (mot_adjectif));
                }
                
                
                // Verbe.
                
                tuple <string, string, int, int> resultat_verbe = verbe.determine_si_existe_un_verbe_dans_la_phrase(i, phrase, structure_du_texte_source[indice][indice_sous_phrase[indice]], &champ_lexical);
                
                if (get <0> (resultat_verbe) != "MEM2!65oG")
                {
                    presence_verbe[indice] = true;
                    
                    s_source.push_back("verbe_" + to_string(get <2> (resultat_verbe)));
                    s_sortie.push_back("verbe_" + to_string(get <3> (resultat_verbe)));
                    
                    significations.push_back(get <0> (resultat_verbe));
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back(get <1> (resultat_verbe));
                    
                    // On passe les termes qui composent le verbe.
                    
                    i += get <2> (resultat_verbe) - 1;
                }
                
                
                // Le mot n'est pas répertorié dans la base de données.
                
                if ((get <0> (mot_commun)).empty() && (get <1> (mot_propre)).empty() && mot_invariable == "MEM2!65oG" && get <0> (resultat_verbe) == "MEM2!65oG" && get <0> (mot_adjectif) == "MEM2!65oG")
                {
                    s_source.push_back("inconnu_1");
                    s_sortie.push_back("inconnu_1");
                    
                    significations.push_back(phrase[i]);
                    
                    champs_lexicaux.push_back(vector <string> ());
                    
                    champs_lexicaux[champs_lexicaux.size() - 1].push_back("-");
                }
            }
        }

        for(int j = 0; j < s_source.size(); j++)
        {
            // S'il y a une virgule après le mot, on l'ajoute.
            
            if(i == phrase.size() - 1 && virgule == true)
            {
                significations[j] += ',';
            }
            
            structure_du_texte_source[indice][indice_sous_phrase[indice]].push_back(vector <string> ());
            structure_du_texte_sortie[indice][indice_sous_phrase[indice]].push_back(vector <string> ());
            
            tableau_contenant_significations_mot[indice][indice_sous_phrase[indice]].push_back(vector <string> ());
            tableau_contenant_champs_lexicaux[indice][indice_sous_phrase[indice]].push_back(vector <vector <string>> ());
            
            // Ajout des mots.
                        
            structure_du_texte_source[indice][indice_sous_phrase[indice]][indice_mot[indice]].push_back(s_source[j]);
            structure_du_texte_sortie[indice][indice_sous_phrase[indice]][indice_mot[indice]].push_back(s_sortie[j]);
            
            tableau_contenant_significations_mot[indice][indice_sous_phrase[indice]][indice_mot[indice]].push_back(significations[j]);
            
            tableau_contenant_champs_lexicaux[indice][indice_sous_phrase[indice]][indice_mot[indice]].push_back(vector <string> ());
            
            // Ajout des champs lexicaux.
            
            for (int k = 0; k < champs_lexicaux[j].size(); k++)
            {
                tableau_contenant_champs_lexicaux[indice][indice_sous_phrase[indice]][indice_mot[indice]][j].push_back(champs_lexicaux[j][k]);
            }
        }

        // Réinitialisation.
        
        s_source.clear();
        s_sortie.clear();
        significations.clear();
        champs_lexicaux.clear();
        
        p_personnel = false;

        indice_mot[indice]++;
    }
}




// Recherche des virgules dans les phrases.

void Phrase::recherche_virgule(string phrase, int indice)
{
    bool virgule  = false;
    vector <string> tableau;
    string sous_phrase = "", mot = "";
    
    for(int i = 0; i < phrase.size(); i++)
    {
        if(phrase[i] == ',' || i == phrase.size() - 1)
        {
            if(phrase[i] != ',')
            {
                sous_phrase += phrase[i];
            }
            
            else
            {
                virgule = true;
            }
            
            // Séparation des mots.
            
            istringstream iss(sous_phrase);
            
            while(getline(iss, mot, ' '))
            {
                tableau.push_back(mot);
            }
            
            structure_du_texte_source[indice].push_back(vector <vector <string>> ());
            structure_du_texte_sortie[indice].push_back(vector <vector <string>> ());
            
            tableau_contenant_significations_mot[indice].push_back(vector <vector <string>> ());
            tableau_contenant_champs_lexicaux[indice].push_back(vector <vector <vector <string>>> ());
            
            // Traduction des phrases.
            
            traduction_des_mots(tableau, indice, virgule);
            
            // S'il y a un verbe dans le morceau de phrase, on considère qu'elle est indépendante du reste.

            if(presence_verbe[indice] == true)
            {
                presence_verbe[indice] = false;
                
                indice_mot[indice] = 0;
                indice_sous_phrase[indice]++;
            }
            
            virgule = false;
            tableau.clear();
            sous_phrase = "";
            
            while (phrase[i + 1] == ' ')
            {
                i++;
            }
            
        }
        
        else
        {
            sous_phrase += phrase[i];
        }
    }
}





// Découpe le texte à chaque conjonction de coordination.

void Phrase::recherche_conjonction_coordination(vector <string> tableau)
{
    string phrase = "";
    bool conjonction = false;
        
    conjonction_coordination["A"] = cc_a;
    conjonction_coordination["F"] = cc_f;

    for (int i = 0; i < tableau.size(); i++)
    {
        // On cherche si le mot est une conjonction de coordination ou non.

        for (int j = sizeof(conjonction_coordination[langue_source]) / sizeof(* conjonction_coordination[langue_source]); j--;)
        {
            if (tableau[i] == conjonction_coordination[langue_source][j])
            {
                conjonction = true;
                
                break;
            }
        }

        phrase += tableau[i] + ' ';
        
        // Chaque portion de la phrase comprise entre :
        //
        // - le début et une conjonction
        // - deux conjonctions
        // - une conjonction et la fin
        
        // est considérée comme étant une sous-phrase indépendante des autres.

        if (conjonction == true || i == (int)tableau.size() - 1)
        {
            phrase.erase(phrase.size() - 1);

            phrases_constituantes_le_texte.push_back(phrase);
            
            if (conjonction == true)
            {
                t_ponctuation.push_back(0);
            }
            
            conjonction = !conjonction;
            
            phrase = "";
        }
    }
}




// Séparation du texte en plusieurs phrases selon la ponctuation.

void Phrase::recherche_de_la_ponctuation(string t)
{
    vector <string> tableau;
    string mot = "", phrase = "";
    
    // On récupère le texte caractère par caractère.
    
    for (int i = 0; i < t.size(); i++)
    {
        // On découpe le texte à chaque ponctuation.
        
        if (t[i] == '.' || t[i] == '!' || t[i] == '?' || t[i] == ';' || t[i] == ':' || t[i] == '\0')
        {
            transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
            
            // On isole chaque mot constituant la phrase.
            
            istringstream iss(phrase);
            
            while (getline(iss, mot, ' '))
            {
                tableau.push_back(mot);
            }
            
            recherche_conjonction_coordination(tableau);
            
            // On ajoute la ponctuation.
            
            t_ponctuation.push_back(t[i]);
            
            // S'il existe, et tant qu'il est présent,
            // on saute le caractère espace situé entre la ponctuation et la première lettre du mot suivant.
            
            while (t[i + 1] == ' ')
            {
                i++;
            }
            
            // Réinitialisation.
            
            phrase = "";
            tableau.clear();
        }
        
        else
        {
            phrase += t[i];
        }
    }
}




// Découpe le texte en phrases.

void Phrase::construction_du_texte(string texte)
{
    int compteur = 0;
    
    thread mes_threads[100];
   
    recherche_de_la_ponctuation(texte);

    // Création d'un thread par phrase.
    
    // Les phrases créées en multithread ont une vitesse de traduction différente selon leur complexité.
    // On les place donc dans un tableau dont l'indice de position correspond au numéro du thread.
    // Cela évite un mauvais ordre d'affichage des phrases.

    while (compteur < phrases_constituantes_le_texte.size())
    {
        indice_mot.push_back(0);
        indice_sous_phrase.push_back(0);
        presence_verbe.push_back(false);
        
        structure_du_texte_source.push_back(vector <vector <vector <string>>> ());
        structure_du_texte_sortie.push_back(vector <vector <vector <string>>> ());
        
        tableau_contenant_significations_mot.push_back(vector <vector <vector <string>>> ());
        tableau_contenant_champs_lexicaux.push_back(vector <vector <vector <vector <string>>>> ());
                
        mes_threads[compteur] = thread(&Phrase::recherche_virgule, this, phrases_constituantes_le_texte[compteur], compteur);

        compteur++;
    }

    for (int i = 0; i < compteur; i++)
    {
        mes_threads[i].join();
    }
    
    for (int i = 0; i < compteur; i++)
    {
        t_final.push_back(vector <string> ());
        
        choix_des_mots_selon_champ_lexical(i);
    }
    
    assemblage_des_phrases();
}
