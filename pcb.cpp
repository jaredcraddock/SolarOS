//
//  pcb.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "pcb.hpp"
pcb::pcb()
{
    cpuUsageTerm = 0;
    ioRequestTerm = 0;
    waitingTerm = 0;
    sentToBlock = 0;
    
}