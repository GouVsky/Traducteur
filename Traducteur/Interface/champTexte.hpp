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

#include "curseur.hpp"
#include "zoneTexte.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GChampDeTexte : public GZoneDeTexte
{
    public :
    
    GChampDeTexte();
    int recuperer_taille_texte();
    std::string recuperer_texte();
    void creer_curseur();
    void traitement();
    void effacer_contenu();
    void afficher();
    
    private :
    
    GCurseur curseur;
    
    sf::RenderTexture texture;
    
    int position_x_curseur,
        position_y_curseur;
    
    std::vector <int> parametres_curseur;
};

#endif /* champTexte_hpp */
