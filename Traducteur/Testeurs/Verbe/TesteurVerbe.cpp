//
//  TesteurVerbe.cpp
//  Traducteur
//
//  Created by Grégoire on 02/02/2018.
//  Copyright © 2018 Grégoire. All rights reserved.
//

#include "TesteurVerbe.hpp"

using namespace std;


TesteurVerbe::TesteurVerbe(string langue_source, string langue_sortie) : __parseur_formes(langue_source, langue_sortie, "./Resources/Dictionnaire/Verbes/formes.txt")
{
    _langue_source = langue_source;
    
    _langue_sortie = langue_sortie;
    
    __donnees_formes_verbes = __parseur_formes.parser();
}




bool TesteurVerbe::comparer(string verbe, vector <string> verbes_construits, vector <Groupe> & groupes)
{
    bool trouve = false;
    
    
    // Comparaison des verbes avec celui de la phrase.
    // Pour cela, on récupère autant de mots traduits précédemment que la taille du verbe construit.
    // (En fait "taille - 1" car on prend le mot courant).
    
    for (int i = 0; i < verbes_construits.size(); i++)
    {
        string verbe_dans_phrase;
        
        size_t taille = __verbe->calculer_taille(verbes_construits[i]);
        
        size_t indice = groupes.size() - taille + 1;
        
        
        for (size_t j = indice; j < groupes.size(); j++)
        {
            verbe_dans_phrase += groupes[j].recuperer_mot_source() + ' ';
        }
        
        verbe_dans_phrase += verbe;
        
        
        // On récupère toujours le verbe le plus grand.
        
        if (__verbe->comparer_taille(_verbe_construit, verbes_construits[i]) && verbes_construits[i] == verbe_dans_phrase)
        {
            trouve = true;
            
            _verbe_construit = verbes_construits[i];
        }
    }
    
    return trouve;
}




vector <string> TesteurVerbe::construction(DonneesMot & donnees, string langue, int temps, int famille, int mot)
{
    string temps_verbe = __donnees_formes_verbes.recuperer_temps(langue, temps);

    vector <string> formes = __donnees_formes_verbes.recuperer_formes(langue, temps);
    
    string verbe = donnees.recuperer_famille(langue, famille).recuperer_mot(mot).recuperer_mot();
    
    
    return __verbe->construire_verbe(langue, verbe, formes, temps_verbe, __donnees_verbe.recuperer_groupe(langue), _sujet);
}




bool TesteurVerbe::tester_verbe(string verbe, vector <Groupe> & groupes, DonneesMot & donnees)
{
    bool trouve = false;
        
    size_t nombre_familles = donnees.recuperer_nombre_familles(_langue_source);
    
    
    // On détermine le sujet du verbe.
    
    _sujet = Sujet::recuperer_valeur_sujet(groupes);
    

    // On teste chaque famille.
    
    for (int famille = 0; famille < nombre_familles; famille++)
    {
        if (donnees.recuperer_type(famille).recuperer_classe() == "VERBE")
        {
            __donnees_verbe.reinitialisation();
            
            
            size_t nombre_sens = donnees.recuperer_nombre_sens(_langue_source, famille);
            

            if (donnees.recuperer_type(famille).recuperer_categorie() == "ACTION")
            {
                __verbe = donnees.recuperer_type(famille).recuperer_structure_types().action;
            }
            
            else if (donnees.recuperer_type(famille).recuperer_categorie() == "ATTRIBUTIF")
            {
                __verbe = donnees.recuperer_type(famille).recuperer_structure_types().attributif;
            }
            
            
            __donnees_verbe.ajouter_groupe(_langue_source, __verbe->recuperer_groupe(_langue_source));
            
            __donnees_verbe.ajouter_groupe(_langue_sortie, __verbe->recuperer_groupe(_langue_sortie));

            
            // On teste chaque signification.
            
            for (int sens = 0; sens < nombre_sens; sens++)
            {
                size_t nombre_temps = __donnees_formes_verbes.recuperer_nombre_formes(_langue_source);
                
                
                // On teste chaque temps.
                
                for (int temps = 0; temps < nombre_temps; temps++)
                {
                    vector <string> verbes_construits = construction(donnees, _langue_source, temps, famille, sens);
                    
                    
                    // La recherche ne s'arrête pas lorsque l'on a trouvé une correspondance.
                    // Il peut exister une construction de taille plus grande.
                    
                    if (comparer(verbe, verbes_construits, groupes))
                    {
                        trouve = true;
                        
                        
                        // On traduit toutes les significations différentes du verbe.
                        
                        size_t nombre_mots = donnees.recuperer_nombre_sens(_langue_sortie, famille);
                        
                        
                        for (int mot = 0; mot < nombre_mots; mot++)
                        {
                            vector <string> verbes_traduits = construction(donnees, _langue_sortie, temps, famille, sens);
                            
                            
                            donnees.recuperer_famille(_langue_sortie, famille).recuperer_mot(mot).definir_mot(verbes_traduits[0]);
                            
                            __donnees_verbe.ajouter_verbe_source(_verbe_construit);
                            
                            __donnees_verbe.ajouter_verbe_traduit(verbes_traduits[0]);
                            
                            __donnees_verbe.ajouter_indice_groupe_debut_verbe(__verbe->calculer_taille(_verbe_construit) - 1);
                        }
                    }
                }
            }
        }
    }
    
    return trouve;
}
