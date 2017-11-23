//
//  ParseurFormeVerbe.hpp
//  Traducteur
//
//  Created by Grégoire on 16/11/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef ParseurFormeVerbe_hpp
#define ParseurFormeVerbe_hpp

#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

class ParseurFormeVerbe
{
    public :
    
    ParseurFormeVerbe();
    std::vector <std::string> recuperer_forme() { return __forme_decoupee; };
    void parser(std::string forme_verbe);
    
    private :
    
    std::vector <std::string> __forme_decoupee;
};

#endif /* ParseurFormeVerbe_hpp */
