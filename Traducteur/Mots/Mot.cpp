//
//  Mot.cpp
//  Traducteur
//
//  Created by Grégoire on 18/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#include "Mot.hpp"

using namespace std;


Mot::Mot() {}




Mot::Mot(string mot)
{
    _mot = mot;
}




Mot & Mot::operator=(Mot mot)
{
    _mot = mot._mot;
    
    __champs_lexicaux = mot.__champs_lexicaux;
    
    return * this;
}




Mot Mot::operator+(Mot mot)
{
    Mot concatenation(_mot + '/' + mot.recuperer_mot());
    
    concatenation.__champs_lexicaux = __champs_lexicaux + mot.__champs_lexicaux;
    
    return concatenation;
}




Mot & Mot::operator+=(Mot mot)
{
    * this = * this + mot;
    
    return * this;
}




void Mot::definir_mot(string mot)
{
    _mot = mot;
}




void Mot::definir_les_differents_champs_lexicaux(ChampsLexicaux champs_lexicaux)
{
    __champs_lexicaux = __champs_lexicaux + champs_lexicaux;
}
