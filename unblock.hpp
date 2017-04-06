//
//  unblock.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef unblock_hpp
#define unblock_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class unblock : public Commands
{
public:
    unblock(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* unblock_hpp */
