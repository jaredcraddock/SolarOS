//
//  history.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef history_hpp
#define history_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class history : public Commands
{
    
public:
    history(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver *receiver;
};

#endif /* history_hpp */
