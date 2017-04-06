//
//  loadProcesses.hpp
//  SolarOS
//
//  Created by Jared Craddock on 11/14/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef loadProcesses_hpp
#define loadProcesses_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"
class loadProcesses : public Commands
{
public:
    loadProcesses(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};


#endif /* loadProcesses_hpp */
