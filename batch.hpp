//
//  batch.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef batch_hpp
#define batch_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class batch : public Commands
{
public:
    batch(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* batch_hpp */
