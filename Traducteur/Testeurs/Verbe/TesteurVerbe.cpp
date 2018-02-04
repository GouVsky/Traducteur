//
//  TesteurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 02/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "TesteurVerbe.hpp"

using namespace std;


TesteurVerbe::TesteurVerbe() {}




bool TesteurVerbe::comparer(string verbe, string verbe_construit, vector <Groupe> & groupes)
{
    bool trouve = false;
    
    
    // Comparaison du verbe avec celui de la phrase.
    // Pour cela, on récupère autant de mots traduits précédemment que la taille du verbe construit.
    
    string verbe_dans_phrase;

    size_t taille = __verbe.calculer_taille(verbe_construit);

    size_t indice = groupes.size() - taille + 1;
    
    
    for (size_t i = indice; i < groupes.size(); i++)
    {
        verbe_dans_phrase += groupes[i].recuperer_mot_source() + ' ';
    }
    
    verbe_dans_phrase += verbe;
    
    
    // On récupère toujours le verbe le plus grand.
    
    if (__verbe.comparer_taille(_sauvegarde, verbe_construit) && verbe_construit == verbe_dans_phrase)
    {
        trouve = true;

        _sauvegarde = verbe_construit;
        
        _indice_groupe_debut_verbe = indice;
    }
    
    return trouve;
}




bool TesteurVerbe::tester_verbe(string verbe, string langue_source, string langue_sortie, vector <Groupe> & groupes, DonneesMot & donnees)
{
    ParseurFormeVerbe parseur_formes(langue_source, langue_sortie, "./Resources/Dictionnaire/Verbes/formes.txt");
    
    
    bool trouve = false;
    
    size_t nombre_familles = donnees.recuperer_nombre_familles(langue_source);
    
    
    // On détermine le sujet.
    
    Sujet sujet;
    
    sujet.rechercher_le_sujet(groupes);
    
    
    // On teste chaque famille.
    
    for (int famille = 0; famille < nombre_familles; famille++)
    {
        // On ne réalise le test que si la famille est de type 'Verbe'.
        
        if (donnees.recuperer_type(famille).classe() == "VERBE")
        {
            size_t nombre_sens = donnees.recuperer_nombre_sens(langue_source, famille);

            
            // On teste chaque signification.
            
            for (int sens = 0; sens < nombre_sens; sens++)
            {
                size_t nombre_temps = parseur_formes.recuperer_donnees().recuperer_nombre_formes(langue_source);
                
                
                // On teste chaque temps.
                
                for (int temps = 0; temps < nombre_temps; temps++)
                {
                    // Construction du verbe.
                    
                    string temps_verbe = parseur_formes.recuperer_donnees().recuperer_temps(langue_source, temps);
                    
                    vector <string> formes = parseur_formes.recuperer_donnees().recuperer_formes(langue_source, temps);
                    
                    
                    string verbe_construit = __verbe.construire_verbe(langue_source, verbe, formes, temps_verbe, sujet.recuperer_valeur());
                    
                    
                    // La recherche ne s'arrête pas lorsque l'on a trouvé une correspondance.
                    // Il peut exister une construction de taille plus grande.
                    
                    if (comparer(verbe, verbe_construit, groupes))
                    {
                        trouve = true;
                        
                        
                        // On traduit le verbe (toutes les significations différentes).
                        
                        size_t nombre_mots = donnees.recuperer_famille(langue_sortie, famille).recuperer_mots().size();
                        
                        for (int mot = 0; mot < nombre_mots; mot++)
                        {
                            string verbe_sortie = donnees.recuperer_famille(langue_sortie, famille).recuperer_mots()[mot].recuperer_mot();
                            
                            string verbe_traduit = __verbe.construire_verbe(langue_sortie, verbe_sortie, formes, temps_verbe, sujet.recuperer_valeur());
                            
                            donnees.recuperer_famille(langue_sortie, famille).recuperer_mots()[mot].recuperer_mot() = verbe_traduit;
                        }
                    }
                }
            }
        }
    }
    
    return trouve;
}
