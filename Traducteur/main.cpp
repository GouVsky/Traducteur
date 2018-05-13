//
//  main.cpp
//  Traducteur_universel (Version 1.0 - Hydrogène)
//
//  Created by Grégoire on 13/09/2015.
//  Copyright (c) 2015 Grégoire. All rights reserved.
//

#include <ctime>
#include <string>
#include <iostream>

#include "ConstructeurTexte.hpp"


#define ANGLAIS "A"
#define FRANCAIS "F"

using namespace std;


int main(int argc, const char * argv[])
{
    string texte = "";

    string langue_source = ANGLAIS;
    string langue_sortie = FRANCAIS;
    
    
    cout << "Entrer un texte à traduire :" << endl << endl;
    
    getline(cin, texte);
    
    texte += '\0';
    
    
    double debut = clock();
    
    // Traduction du texte.
    
    ConstructeurTexte bob_le_bricoleur(texte, langue_source, langue_sortie);

    bob_le_bricoleur.construire_texte();
    
    cout << endl << bob_le_bricoleur.recuperer_texte_traduit() << endl << endl;
    
    cout << "Temps de traduction : " << (clock() - debut) / CLOCKS_PER_SEC << endl << endl;
    
    
    return 0;
}
