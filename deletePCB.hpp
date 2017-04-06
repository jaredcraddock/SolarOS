//
//  deletePCB.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef deletePCB_hpp
#define deletePCB_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class deletePCB : public Commands
{
public:
    deletePCB(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};
#endif /* deletePCB_hpp */
