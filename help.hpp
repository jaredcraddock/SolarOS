//
//  help.hpp
//  testproj
//
//  Created by Jared Craddock on 8/26/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef help_hpp
#define help_hpp

#include <stdio.h>
#include <iostream>
#include "Commands.hpp"
#include "receiver.hpp"
class help: public Commands
{
    
public:
    help(receiver *receiver) : receiver(receiver) {}
   virtual void execute();
    
private:
    receiver *receiver;
    
};

#endif /* help_hpp */
