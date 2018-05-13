//
//  Type.cpp
//  Traducteur
//
//  Created by Grégoire on 16/06/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Type.hpp"

using namespace std;


Type::Type() {}




Type::Type(vector <string> type)
{
    _classe = type[0];
    
    _categorie = (type.size() > 1) ? type[1] : "";
    
    _propriete = (type.size() > 2) ? type[2] : "";
    
    
    if (_classe == "NOM")
    {
        if (_categorie == "COMMUN")
        {
            __types.commun = new Commun;
        }
        
        else if (_categorie == "PROPRE")
        {
            __types.propre = new Propre;
        }
    }
    
    else if (_classe == "VERBE")
    {
        if (_categorie == "ACTION")
        {
            __types.action = new VerbeAction(_propriete);
        }
    }
    
    else if (_classe == "PRONOM")
    {
        __types.pronom = new Pronom;
    }
    
    else if (_classe == "ADJECTIF")
    {
        __types.adjectif = new Adjectif;
    }
    
    else if (_classe == "INVARIABLE")
    {
        __types.invariable = new Invariable;
    }
}




Type Type::operator+(Type type)
{
    _classe += '/' + type._classe;
    
    _categorie += '/' + type._categorie;
    
    _propriete += '/' + type._propriete;
    
    
    return * this;
}




void Type::definir_classe(string classe)
{
    _classe = classe;
}




void Type::definir_categorie(string categorie)
{
    _categorie = categorie;
}




void Type::definir_propriete(string propriete)
{
    _propriete = propriete;
}
