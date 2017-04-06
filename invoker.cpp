//
//  invoker.cpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "invoker.hpp"



invoker::invoker()
{
    commandvec.reserve(19);
}



void invoker::setCommand(int slot,Commands* command)
{
    commandvec[slot] = command;
}

void invoker::execute(int slot)
{
    commandvec[slot]->execute();
}