//
//  receiver.cpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "receiver.hpp"




receiver::receiver()
{
    
}


int readyMemory;

void receiver::version()
{
    std::cout<<"Version is 1.3.0!!!!!"<<std::endl;
    

    commandhistory.push_back("version");
}

int receiver::exit()
{
    commandhistory.push_back("exit");
    ::exit(0);
    
}

void receiver::date()
{
    
    
    system("date '+The Current Time:%nYear: %Y%nMonth: %m%nDay: %A%n Hour: %H%nMinute: %M%nSecond: %S'");
    commandhistory.push_back("date");
    
}

void receiver::directory()
{
        std::cout<<"List of files" <<std::endl;
        std::cout<<system( "ls /Users/Jared/Desktop/solarOS/solarOS" );
        commandhistory.push_back("directory");

    
}

void receiver::history()
{
    commandhistory.push_back("history");
    
    for (int i = 0; i < commandhistory.capacity(); i++)
    {
        std::cout<<commandhistory[i]<<std::endl;
    }
}


void receiver::aliasing()
{
    
    commandhistory.push_back("aliasing");
    
}

void receiver::help()
{
    std::cout<<"version: Displays the version of the OS "<<std::endl;
    std::cout<<"date: displays the current date "<<std::endl;
    std::cout<<"directory: displays the current directory "<<std::endl;
    std::cout<<"history: displays a history of commands "<<std::endl;
    std::cout<<"batch: executes a sequence of commands from a txt file "<<std::endl;
    std::cout<<"aliasing: creates an alias a command can be executed by "<<std::endl;
    std::cout <<"exit: exits the program"<<std::endl;
    std::cout <<"help: displays command information"<<std::endl;
    std::cout <<"createPCB: enter a valid integer for process ID and memory, creates a PCB"<<std::endl;
    std::cout <<"deletePCB: enter a valid integer for process ID , deletes a PCB"<<std::endl;
    std::cout <<"block: enter a valid integer for process ID , moves PCB from ready to blocked queue"<<std::endl;
    std::cout <<"unblock: enter a valid integer for process ID , moves PCB from blocked to ready"<<std::endl;
    std::cout <<"showPCB: enter a valid integer for process ID , shows all attributes of a PCB"<<std::endl;
    std::cout <<"showAll: shows the attributes of every process in the system"<<std::endl;
    std::cout <<"showReady: shows the attributes for every process in the ready queue"<<std::endl;
    std::cout <<"showBlocked: shows the attributes for every process in the blocked queue"<<std::endl;
    std::cout <<"generateRandomPCBs: enter a valid integer, creates that # of processes with random ID and Memory"<<std::endl;
    std::cout <<"exec: runs every process through the CPU"<<std::endl;
    std::cout <<"every cycle, processes may be terminated,blocked for IO, or moved back into the ready queue"<<std::endl;
    std::cout <<"every 10th cycle possible for an IO event to be generated"<<std::endl;
    std::cout <<"Ends when ready and blocked queue are empty"<<std::endl;
    std::cout <<"execution process is traced in a file called trace.txt"<<std::endl;
    
    commandhistory.push_back("help");
    
}

void receiver::batch()
{

    commandhistory.push_back("batch");
    
    
    
}

void receiver::setMaxMemory()
{
    
    std::cout<<"Enter max memory of the system"<<std::endl;
    int userInput = 0;
    while (!(std::cin >> userInput))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"invalid try again"<<std::endl;
        
    }
    maxMemory = userInput;
    
    std::cout<<"Please enter a command"<<std::endl;
}

bool receiver::createPCB(int id, int memory, int pcbType)
{
    commandhistory.push_back("createPCB");
    pcb *newPCB = new pcb;
    newPCB->PID = id;
    newPCB->memory = memory;
    newPCB->sentToBlock = 0;
    newPCB->pcbType = pcbType;
    bool error = false;
    
    if (memory > maxMemory)
    {
        error = true;
        std::cout<<"Memory exceeds max memory"<<std::endl;
    }
    
    if (readyMemory > maxMemory)
    {
        error = true;
        std::cout<<"Ready queue memory exceeds max memory, no more processes can be generated"<<std::endl;
        
    }
    
    for (std::deque<pcb>::iterator it = ready.begin(); it!=ready.end(); ++it)
    {
        if (id == it->PID)
        {
            std::cout<<"Error, already exists";
            error = true;
            
        }
    }
    
    for (std::deque<pcb>::iterator it = blocked.begin(); it!=blocked.end(); ++it)
    {
        if (id == it->PID)
        {
            std::cout<<"Duplicate, a process wasn't created " <<std::endl;
            error = true;
            
        }
    }
    
    if (error == false)
    {
     std::cout<<"Created a new process"<<std::endl;
     readyMemory+= newPCB->memory;
     ready.push_back(*newPCB);
        return true;
    }
    
    return false;
}

bool receiver::deletePCB(int id)
{
    commandhistory.push_back("deletePCB");
    bool found = false;
    std::deque<pcb>::iterator it;
    for (it = ready.begin(); it!=ready.end();)
    {
        if (id == it->PID)
        {
          std::cout<<"Process Terminated"<<std::endl;
          std::cout<<"Pid was"<<it->PID<<std::endl;
          std::cout<<"cpuUsageterm was"<<it->cpuUsageTerm<<std::endl;
          std::cout<<"ioRequestTerm was"<<it->ioRequestTerm<<std::endl;
          std::cout<<"Wait term was"<<it->waitingTerm<<std::endl;
            std::cout<<"process type was"<<it->pcbType<<std::endl;
            
                    
            
           it = ready.erase(it);
           found = true;
            return true;
        }
        
        else
        {
            ++it;
        }
    }
    
    std::deque<pcb>::iterator iter;
    for (std::deque<pcb>::iterator iter = blocked.begin(); iter!=blocked.end();)
    {
        if (id == iter->PID)
        {
           iter = ready.erase(iter);
            //std::cout<<"Found, success!";
            found = true;
            return true;
            
        }
        else
        {
            ++iter;
        }
    }
    
    
    if (found == false)
    {
        std::cout<<"Not found!";
        
    }
    return false;
   
}

bool receiver::block(int id)
{
    commandhistory.push_back("block");
    std::deque<pcb>::iterator it ;
    for (it = ready.begin(); it!=ready.end();)
    {
        if (id == it->PID )
        {
            blocked.push_back(*it);
            it =ready.erase(it);
            std::cout<<"blocked, success!"<<std::endl;
            return true;
            
            
        }
        
        else
        {
            ++it;
        }
        
    }
    
    return false;
}

bool receiver::unblock(int id)
{
    commandhistory.push_back("unblock");
    for (std::deque<pcb>::iterator it = blocked.begin(); it!=blocked.end(); ++it)
    {
        if (id == it->PID)
        {
            ready.push_back(*it);
            blocked.erase(it);
            --it;
            std::cout<<"Unblocked, success!";
            return true;
        }
        
        
        
        
    }
    std::cout<<"Failed, did not find process"<<std::endl;

    return false;
}

void receiver::showPCB(int id)
{
    commandhistory.push_back("showPCB");
    bool found = false;
    for (std::deque<pcb>::iterator it = ready.begin(); it!=ready.end(); ++it)
    {
        if (id == it->PID)
        {
            found = true;
            std::cout<<"PID is "<<it->PID<<std::endl;
            std::cout<<"cpuUsageTerm is "<<it->cpuUsageTerm<<std::endl;
            std::cout<<"ioRequestTerm is"<<it->ioRequestTerm<<std::endl;
            std::cout<<"Memory is "<<it->memory<<std::endl;
            std::cout<<"waitingTerm is "<<it->waitingTerm<<std::endl;
            std::cout<<"State is ready"<<std::endl;
            
        }
    }
    
    if (found == false)
    {
        
        for (std::deque<pcb>::iterator it = blocked.begin(); it!=blocked.end(); ++it)
        {
            if (id == it->PID)
            {
                std::cout<<"PID is "<<it->PID<<std::endl;
                std::cout<<"cpuUsageTerm is "<<it->cpuUsageTerm<<std::endl;
                std::cout<<"ioRequestTerm is"<<it->ioRequestTerm<<std::endl;
                std::cout<<"Memory is "<<it->memory<<std::endl;
                std::cout<<"waitingTerm is "<<it->waitingTerm<<std::endl;
                std::cout<<"cycle when sent to block was"<<it->sentToBlock<<std::endl;
                std::cout<<"State is blocked";
                
            }
        }
    }
    
    
    
}

void receiver::showAll()
{
    commandhistory.push_back("showAll");
    std::deque<pcb> showAllQueue;
    std::copy (ready.begin(), ready.end(), std::back_inserter(showAllQueue));
    std::copy (blocked.begin(), blocked.end(), std::back_inserter(showAllQueue));
    
    std::sort(showAllQueue.begin(), showAllQueue.end(), [](pcb a, pcb b) {
        return b.PID > a.PID;
    });
    for (pcb a : showAllQueue) {
        int b = a.PID;
        showPCB(b);
    }
    //std::cout << '\n';
    
}

void receiver::showReady()
{
    commandhistory.push_back("showReady");
    std::cout<<"Current Ready:"<<std::endl;
    
    for (std::deque<pcb>::iterator it = ready.begin(); it!=ready.end(); ++it)
    {
        std::cout<<"PID is "<<it->PID<<std::endl;
        std::cout<<"cpuUsageTerm is "<<it->cpuUsageTerm<<std::endl;
        std::cout<<"ioRequestTerm is"<<it->ioRequestTerm<<std::endl;
        std::cout<<"Memory is "<<it->memory<<std::endl;
        std::cout<<"State is ready"<<std::endl;
        std::cout<<"PCB type is"<<it->pcbType<<std::endl;
        
        
    }

}

void receiver::showBlocked()
{
    commandhistory.push_back("showBlocked");
    std::cout<<"Current Blocked:"<<std::endl;
    
    for (std::deque<pcb>::iterator it = blocked.begin(); it!=blocked.end(); ++it)
    {
        std::cout<<"PID is "<<it->PID<<std::endl;
        std::cout<<"cpuUsageTerm is "<<it->cpuUsageTerm<<std::endl;
        std::cout<<"ioRequestTerm is"<<it->ioRequestTerm<<std::endl;
        std::cout<<"Memory is "<<it->memory<<std::endl;
        std::cout<<"event type is "<<it->eventRequested<<std::endl;
        std::cout<<"time is<"<<it->sentToBlock<<std::endl;
        std::cout<<"State is blocked"<<std::endl;
        
        
    }
    
}

void receiver::generateRandomPCBs(int num)
{
    commandhistory.push_back("generateRandomPCBs");
    
    std::cout<<"Enter the number of processes to generate";
    
    srand (time(NULL) );
    
    for (int i = 0; i < num; i++)
    {
        int id = rand() % 10001;
        int memory = rand() % 200;
        int pcbType = rand () % 3;
        createPCB(id,memory,pcbType);
        
    }
    
}

void receiver::loadProcesses()
{
    std::ifstream processFile;
    processFile.open ("processes.txt");
    int id;
    int memory;
    int timeOfArrival;
    
    while (processFile >> id >> memory >> timeOfArrival)
    {
        createPCB(id, memory, 2 );
    }
    
    processFile.close();
}



void receiver::exec()
{
  
    memorySystem memBlock;
    commandhistory.push_back("exec");
    std::ofstream file;
    std::ifstream fin;
    file.open("trace.txt");
    std::ofstream memoryTrace;
    memoryTrace.open("memoryTrace.txt");
    srand(time(NULL) );
    int random;
    int decision;
    std::string timeStamp;
    int timeCycle = 0;
    bool running = true;
    int method = 0;
    int quantum = 0;
    int queues = 0;
    int temp = 0;
    int avgTurnAround = 0;
    int avgResponseTime = 0;
    int initialSize = 0;
    int cpuUsage = 0;
    char answer;
    bool firstFit = false;
    bool nextFit = false;
    bool bestFit = false;
    bool worstFit = false;
    int nextFitPos  = 0;
    std::string memoryMethod;
    std::cout<<"Run a method on processes from file? Y for yes, something else for no"<<std::endl;
    std::cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        
        std::string input;
        std::string fileName;
        std::cout<<"Enter the filename ""processes.txt"<<std::endl;
        std::cin>>fileName;
        
        fin.open(fileName);
        if(fin.fail())
            std::cout << "File failed to open." << std::endl;
        int a, b, c;
        while (fin>> a >> b >> c)
        {
            createPCB(a, b, c);
        }
        fin.close();
        
    }
    
    std::cout<<"firstFit, nextFit, bestFit, or worstFit?"<<std::endl;
    std::cin >> memoryMethod;
    
    if (memoryMethod == "firstFit")
    {
        firstFit = true;
        memoryTrace << "firstFit method"<<std::endl;
    }
    
    if (memoryMethod == "nextFit")
    {
        nextFit = true;
        memoryTrace << "nextFit method"<<std::endl;
    }
    
    if (memoryMethod == "bestFit")
    {
        bestFit = true;
        memoryTrace << "bestFit method"<<std::endl;
    }
    
    if (memoryMethod == "worstFit")
    {
        worstFit = true;
        memoryTrace << "worstFit method"<<std::endl;
    }
    
    method = 0;
    std::cout<<"Enter 0 for mixed, 1 for RR, 2 for MLFQ"<<std::endl;
    std::cin.clear();
    std::cin >> method;
    if (method == 1)
    {
        std::cout<<"Enter a time quantum"<<std::endl;
        std::cin >> quantum;
    }
    
    if (method == 2)
    {
        std::cout << "Enter the # of queues"<<std::endl;
        std::cin >> queues;
    }
    
   

    
    file <<"Starting ready queue size is"<<ready.size()<<std::endl;
    initialSize = ready.size();
            while (running)
            {
                if (ready.size() == 0)
                {
                    cpuUsage ++;
                }
                file << "new iteration, timecycle + 1"<<std::endl;
                timeCycle++;
                file << "Timecycle is"<<timeCycle<<std::endl;
                
                if(temp == 0)
                {
                    memoryTrace << "hello";
                    cpu = &ready.front();
                    memBlock.pcb = *cpu;
                    memBlock.pcb.PID = -1;
                    memBlock.memory = maxMemory - cpu->memory;
                    memLinkedList.push_back(memBlock);
                
                    file << "set cpu to front of ready queue, cpu's PID is "<<cpu->PID<<std::endl;
                    cpu->arrival = timeCycle;
                    temp++;
                    memBlock.memory = cpu->memory;
                    memBlock.inUse = true;
                    memLinkedList.push_back(memBlock);
                    
                }
                
                
                
                if (ready.size() > 0)
                {
                    
                    if (firstFit)
                    {
                        
                        cpu = &ready.front();
                        
                        
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->memory > cpu->memory && v->inUse == false && v->pcb.PID == -1)
                            {
                                memoryTrace << "Needed to fo find a memory block of atleast size" << cpu->memory << std::endl;
                                memoryTrace << "Found a memory block of size" << v->memory << std::endl;
                                v->memory = v->memory - cpu->memory;
                                memorySystem z;
                                z.pcb.PID = cpu->PID;
                                z.inUse = true;
                                z.memory = cpu->memory;
                                memLinkedList.push_back(z);
                                for (auto v : memLinkedList)
                                {
                                    if (v.inUse == false)
                                    {
                                        memoryTrace << v.memory << " ,";
                                    }
                                    
                                    if (v.inUse == true)
                                    {
                                        memoryTrace << "X";
                                        memoryTrace << " ,";
                                    }
                                }
                                memoryTrace<<"\n";
                                memoryTrace<<"\n";
                                memoryTrace<<"\n";
                                break;
                            }
                            
                            else
                            {
                                
                                std::cout << "We ran out of memory! attempting coalescing" << std::endl;
                                std::list <memorySystem>::iterator v;
                                for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                                {
                                    auto nx = std::next(v);
                                    if (nx->inUse == false && v->inUse == false)
                                    {
                                        v->memory += nx->memory;
                                        memLinkedList.erase(nx);
                                        memoryTrace<< "Did coalescing, Next line = Post-Coalescing" << std::endl;
                                        for (auto v : memLinkedList)
                                        {
                                            if (v.inUse == false)
                                            {
                                                memoryTrace << v.memory << " ,";
                                            }
                                            
                                            if (v.inUse == true)
                                            {
                                                memoryTrace << "X";
                                                memoryTrace << " ,";
                                            }
                                        }
                                        memoryTrace<<"\n";
                                        memoryTrace<<"\n";
                                        memoryTrace<<"\n";
                                        std::cout << "Did coalescing" << std::endl;
                                    }
                                    
                                    
                                }
                            }
                        }
                        
                        
                      
                        
                        
                        
                    }
                   
                    
                    if (bestFit && ready.size() > 0)
                    {
                        int lowest = 0;
                        bool initial = false;
                        bool coalesce = true;
                        cpu = &ready.front();
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            
                            if (v->memory > cpu->memory && v->inUse == false && v->pcb.PID == -1)
                            {
                                if (initial == false)
                                {
                                    lowest = v->memory;
                                    initial = true;
                                }
                                
                                if (v->memory < lowest)
                                {
                                    lowest = v->memory;
                                }
                            }
                            
                            
                        }
                        
                        std::list <memorySystem>::iterator v2;
                        
                        for (v2 = memLinkedList.begin(); v2 != memLinkedList.end(); ++v2)
                        {
                            
                            if (v2->memory == lowest && v2->memory > cpu->memory)
                            {
                                memoryTrace << "Needed to fo find a memory block of atleast size" << cpu->memory << std::endl;
                                memoryTrace << "Found a memory block of size" << v2->memory << std::endl;
                                v2->memory = v2->memory - cpu->memory;
                                memorySystem z;
                                z.pcb.PID = cpu->PID;
                                z.inUse = true;
                                z.memory = cpu->memory;
                                memLinkedList.push_back(z);
                                coalesce = false;
                            }
                            
                            
                            
                        }
                        
                        if (coalesce)
                        {
                            std::cout << "We ran out of memory! attempting coalescing" << std::endl;
                            std::list <memorySystem>::iterator v;
                            for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                            {
                                auto nx = std::next(v);
                                if (nx->inUse == false && v->inUse == false)
                                {
                                    v->memory += nx->memory;
                                    memLinkedList.erase(nx);
                                    memoryTrace<< "Did coalescing, Next line = Post-Coalescing" << std::endl;
                                    for (auto v : memLinkedList)
                                    {
                                        if (v.inUse == false)
                                        {
                                            memoryTrace << v.memory << " ,";
                                        }
                                        
                                        if (v.inUse == true)
                                        {
                                            memoryTrace << "X";
                                            memoryTrace << " ,";
                                        }
                                    }
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                
                                }
                                
                                
                            }
                        }
                        
                        
                       
                        
                        for (auto v : memLinkedList)
                        {
                            if (v.inUse == false)
                            {
                                memoryTrace << v.memory << " ,";
                            }
                            
                            if (v.inUse == true)
                            {
                                memoryTrace << "X";
                                memoryTrace << " ,";
                            }
                        }
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";

                        
                        
                    }
                    
                    if (worstFit && ready.size() > 0)
                    {
                        int highest = 0;
                        bool coalesce = true;
                        cpu = &ready.front();
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            
                            if (v->memory > cpu->memory && v->inUse == false && v->pcb.PID == -1)
                            {
                                
                                    highest = v->memory;
                                
                                
                                if (v->memory > highest)
                                {
                                    highest = v->memory;
                                }
                            }
                            
                            
                        }
                        
                        std::list <memorySystem>::iterator v2;
                        
                        for (v2 = memLinkedList.begin(); v2 != memLinkedList.end(); ++v2)
                        {
                            
                            if (v2->memory == highest && v2->memory > cpu->memory)
                            {
                                memoryTrace << "Needed to fo find a memory block of atleast size" << cpu->memory << std::endl;
                                memoryTrace << "Found a memory block of size" << v2->memory << std::endl;
                                v2->memory = v2->memory - cpu->memory;
                                memorySystem z;
                                z.pcb.PID = cpu->PID;
                                z.inUse = true;
                                z.memory = cpu->memory;
                                memLinkedList.push_back(z);
                                coalesce = false;
                            }
                            
                            
                            
                        }
                        
                        if (coalesce)
                        {
                            std::cout << "We ran out of memory! attempting coalescing" << std::endl;
                            std::list <memorySystem>::iterator v;
                            for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                            {
                                auto nx = std::next(v);
                                if (nx->inUse == false && v->inUse == false)
                                {
                                    v->memory += nx->memory;
                                    memLinkedList.erase(nx);
                                    memoryTrace<< "Did coalescing, Next line = Post-Coalescing" << std::endl;
                                    for (auto v : memLinkedList)
                                    {
                                        if (v.inUse == false)
                                        {
                                            memoryTrace << v.memory << " ,";
                                        }
                                        
                                        if (v.inUse == true)
                                        {
                                            memoryTrace << "X";
                                            memoryTrace << " ,";
                                        }
                                    }
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                    
                                }
                                
                                
                            }
                        }
                        
                        
                        
                        
                        for (auto v : memLinkedList)
                        {
                            if (v.inUse == false)
                            {
                                memoryTrace << v.memory << " ,";
                            }
                            
                            if (v.inUse == true)
                            {
                                memoryTrace << "X";
                                memoryTrace << " ,";
                            }
                        }
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";
                        
                        
                        
                    }
                    
                   
                    if (nextFit && ready.size() > 0)
                    {
                        bool coalesce = true;
                        cpu = &ready.front();
                        
                        std::list <memorySystem>::iterator v;
                        int counter = 0;
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (nextFitPos != 0)
                            {
                                for (int i = 0; i <= nextFitPos; i++)
                                {
                                    v = ++v;
                                }
                            }
                            
                            counter++;
                            if (v->memory > cpu->memory && v->inUse == false && v->pcb.PID == -1)
                            {
                                
                                
                                
                                    memoryTrace << "Needed to find a memory block of atleast size" << cpu->memory << std::endl;
                                    memoryTrace << "Found a memory block of size" << v->memory << std::endl;
                                    v->memory = v->memory - cpu->memory;
                                    memoryTrace << "Old block now has size" << v->memory << std::endl;
                                    memorySystem z;
                                    z.pcb.PID = cpu->PID;
                                    z.inUse = true;
                                    z.memory = cpu->memory;
                                    memLinkedList.push_back(z);
                                    nextFitPos = counter;
                                coalesce = false;
                                    break;
                                
                               
                            }
                            
                            if (counter == memLinkedList.size())
                            {
                                nextFitPos = 0;
                            }
                            
                            
                            
                        }
                        
                        if (coalesce)
                        {
                            std::cout << "We ran out of memory! attempting coalescing" << std::endl;
                            std::list <memorySystem>::iterator v;
                            for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                            {
                                auto nx = std::next(v);
                                if (nx->inUse == false && v->inUse == false)
                                {
                                    v->memory += nx->memory;
                                    memLinkedList.erase(nx);
                                    memoryTrace<< "Did coalescing, Next line = Post-Coalescing" << std::endl;
                                    for (auto v : memLinkedList)
                                    {
                                        if (v.inUse == false)
                                        {
                                            memoryTrace << v.memory << " ,";
                                        }
                                        
                                        if (v.inUse == true)
                                        {
                                            memoryTrace << "X";
                                            memoryTrace << " ,";
                                        }
                                    }
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                    memoryTrace<<"\n";
                                    
                                }
                                
                                
                            }
                        }
                        
                        
                        
                        for (auto v : memLinkedList)
                        {
                            if (v.inUse == false)
                            {
                                memoryTrace << v.memory << " ,";
                            }
                            
                            if (v.inUse == true)
                            {
                                memoryTrace << "X";
                                memoryTrace << " ,";
                            }
                        }
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";
                        memoryTrace<<"\n";

                    }
                    
                    
                    if (method == 2 && ready.size() > 1)
                    {
                        std::sort(ready.begin(), ready.end(), [](pcb a, pcb b) {
                            return b.priority < a.priority;
                        });
                    }
                    
                    
                    
                    
                        if (cpu->cpuUsageTerm == 0)
                        {
                          cpu->cpuUsageTerm = rand() % 10 + 1;
                        }
                    
                    
                    cpu->rrcycles++;
                    if (cpu->priority == 0 && method == 2)
                    {
                      cpu->priority = queues; // top priority initially
                    }
                    cpu->timeSlice ++;
                    
                if (cpu->timeSlice == 10 && method == 2)
                {
                    file << "Demoting this process one queue, pid is" <<cpu->PID<<std::endl;
                    cpu->priority --;
                }
                    
            
                    
                    for (std::deque<pcb>::iterator it = ready.begin(); it!=ready.end(); ++it)
                    {
                        it->waitingTerm += cpu->cpuUsageTerm;
                        it->waitingTerm += 10; // process switch penalty.
                        
                        
                    }
                    file << "updated waiting terms of processes in ready queue"<<std::endl;
                    
                    if (cpu->rrcycles != 0 && cpu->rrcycles == quantum && method == 1)
                    {
                        file <<", Reached RR QUANTUM moving -> "<<cpu->PID<< "back to ready queue"<<std::endl;
                        cpu->rrcycles = 0;
                        ready.push_back(*cpu);
                        ready.pop_front();
                    }
                    
                    if (cpu->rrcycles != 0 && cpu->rrcycles == 100 && method == 2)
                    {
                        for (std::deque<pcb>::iterator it = ready.begin(); it!=ready.end(); ++it)
                        {
                            file <<"Promoting evertyhing up one queue<<std::endl"<<std::endl;
                            it->priority++;
                            
                            
                        }
                       
                    }
                    
                }
                
                if (timeCycle % 10 == 0)
                {
                    timeStamp = std::to_string(timeCycle);
                    
                    random = rand() %11;
                    file << "Reached a 10th time cycle"<<std::endl;
                    if (random == 4)
                    {
                        ioEvent* event = new ioEvent;
                        event->eventType = 2;
                        event->time = timeCycle;
                       eventQueue.push_back(*event);
                        file << "random was 4, created userIO event w/ timestamp "<<timeCycle<<std::endl;
                        
                    }
                    
                    if (random == 9)
                    {
                        ioEvent* eventb = new ioEvent;
                        eventb->eventType = 3;
                        eventb->time = timeCycle;
                        eventQueue.push_back(*eventb);
                        file << "random was 9 ,created hardwareIO event w/ timestamp "<<timeCycle<<std::endl;

                    }
                    
                    if (random != 9 && random != 4)
                    {
                        file<<"random was "<<random<<"did not make new ioevent"<<std::endl;
                    }
                    
                    
                    
                    
                }
                
                
                
                    
                    
                
                
                if (ready.size() > 0 && cpu->pcbType == 0) // interactive
                {
                    file <<"What should we do with this process?"<<std::endl;
                    decision = rand() % 6;
                    cpu->turnAroundTime =  cpu->waitingTerm - cpu->cpuUsageTerm;
                    cpu->responseTime  =  cpu->firstRun ;
                    if (decision == 0)
                    {
                        file <<"random was 0, Deleted process: "<<cpu->PID<<std::endl;
                        avgTurnAround += cpu->turnAroundTime;
                        avgResponseTime+= cpu->responseTime;
                        
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                         
                        }
                        
                        readyMemory -= cpu->memory;
                        deletePCB(cpu->PID);
                        
                    }
                    
                    else if (decision == 1)
                    {
                        file <<"Random was 1, Moving process -> "<<cpu->PID<< "back to ready queue"<<std::endl;
                     
                        ready.push_back(*cpu);
                        ready.pop_front();
                    }
                    
                    else if (decision == 2 || decision == 4)
                    {
                        
                        file <<"Random was 2, process -> "<<cpu->PID<< "moving to blocked to wait for user/IO"<<std::endl;
                        cpu->eventRequested = 2; // user/io
                        cpu->ioRequestTerm = 0;
                        int b = timeCycle;
                        cpu->sentToBlock = b;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory -= cpu->PID;
                        block(cpu->PID);
                        
                        
                        
                    }
                    
                    else if (decision == 3 || decision == 5)
                    {
                        file <<"Random was 3, process -> "<<cpu->PID<< "moving to blocked to wait for hardware/IO"<<std::endl;
                        cpu->eventRequested = 3; // hardware i/o
                        cpu->ioRequestTerm = 0;
                        int a = timeCycle;
                        cpu->sentToBlock = a;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory -= cpu->PID;
                        block(cpu->PID);
                        
                        
                    }
                }
                
                
                if (ready.size() > 0 && cpu->pcbType == 1) // cpubound
                {
                    cpu->turnAroundTime =  cpu->waitingTerm - cpu->cpuUsageTerm;
                    cpu->responseTime  =  cpu->firstRun ;
                    file <<"What should we do with this process?"<<std::endl;
                    decision = rand() % 6;
                    
                    if (decision == 0 || decision == 4)
                    {
                        file <<"random was 0, Deleted process: "<<cpu->PID<<std::endl;
                        avgTurnAround += cpu->turnAroundTime;
                        avgResponseTime+= cpu->responseTime;
                        
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory-= cpu->memory;
                        deletePCB(cpu->PID);
                        
                    }
                    
                    else if (decision == 1 ||  decision == 5)
                    {
                        file <<", Moving process -> "<<cpu->PID<< "back to ready queue"<<std::endl;
                       
                        
                        
                        ready.push_back(*cpu);
                        ready.pop_front();
                    }
                    
                    else if (decision == 2)
                    {
                        file <<"Random was 2, process -> "<<cpu->PID<< "moving to blocked to wait for user/IO"<<std::endl;
                        cpu->eventRequested = 2; // user/io
                        cpu->ioRequestTerm = 0;
                        int b = timeCycle;
                        cpu->sentToBlock = b;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory-= cpu->memory;
                        block(cpu->PID);
                        
                        
                        
                    }
                    
                    else if (decision == 3)
                    {
                        file <<"Random was 3, process -> "<<cpu->PID<< "moving to blocked to wait for hardware/IO"<<std::endl;
                        cpu->eventRequested = 3; // hardware i/o
                        cpu->ioRequestTerm = 0;
                        int a = timeCycle;
                        cpu->sentToBlock = a;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory-= cpu->memory;
                        block(cpu->PID);
                        
                        
                    }
                }
                
                
                
                if (ready.size() > 0 && cpu->pcbType == 2)
                {
                    cpu->turnAroundTime =  cpu->waitingTerm - cpu->cpuUsageTerm;
                    cpu->responseTime  =  cpu->firstRun;
                    file <<"What should we do with this process?"<<std::endl;
                    decision = rand() % 4;
                    
                    if (decision == 0)
                    {
                        file <<"random was 0, Deleted process: "<<cpu->PID<<std::endl;
                        avgTurnAround += cpu->turnAroundTime;
                        avgResponseTime+= cpu->responseTime;
                        
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory-= cpu->memory;
                        deletePCB(cpu->PID);
                        
                    }
                    
                    else if (decision == 1)
                    {
                        file <<"Random was 1, Moving process -> "<<cpu->PID<< "back to ready queue"<<std::endl;
                      
                        ready.push_back(*cpu);
                        ready.pop_front();
                    }
                    
                    else if (decision == 2)
                    {
                        file <<"Random was 2, process -> "<<cpu->PID<< "moving to blocked to wait for user/IO"<<std::endl;
                        cpu->eventRequested = 2; // user/io
                        cpu->ioRequestTerm = 0;
                        int b = timeCycle;
                        cpu->sentToBlock = b;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory -= cpu->memory;
                        block(cpu->PID);
                        
                       
                        
                    }
                    
                    else if (decision == 3)
                    {
                        file <<"Random was 3, process -> "<<cpu->PID<< "moving to blocked to wait for hardware/IO"<<std::endl;
                        cpu->eventRequested = 3; // hardware i/o
                        cpu->ioRequestTerm = 0;
                        int a = timeCycle;
                        cpu->sentToBlock = a;
                        std::list <memorySystem>::iterator v;
                        
                        for (v = memLinkedList.begin(); v != memLinkedList.end(); ++v)
                        {
                            if (v->pcb.PID == cpu->PID)
                            {
                                v->inUse = false;
                                v->pcb.PID = -1;
                                break;
                                
                            }
                            
                            
                        }
                        readyMemory -= cpu->memory;
                        block(cpu->PID);
                        
                        
                    }
                }
            
    
            
    
                if (blocked.size() != 0)
                {
                    for (std::deque<pcb>::iterator it = blocked.begin(); it!=blocked.end(); ++it)
                    {
                        it->ioRequestTerm++;
                        
                    }
                    file <<"Updated ioRequest term for blocked queue processes"<<std::endl;
                    
                }
               
                
               
               
                if (eventQueue.size() != 0 && blocked.size() != 0)
                {
                    bool found = false;
                    std::deque<pcb>::iterator it;
                    std::deque<ioEvent>::iterator iter;
                    for (iter = eventQueue.begin(); iter!=eventQueue.end();)
                    {
                        for (it = blocked.begin(); it!=blocked.end();)
                        {
                            if ((it->eventRequested == iter->eventType && iter->time >= it->sentToBlock))
                            {
                                file <<"Process<<"<<it->PID<<" went into the blocked queue at cycle "<<it->sentToBlock<<std::endl;
                                file <<"It needed an event of type"<<it->eventRequested<<" 2 is user, 3 is hardware"<<std::endl;
                                file <<"Found an event of type"<<iter->eventType<<" that happened at cycle "<<iter->time<<std::endl;
                                file <<"Process"<<it->PID<<" 's io request was handled, moving back to ready queue"<<std::endl;
                                readyMemory+= it->memory;
                                ready.push_back(*it);
                                it = blocked.erase(it);
                                
                            }
                            
                            else
                            {
                                ++it;
                            }
                            
                        }
                        
                        if (found)
                        {
                            file <<"Event is done, deleting from eventQueue"<<std::endl;
                            iter = eventQueue.erase(iter);
                        }
                        else
                        {
                            ++iter;
                        }

                    
                }
                
                
                }
                
                file <<"Ready queue size is"<<ready.size()<<std::endl;
                file <<"blocked queue size is"<<blocked.size()<<std::endl;
                
                if (ready.size() == 0 && blocked.size() == 0)
                {
                    file<<"Ready and blocked queue are empty, we are done!"<<std::endl;
                    running = false;
                    std::cout<<"Average Response time is"<<avgResponseTime / initialSize<<std::endl;
                    std::cout<<"Average TurnAround time is"<<avgTurnAround / initialSize<<std::endl;
                    std::cout<<"Cpu was vacant" << cpuUsage << "cycles out of" << timeCycle << " total cycles"<<std::endl;
                    std::cout << "Check trace.txt and memoryTrace.txt" <<std::endl;
                    
                }
            
                
            
            
}
    
    
    file.close();
    memoryTrace.close();
    
    
}
