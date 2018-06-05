//
//  ConstructeurExpression.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "ConstructeurExpression.hpp"

using namespace std;


ConstructeurExpression::ConstructeurExpression()
{
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
        __mots_expression_traduite.clear();
        
        
        fichier >> __expression[config::ANGLAIS] >> __expression[config::FRANCAIS];
        
        
        // On récupère les mots de l'expression source.
        
        vector <string> mots_expression_source;

        istringstream decouper_expression_source(__expression[config::langue_source]);
        
        while (getline(decouper_expression_source, mot, ';'))
        {
            mots_expression_source.push_back(mot);
        }
        
        _taille_source = mots_expression_source.size();
        
        
        // On récupère les mots de l'expression traduite.
        // Celle-ci doit contenir le même nombre de mots que l'expression source.
        
        __mots_expression_traduite.assign(mots_expression_source.begin(), mots_expression_source.begin() + _taille_source);
        
        
        // Comparaison de l'expression avec celle de la phrase.
        
        if (__mots_expression_traduite == mots_expression_source)
        {
            trouve = true;
        }
    }
    
    fichier.close();
    
    return trouve;
}
