//
//  showReady.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef showReady_hpp
#define showReady_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class showReady : public Commands
{
public:
    showReady(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* showReady_hpp */
