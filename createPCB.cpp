//
//  createPCB.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "createPCB.hpp"

void createPCB::execute()
{
    int id = 0;
    int memory = 0;
    int pcbType = 0;
    std::cout<<"Enter ID"<<std::endl;
    std::cin >> id;
    std::cout<<"Enter memory"<<std::endl;
    std ::cin >> memory;
    std::cout<<"Enter cpu type, 0 for interactive, 1 for cpuBound, 2 for mixed"<<std::endl;
    std::cin >>pcbType;
    receiver->createPCB(id, memory,pcbType);
}