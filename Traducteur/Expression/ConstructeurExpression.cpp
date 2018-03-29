//
//  ConstructeurExpression.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "ConstructeurExpression.hpp"

using namespace std;


ConstructeurExpression::ConstructeurExpression(string source, string sortie)
{
    _langue_source = source;
    
    _langue_sortie = sortie;
    
    _taille_source = 0;
}




bool ConstructeurExpression::construire_expression(vector <string> mots)
{
    bool trouve = false;
    
    string mot,
           expression;
    
    ifstream fichier("./Resources/Dictionnaire/expressions.txt");
    
    
    while (!(fichier.eof() || trouve))
    {
        fichier >> __expression["A"] >> __expression["F"];
        
        
        _taille_source = count(__expression[_langue_source].begin(), __expression[_langue_source].end(), ';');
        
        
        // Comparaison de l'expression avec celle de la phrase.
        // Pour cela, on récupère autant de mots que la taille de l'expression du fichier.
        // On effectue un minimum afin de ne pas dépasser la taille du tableau de mots.
        
        for (int i = 0; i < min(_taille_source, mots.size()); i++)
        {
            expression += mots[i] + ';';
        }
        
        
        if (expression == __expression[_langue_source])
        {
            trouve = true;
            
            istringstream decouper_expression(__expression[_langue_sortie]);
            
            
            while (getline(decouper_expression, mot, ';'))
            {
                __mots_expression_traduite.push_back(mot);
            }
        }
    }
    
    fichier.close();
    
    return trouve;
}
