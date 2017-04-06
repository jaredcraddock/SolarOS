//
//  receiver.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef receiver_hpp
#define receiver_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "dirent.h"
#include <vector>
#include <fstream>
#include "pcb.hpp"
#include <deque>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <list>
#include "ioEvent.hpp"
class receiver
{
public:
    receiver();
    void version();
    void date();
    void directory();
    void history();
    void batch();
    void aliasing();
    int exit();
    void help();
    bool createPCB(int id, int memory, int pcbType);
    bool deletePCB(int id);
    bool block(int id);
    bool unblock(int id);
    void showPCB(int id);
    void showAll();
    void showReady();
    void showBlocked();
    void generateRandomPCBs(int num);
    void exec();
    void setMaxMemory();
    void loadProcesses();
    pcb *cpu;
    std::deque <pcb> ready;
    std::deque <pcb> blocked;
    std::deque <ioEvent> eventQueue;
    int maxMemory;
    struct memorySystem
    {
        pcb pcb;
        int memory;
        bool inUse = false;
    };
    std::list<memorySystem> memLinkedList;
    
    
    
    
private:
    std::vector <std::string> commandhistory;
    
};

#endif /* receiver_hpp */
