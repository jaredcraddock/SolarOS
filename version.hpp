//
//  version.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef version_hpp
#define version_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class version : public Commands
{
public:
    version(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver *receiver;
    
};

#endif /* version_hpp */
