//
//  verbe.cpp
//  Traducteur_universel
//
//  Created by Grégoire on 20/09/2015.
//  Copyright © 2015 Grégoire. All rights reserved.
//

#include "Verbe.hpp"

using namespace std;


string Verbe::recuperer_forme_verbe_irregulier(string langue, string temps, int sujet)
{
    transform(langue.begin(), langue.end(), langue.begin(), ::tolower);
    
    string fichier = "./Resources/Dictionnaire/Verbes/Irreguliers/" + langue + ".txt";
    
    return 0;
}




string Verbe::construire_verbe(string mot, vector <Mot> & verbes, vector <Groupe> & groupes, vector <vector <Mot>> & verbes_sorties, DonneesFormeVerbe & donnees)
{
    /*// On détermine au préalable le sujet.
    
    Sujet::rechercher_le_sujet(groupes);
    
    
    // Sauvegarde des différents paramètres.
    
    string sauvegarde_temps;
    
    size_t sauvegarde_indice = 0;
    
    vector <string> sauvegarde_forme;
    
    
    bool trouve = false;
    
    size_t taille_max = 0;
    
    size_t nombre_groupes = groupes.size();
    
    size_t nombre_verbes = verbes.size();
    
    
    size_t nombre_formes = donnees.recuperer_nombre_formes("");
    
    
    // Pour tous les sens possibles, on teste lequel correspond à celui de la phrase.
    
    for (int i = 0; i < nombre_verbes; i++)
    {
        for (int j = 0; j < nombre_formes; j++)
        {
            string verbe_dans_phrase;
            
            string verbe = construire_verbe(_langue_source, verbes[i].recuperer_mot(), __parseur_forme.recuperer_formes(_langue_source)[j], __parseur_forme.recuperer_temps(_langue_source)[j]);
            
            size_t taille = count(verbe.begin(), verbe.end(), ' ') + 1;
            
            
            // Comparaison du verbe avec celui de la phrase.
            // On construit le verbe avec les mots précédents et le mot actuel.
            
            size_t indice = nombre_groupes - taille + 1;
            
            
            for (size_t k = indice; k < nombre_groupes; k++)
            {
                verbe_dans_phrase += groupes[k].recuperer_mot_source() + ' ';
            }
            
            verbe_dans_phrase += mot;
            
            
            // On récupère toujours la forme du verbe la plus grande.
            
            if (verbe_dans_phrase == verbe && taille > taille_max)
            {
                taille_max = taille;
                
                sauvegarde_indice = indice;
                
                sauvegarde_forme = __parseur_forme.recuperer_formes(_langue_sortie)[j];
                
                sauvegarde_temps = __parseur_forme.recuperer_temps(_langue_sortie)[j];
                
                trouve = true;
            }
        }
    }
    
    if (trouve)
    {
        // On supprime les groupes de mots qui font en fait partis du verbe.
        
        groupes.erase(groupes.begin() + sauvegarde_indice, groupes.end());
        
        
        // On conjugue tous les sens du verbe source.
        
        for (int j = 0; j < verbes_sorties.size(); j++)
        {
            for (int k = 0; k < verbes_sorties[j].size(); k++)
            {
                verbes_sorties[j][k].recuperer_mot() = construire_verbe(_langue_sortie, verbes_sorties[j][k].recuperer_mot(), sauvegarde_forme, sauvegarde_temps);
            }
        }
    }*/
    
    return 0;
}
