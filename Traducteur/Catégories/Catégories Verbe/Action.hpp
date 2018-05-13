//
//  Action.hpp
//  Traducteur
//
//  Created by Grégoire on 26/12/2017.
//  Copyright © 2017 Grégoire. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include <string>
#include <stdio.h>

#include "Verbe.hpp"


class VerbeAction : public Verbe
{
    public :
    
    VerbeAction();
    VerbeAction(std::string propriete);
};

#endif /* Action_hpp */
