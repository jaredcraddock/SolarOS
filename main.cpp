//
//  main.cpp
//  testproj
//
//  Created by Jared Craddock on 8/26/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//



#include <iostream>
#include <string>
#include "client.hpp"

// Execute trace is traced in file trace.txt
// To do test cases, comment out this main and uncomment testMain.

void welcomeMessage();

int main(int argc, const char * argv[]) {
    
  
    client client;
    std::string input;
    welcomeMessage();
    client.setMemory();
    while (std::cin >> input)
    {
       client.osLoop(input);
    }
   
        
    return 0;
    
    }



void welcomeMessage()
{
    std::cout << R"(
                ooo
               / : \
              / o0o \
        _____"~~~~~~~"_____
        \+###|U * * U|###+/
         \...!(.>..<)!.../
        ^^^^o|        |o^^^^
        +=====}:^^^^^:{=====+#
        .____  .|!!!|.  ____.
        |#####:/" " "\:#####|
        |#####=|  O  |=#####|
        |#####>\_____/<#####|
        ^^^^^   | |   ^^^^^
        )";
            std::cout<<"Welcome to Solar OS (Project 4)"<<std::endl;
            std::cout<<"Please enter a command"<<std::endl;
}
