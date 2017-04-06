//
//  deletePCB.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "deletePCB.hpp"

void deletePCB::execute()
{
    int id = 0;
    std::cout<<"Enter ID";
    std::cin >> id;
    receiver->deletePCB(id);
}