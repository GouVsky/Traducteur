//
//  nomPropre.hpp
//  Traducteur
//
//  Created by Grégoire on 26/01/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef nomPropre_hpp
#define nomPropre_hpp

#include <string>
#include <stdio.h>

class NomPropre
{
    public :
    
    NomPropre();
    std::string recuperer_genre() const { return _genre; };
    
    private :
    
    std::string _genre;
};

#endif /* nomPropre_hpp */
