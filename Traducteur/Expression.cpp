//
//  expression.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 14/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include "Expression.h"
#include "ResourcePath.hpp"

using namespace std;


Expression::Expression(string source, string sortie)
{
    _langue_source = source;
    _langue_sortie = sortie;
    
    _taille_expression_source = 0;
    _taille_expression_sortie = 0;
}




// Retourne la taille de l'expression traduite.

int Expression::recuperer_taille_expression_sortie()
{
    return _taille_expression_sortie;
}




// Retourne la taille de l'expression source.

int Expression::recuperer_taille_expression_source()
{
    return _taille_expression_source;
}




// Retourne l'expression traduite.

string Expression::recuperer_expression()
{
    return __expression[_langue_sortie];
}




// Détermine s'il existe une expression dans la phrase.

void Expression::determine_si_existe_une_expression_dans_la_phrase(int compteur, vector <string> tableau)
{
    ifstream monFichierExpressions(resourcePath() + "expressions.txt");

    while (!monFichierExpressions.eof())
    {
        monFichierExpressions >> __expression["A"] >> __expression["F"];
                
        // Si le premier mot de l'expression ne correspond pas au mot de la phrase, cela ne sert à rien de continuer.
        
        if (__expression[_langue_source].substr(0, tableau[compteur].size()) == tableau[compteur])
        {
            // On relève les nombre de mots qui composent l'expression.
            
            _taille_expression_source = (int) count(__expression[_langue_source].begin(), __expression[_langue_source].end(), ';') + 1;
            
            // On construit l'expression avec les mots entrés par l'utilisateur.

            _expression = "";
            
            for (int i = 0; i < min(_taille_expression_source, (int) tableau.size() - compteur); i++)
            {
                _expression += tableau[compteur + i] + ';';
            }

            _expression.erase(_expression.size() - 1);

            // On compare.
            
            if (__expression[_langue_source] == _expression)
            {
                _taille_expression_sortie = (int) count(__expression[_langue_sortie].begin(), __expression[_langue_sortie].end(), ';') + 1;
                
                replace(__expression[_langue_sortie].begin(), __expression[_langue_sortie].end(), ';', ' ');
                
                break;
            }
        }
    }
}
