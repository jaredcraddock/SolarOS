//
//  exec.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/23/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef exec_hpp
#define exec_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class exec : public Commands
{
public:
    exec(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* exec_hpp */
