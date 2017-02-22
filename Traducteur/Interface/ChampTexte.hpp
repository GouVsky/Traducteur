//
//  champTexte.hpp
//  Traducteur
//
//  Created by Grégoire on 22/12/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef champTexte_hpp
#define champTexte_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "Curseur.hpp"
#include "ZoneTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GChampDeTexte : public GZoneDeTexte
{
    public :
    
    GChampDeTexte();
    std::string recuperer_texte();
    void creer_curseur();
    void traitement();
    void effacer_contenu();
    void afficher();
    
    private :
    
    GCurseur curseur;
    
    int position_x_curseur,
        position_y_curseur;
    
    std::string texte_source;
    
    std::vector <int> parametres_curseur;
};

#endif /* champTexte_hpp */
