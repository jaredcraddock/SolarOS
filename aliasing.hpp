//
//  aliasing.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef aliasing_hpp
#define aliasing_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class aliasing : public Commands
{
public:
    aliasing(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};

#endif /* aliasing_hpp */
