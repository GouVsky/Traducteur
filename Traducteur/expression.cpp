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


// Détermine s'il existe une expression dans la phrase.

tuple <string, int, int> Expression::determine_si_existe_une_expression_dans_la_phrase(int compteur, vector <string> tableau, string l_source, string l_sortie)
{
    langue_source = l_source;
    langue_sortie = l_sortie;

    ifstream monFichierExpressions(resourcePath() + "expressions.txt");

    while(!monFichierExpressions.eof())
    {
        monFichierExpressions >> expression["A"] >> expression["F"];
                
        // Si le premier mot de l'expression ne correspond pas au mot de la phrase, cela ne sert à rien de continuer.
        
        if(expression[langue_source].substr(0, tableau[compteur].size()) == tableau[compteur])
        {
            // On relève les nombre de mots qui composent l'expression.
            
            taille_expression_source = (int)count(expression[langue_source].begin(), expression[langue_source].end(), ';') + 1;
            
            // On construit l'expression avec les mots entrés par l'utilisateur.

            for(int j=0; j < min(taille_expression_source, (int)tableau.size()-compteur); j++)
            {
                phrase += tableau[compteur+j] + ';';
            }

            phrase.erase(phrase.size()-1);

            // On compare.
            
            if(expression[langue_source] == phrase)
            {
                taille_expression_sortie = (int)count(expression[langue_sortie].begin(), expression[langue_sortie].end(), ';') + 1;
                
                replace(expression[langue_sortie].begin(), expression[langue_sortie].end(), ';', ' ');
                
                return make_tuple(expression[langue_sortie], taille_expression_source, taille_expression_sortie);
            }
        }
        
        // Réinitialisation.
        
        phrase = "";
        taille_expression_source = 0;
    }
    
    return make_tuple("MEM2!65oG", 0, 0); // S'il n'y a pas d'expression.
}
