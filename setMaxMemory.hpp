//
//  setMaxMemory.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/24/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef setMaxMemory_hpp
#define setMaxMemory_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class setMaxMemory : public Commands
{
public:
    setMaxMemory(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};
#endif /* setMaxMemory_hpp */
