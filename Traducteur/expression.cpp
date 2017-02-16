//
//  expression.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "expression.h"
#include "ResourcePath.hpp"

using namespace std;


Expression::Expression(string source, string sortie)
{
    langue_source = source;
    langue_sortie = sortie;
    
    taille_expression_source = 0;
    taille_expression_sortie = 0;
}




int Expression::recuperer_taille_expression_sortie()
{
    return taille_expression_sortie;
}




int Expression::recuperer_taille_expression_source()
{
    return taille_expression_source;
}




string Expression::recuperer_expression()
{
    return expression[langue_sortie];
}




// Détermine s'il existe une expression dans la phrase.

void Expression::determine_si_existe_une_expression_dans_la_phrase(int compteur, vector <string> tableau)
{
    taille_expression_source = 0;
    taille_expression_sortie = 0;
    
    ifstream monFichierExpressions(resourcePath() + "expressions.txt");

    while (!monFichierExpressions.eof())
    {
        monFichierExpressions >> expression["A"] >> expression["F"];
                
        // Si le premier mot de l'expression ne correspond pas au mot de la phrase, cela ne sert à rien de continuer.
        
        if (expression[langue_source].substr(0, tableau[compteur].size()) == tableau[compteur])
        {
            // On relève les nombre de mots qui composent l'expression.
            
            taille_expression_source = (int) count(expression[langue_source].begin(), expression[langue_source].end(), ';') + 1;
            
            // On construit l'expression avec les mots entrés par l'utilisateur.

            for (int i = 0; i < min(taille_expression_source, (int) tableau.size() - compteur); i++)
            {
                phrase += tableau[compteur + i] + ';';
            }

            phrase.erase(phrase.size() - 1);

            // On compare.
            
            if (expression[langue_source] == phrase)
            {
                taille_expression_sortie = (int) count(expression[langue_sortie].begin(), expression[langue_sortie].end(), ';') + 1;
                
                replace(expression[langue_sortie].begin(), expression[langue_sortie].end(), ';', ' ');
                
                break;
            }
        }
        
        // Réinitialisation.
        
        phrase = "";
        taille_expression_source = 0;
    }
}
