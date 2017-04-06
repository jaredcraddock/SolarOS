//
//  block.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class block : public Commands
{
public:
    block(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};
#endif /* block_hpp */
