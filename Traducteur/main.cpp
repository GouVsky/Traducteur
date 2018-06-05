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

#include "config.hpp"
#include "ConstructeurTexte.hpp"

using namespace std;


int main(int argc, const char * argv[])
{
    string texte = "";

    config::langue_source = config::ANGLAIS;
    config::langue_sortie = config::FRANCAIS;
    
    
    cout << "Entrer un texte à traduire :" << endl << endl;
    
    getline(cin, texte);
    
    texte += '\0';
    
    
    double debut = clock();
    
    // Traduction du texte.
    
    ConstructeurTexte bob_le_bricoleur(texte);

    bob_le_bricoleur.construire_texte();
    
    cout << endl << bob_le_bricoleur.recuperer_texte_traduit() << endl << endl;
    
    cout << "Temps de traduction : " << (clock() - debut) / CLOCKS_PER_SEC << endl << endl;
    
    
    return 0;
}
