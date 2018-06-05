//
//  config.cpp
//  Traducteur
//
//  Created by Grégoire on 04/06/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "config.hpp"

using namespace std;


int config::langue_source = -1;
int config::langue_sortie = -1;

string config::fichier_mots = "./Resources/Dictionnaire/mots.txt";
string config::fichier_formes = "./Resources/Dictionnaire/Verbes/formes.txt";
string config::fichier_expressions = "./Resources/Dictionnaire/expressions.txt";
string config::dossier_terminaisons = "./Resources/Dictionnaire/Terminaisons/";
