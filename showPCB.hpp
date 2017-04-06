//
//  showPCB.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef showPCB_hpp
#define showPCB_hpp

#include <stdio.h>
#include "receiver.hpp"
#include "Commands.hpp"
class showPCB : public Commands
{
public:
    showPCB(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};
#endif /* showPCB_hpp */
