//
//  generateRandomPCBs.cpp
//  SolarOS
//
//  Created by Jared Craddock on 9/21/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "generateRandomPCBs.hpp"


void generateRandomPCBs::execute()
{
    int num;
    std::cout<<"Enter the number of processes to generate"<<std::endl;
    std::cin>>num;
    receiver->generateRandomPCBs(num);
}