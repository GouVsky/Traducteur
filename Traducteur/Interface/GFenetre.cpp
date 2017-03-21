//
//  fenetre.cpp
//  Traducteur
//
//  Created by Grégoire on 05/02/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//


#include "GImage.hpp"
#include "GFenetre.hpp"
#include "ResourcePath.hpp"

using namespace sf;
using namespace std;


RenderWindow GFenetre::fenetre;

vector <Event> GFenetre::queue;

int GFenetre::element_dans_la_queue = 0;


// Initialisation des différents éléments.

GFenetre::GFenetre() {}




// On récupère les évènements stockés dans une queue.

Event * GFenetre::getEvent()
{
    if (queue.size() > element_dans_la_queue)
    {
        element_dans_la_queue++;
        
        return &queue[element_dans_la_queue - 1];
    }
        
    return nullptr;
}




RenderWindow * GFenetre::getWindow()
{
    return &fenetre;
}




void GFenetre::display()
{
    fenetre.display();
}




void GFenetre::close()
{
    fenetre.close();
}




bool GFenetre::pollEvent(Event & event)
{
    if (fenetre.pollEvent(event))
    {
        queue.push_back(event);

        return true;
    }
    
    return false;
}




bool GFenetre::isOpen()
{
    return fenetre.isOpen();
}




void GFenetre::clear()
{
    fenetre.clear(Color::White);
}




void GFenetre::create(int width, int height, string title, Uint32 style)
{
    fenetre.create(VideoMode(width, height, 32), title, style);
}
