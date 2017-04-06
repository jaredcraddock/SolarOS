//
//  invoker.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef invoker_hpp
#define invoker_hpp

#include <stdio.h>
#include "Commands.hpp"
#include <vector>

class invoker
{
public:
    invoker();
    void setCommand(int slot, Commands *command);
    void execute(int slot);
    std::vector<Commands*>commandvec;
    Commands* commands;
private:
    
    
    
    
    
};


#endif /* invoker_hpp */
