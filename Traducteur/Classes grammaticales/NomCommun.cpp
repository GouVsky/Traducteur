//
//  nomCommun.cpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#include "NomCommun.hpp"

using namespace std;


NomCommun::NomCommun() {}




NomCommun::NomCommun(string genre, string nombre)
{
    _genre = genre;

    _nombre = nombre;
}




NomCommun & NomCommun::operator=(NomCommun nom_commun)
{
    _genre = nom_commun._genre;
    
    _nombre = nom_commun._nombre;
    
    return * this;
}



// Accorde un mot s'il est au pluriel.

void NomCommun::accorder_pluriel(string & mot, string langue)
{
    if (langue == "F")
    {
        if (mot[mot.size() - 1] != 's' && mot[mot.size() - 1] != 'x')
        {
            // Le mot se termine par 'al'.
            
            if (mot.find("al", mot.size() - 2) != -1)
            {
                mot.erase(mot.size() - 2);
                
                mot += "aux";
            }
            
            // Le mot se termine par 'eau'.
            
            else if (mot.find("eau", mot.size() - 3) != -1)
            {
                mot += 'x';
            }
            
            else
            {
                mot += 's';
            }
        }
    }
    
    else if (langue == "A")
    {
        mot += 's';
    }
}
