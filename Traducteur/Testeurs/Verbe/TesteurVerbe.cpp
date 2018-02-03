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




bool TesteurVerbe::comparer(string verbe, vector <Groupe> & groupes)
{
    bool trouve = false;
    
    
    // Comparaison du verbe avec celui de la phrase.
    // Pour cela, on récupère autant de mots traduits précédemment que la taille du verbe construit.
    
    string verbe_dans_phrase;

    size_t taille = __verbe.recuperer_taille();

    size_t indice = groupes.size() - taille + 1;
    
    
    for (size_t i = indice; i < groupes.size(); i++)
    {
        verbe_dans_phrase += groupes[i].recuperer_mot_source() + ' ';
    }
    
    verbe_dans_phrase += verbe;
    
    
    // On récupère toujours le verbe le plus grand.
    
    if (taille > __sauvegarde.recuperer_taille() && __verbe.recuperer_verbe() == verbe_dans_phrase)
    {
        trouve = true;

        __sauvegarde = __verbe;
        
        __sauvegarde.definir_indice_groupe_debut_verbe(indice);
    }
    
    return trouve;
}




bool TesteurVerbe::tester_verbe(string verbe, string langue_source, string langue_sortie, string langue_courante, vector <Groupe> & groupes, DonneesMot & donnees)
{
    ParseurFormeVerbe parseur_formes(langue_source, langue_sortie, "...");
    
    
    bool trouve = false;
    
    size_t nombre_familles = donnees.recuperer_nombre_familles(langue_courante);
    
    
    // On détermine le sujet.
    
    Sujet sujet;
    
    sujet.rechercher_le_sujet(groupes);
    
    
    // On teste chaque famille.
    
    for (int famille = 0; famille < nombre_familles; famille++)
    {
        // On ne réalise le test que si la famille est de type 'Verbe'.
        
        if (donnees.recuperer_famille(langue_courante, famille).recuperer_type().classe() == "VERBE")
        {
            size_t nombre_sens = donnees.recuperer_nombre_sens(langue_courante, famille);

            
            // On teste chaque signification.
            
            for (int sens = 0; sens < nombre_sens; sens++)
            {
                size_t nombre_temps = parseur_formes.recuperer_donnees().recuperer_nombre_formes(langue_courante);
                
                
                // On teste chaque temps.
                
                for (int temps = 0; temps < nombre_temps; temps++)
                {
                    // Construction du verbe.
                    
                    string temps_verbe = parseur_formes.recuperer_donnees().recuperer_temps(langue_courante, temps);
                    
                    vector <string> formes = parseur_formes.recuperer_donnees().recuperer_formes(langue_courante, temps);
                    
                    
                    __verbe.construire_verbe(langue_courante, verbe, formes, temps_verbe, sujet.recuperer_valeur());
                    
                    
                    // La recherche ne s'arrête pas lorsque l'on a trouvé une correspondance.
                    // Il peut exister une construction de taille plus grande.
                    
                    if (comparer(verbe, groupes))
                    {
                        trouve = true;
                    }
                }
            }
        }
    }
    
    return trouve;
}
