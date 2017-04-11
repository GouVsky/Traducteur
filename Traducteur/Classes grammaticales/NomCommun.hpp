//
//  nomCommun.hpp
//  Traducteur
//
//  Created by Grégoire on 26/07/2016.
//  Copyright © 2016 Grégoire. All rights reserved.
//

#ifndef nomCommun_hpp
#define nomCommun_hpp

#include <string>
#include <stdio.h>


class NomCommun
{
    public :
    
    NomCommun();
    std::string recuperer_nombre() const { return _nombre; };
    std::string recuperer_genre() const { return _genre; };
    void accorder_pluriel(std::string & mot, std::string langue);
    
    private :
        
    std::string _genre,
                _nombre;
};

#endif /* nomCommun_hpp */
