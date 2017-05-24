//
//  expression.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "ParseurExpression.h"
#include "ResourcePath.hpp"

using namespace std;


ParseurExpression::ParseurExpression(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _expression_existe = false;
}




// Détermine s'il existe une expression dans la phrase.
#include <iostream>
bool ParseurExpression::parser_fichier(string mot, vector <Groupe> & groupes)
{
    ifstream monFichierExpressions(resourcePath() + _fichier);

    while (!monFichierExpressions.eof())
    {
        monFichierExpressions >> __expression["A"] >> __expression["F"];
        
        // Si le premier mot de l'expression ne correspond pas au mot de la phrase, cela ne sert à rien de continuer.
        
        if (__expression[_langue_source].substr(0, mot.size()).size() == mot.size())
        {
            int taille_expression = (int) count(__expression[_langue_source].begin(), __expression[_langue_source].end(), ';') + 1;
            
            int nombre_groupe = groupes.size();
            
            string expression_de_la_phrase = "";
            
            // Comparaison de l'expression avec celle de la phrase.

            // On construit l'expression avec les mots précédents.
            // On ne prend pas en compte le mot en cours.
            
            int indice = nombre_groupe - taille_expression + 1;
            
            if (indice < 0)
            {
                indice = 1;
            }

            for (int i = indice; i < nombre_groupe; i++)
            {
                expression_de_la_phrase += groupes[i].recuperer_mot_source() + ';';
            }
            
            expression_de_la_phrase += mot;
            
            cout << __expression[_langue_source] << endl;
            // On compare.

            if (expression_de_la_phrase == __expression[_langue_source])
            {
                // On supprime les groupes de mots qui font en fait partis de l'expression.

                groupes.erase(groupes.begin() + indice, groupes.end());
                
                
                replace(__expression[_langue_sortie].begin(), __expression[_langue_sortie].end(), ';', ' ');
                
                _expression = __expression[_langue_sortie];
                
                _expression_existe = true;
                
                break;
            }
        }
    }
    
    return _expression_existe;
}
