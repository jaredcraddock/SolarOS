//
//  setMaxMemory.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/24/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "setMaxMemory.hpp"

void setMaxMemory::execute()
{
    receiver->setMaxMemory();
}