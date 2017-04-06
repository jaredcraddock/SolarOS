//
//  unblock.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "unblock.hpp"

void unblock::execute()
{
    std::cout<<"Enter id of process to unblock"<<std::endl;
    int id = 0;
    std::cin >> id;
    receiver->unblock(id);
}