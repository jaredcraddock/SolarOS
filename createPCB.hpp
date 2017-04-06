//
//  createPCB.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef createPCB_hpp
#define createPCB_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class createPCB : public Commands
{
public:
    createPCB(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* createPCB_hpp */
