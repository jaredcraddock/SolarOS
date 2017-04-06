//
//  showAll.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef showAll_hpp
#define showAll_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class showAll : public Commands
{
public:
    showAll(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* showAll_hpp */
