//
//  client.hpp
//  testproj
//
//  Created by Jared Craddock on 9/1/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef client_hpp
#define client_hpp

#include <stdio.h>
#include <iostream>
#include "Commands.hpp"
#include "help.hpp"
#include "receiver.hpp"
#include "invoker.hpp"
#include "history.hpp"
#include "version.hpp"
#include "exit.hpp"
#include "date.hpp"
#include "directory.hpp"
#include "batch.hpp"
#include "aliasing.hpp"
#include "setMaxMemory.hpp"
#include "createPCB.hpp"
#include "deletePCB.hpp"
#include "block.hpp"
#include "unblock.hpp"
#include "showPCB.hpp"
#include "showAll.hpp"
#include "showReady.hpp"
#include "showBlocked.hpp"
#include "generateRandomPCBs.hpp"
#include "exec.hpp"
#include "loadProcesses.hpp"
#include <string>
#include <fstream>
#include <algorithm>

class client
{
public:
    client();
    void osLoop(std::string input);
    void setMemory();
    
    // Only made these public because of catch unit testing.
    std::vector<std::string> versionVec = {"version"};
    std::vector<std::string> dateVec = {"date"};
    std::vector<std::string> directoryVec = {"directory"};
    std::vector<std::string> historyVec = {"history"};
    std::vector<std::string> batchVec = {"batch"};
    std::vector<std::string> aliasingVec = {"aliasing"};
    std::vector<std::string> exitVec = {"exit"};
    std::vector<std::string> helpVec = {"help"};
    std::vector<std::string> createPCBVec = {"createPCB"};
    std::vector<std::string> deletePCBVec = {"deletePCB"};
    std::vector<std::string> blockVec = {"block"};
    std::vector<std::string> unblockVec = {"unblock"};
    std::vector<std::string> showPCBVec = {"showPCB"};
    std::vector<std::string> showAllVec = {"showAll"};
    std::vector<std::string> showReadyVec = {"showReady"};
    std::vector<std::string> showBlockedVec = {"showBlocked"};
    std::vector<std::string> generateRandomPCBsVec = {"generateRandomPCBs"};
    std::vector<std::string> execVec = {"exec","execute"};
    std::vector<std::string> setMaxMemoryVec = {"setMaxMemory"};
    std::vector<std::string> loadProcessesVec = {"loadProcesses"};
    
    std::vector<std::string> commandVecs = {"version","date","directory","history","batch","aliasing","exit","help","setMaxMemory","createPCB","deletePCB","block","unblock"
    ,"showPCB","showAll","showReady","showBlocked","generateRandomPCBs","exec","execute","loadProcesses"};
   
    
private:
    
    receiver *receiver = new class receiver;
    class history *history = new class history(receiver);
    class version *version = new class version(receiver);
    class exit *exit = new class exit(receiver);
    class date *date = new class date(receiver);
    class batch *batch = new class batch(receiver);
    class aliasing *aliasing = new class aliasing(receiver);
    class directory *directory = new class directory(receiver);
    class help *help = new class help(receiver);
    class createPCB *createPCB= new class createPCB(receiver);
    class deletePCB *deletePCB= new class deletePCB(receiver);
    class block *block= new class block(receiver);
    class unblock *unblock= new class unblock(receiver);
    class showPCB *showPCB= new class showPCB(receiver);
    class showAll *showAll= new class showAll(receiver);
    class showReady *showReady= new class showReady(receiver);
    class showBlocked *showBlocked= new class showBlocked(receiver);
    class generateRandomPCBs *generateRandomPCBs= new class generateRandomPCBs(receiver);
    class exec *exec= new class exec(receiver);
    class setMaxMemory *setMaxMemory = new class setMaxMemory(receiver);
    class loadProcesses *loadProcesses = new class loadProcesses(receiver);
    
    
    invoker *invoker = new class invoker;
    
    
    
};


#endif /* client_hpp */
