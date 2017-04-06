//
//  generateRandomPCBs.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef generateRandomPCBs_hpp
#define generateRandomPCBs_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class generateRandomPCBs : public Commands
{
public:
    generateRandomPCBs(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};


#endif /* generateRandomPCBs_hpp */
