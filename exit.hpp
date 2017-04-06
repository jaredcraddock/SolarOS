//
//  exit.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef exit_hpp
#define exit_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class exit : public Commands
{
public:
    exit(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver *receiver;
};

#endif /* exit_hpp */
