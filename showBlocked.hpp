//
//  showBlocked.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef showBlocked_hpp
#define showBlocked_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class showBlocked : public Commands
{
public:
    showBlocked(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* showBlocked_hpp */
