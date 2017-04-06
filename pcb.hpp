//
//  pcb.hpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef pcb_hpp
#define pcb_hpp
#include <queue>


class pcb
{
public:
    pcb();
    int PID;
    int cpuUsageTerm;
    int ioRequestTerm;
    long long waitingTerm;
    int memory;
    int eventRequested;
    int sentToBlock;
    int turnAroundTime;
    int responseTime;
    int pcbType;
    int priority;
    int timeSlice;
    int rrcycles;
    int firstRun;
    int arrival;
};



#endif /* pcb_hpp */
