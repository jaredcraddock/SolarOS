//
//  block.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "block.hpp"

void block::execute()
{
    int id = 0;
    std::cout<<"Enter id";
    std::cin >> id;
    receiver->block(id);
}