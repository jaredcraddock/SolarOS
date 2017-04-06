//
//  directory.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef directory_hpp
#define directory_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class directory: public Commands
{
public:
    directory(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver *receiver;
};

#endif /* directory_hpp */
