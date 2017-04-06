//
//  client.cpp
//  testproj
//
//  Created by Jared Craddock on 9/1/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#include "client.hpp"

client::client()
{
    
    invoker->setCommand(0, version);
    invoker->setCommand(1, date);
    invoker->setCommand(2, directory);
    invoker->setCommand(3, history);
    invoker->setCommand(4, batch);
    invoker->setCommand(5, aliasing);
    invoker->setCommand(6, exit);
    invoker->setCommand(7, help);
    invoker->setCommand(8, createPCB);
    invoker->setCommand(9, deletePCB);
    invoker->setCommand(10, block);
    invoker->setCommand(11, unblock);
    invoker->setCommand(12, showPCB);
    invoker->setCommand(13, showAll);
    invoker->setCommand(14, showReady);
    invoker->setCommand(15, showBlocked);
    invoker->setCommand(16, generateRandomPCBs);
    invoker->setCommand(17, exec);
    invoker->setCommand(18, setMaxMemory);
    invoker->setCommand(19, loadProcesses);
    
    
}


void client::setMemory()
{
    invoker->execute(18);
}

void client::osLoop(std::string input)

{
    
    
    if (std::find(commandVecs.begin(), commandVecs.end(), input) == commandVecs.end())
    {
        std::cout<<"Invalid command"<<std::endl;
    }
    
    
    for (int i = 0; i <= versionVec.capacity(); i ++)
    {
        if (input == versionVec[i])
        {
            invoker->execute(0);
        }
   
        
    }
    
    
    
    
    for (int i = 0; i <= dateVec.capacity(); i ++)
    {
        if (input == dateVec[i])
        {
            invoker->execute(1);
        }
    }
    
    for (int i = 0; i <= versionVec.capacity(); i ++)
    {
        if (input == directoryVec[i])
        {
            invoker->execute(2);
        }
    }
    
    for (int i = 0; i <= historyVec.capacity(); i ++)
    {
        if (input == historyVec[i])
        {
            invoker->execute(3);
        }
    }
    
    for (int i = 0; i <= batchVec.capacity(); i ++)
    {
        if (input == batchVec[i])
        {
            invoker->execute(4);
        }
    }
    
    
    for (int i = 0; i <= aliasingVec.capacity(); i ++)
    {
        if (input == aliasingVec[i])
        {
            invoker->execute(5);
        }
    }
    
    for (int i = 0; i <= exitVec.capacity(); i ++)
    {
        if (input == exitVec[i])
        {
            char confirm;
            std::cout<<"Are you sure you want to exit? 'y' to confirm"<<std::endl;
            std::cin >> confirm;
            if (confirm == 'y')
            {
                invoker->execute(6);
            }
            
            else
                std::cout<<"Solar OS is still running woo!!"<<std::endl;
            
        }
    }
    
    for (int i = 0; i <= helpVec.capacity(); i ++)
    {
        if (input == helpVec[i])
        {
            invoker->execute(7);
        }
    }
    
    for (int i = 0; i <= createPCBVec.capacity(); i ++)
    {
        if (input == createPCBVec[i])
        {
            invoker->execute(8);
        }
    }
    
    for (int i = 0; i <= deletePCBVec.capacity(); i ++)
    {
        if (input == deletePCBVec[i])
        {
            invoker->execute(9);
        }
    }
    
    for (int i = 0; i <= blockVec.capacity(); i ++)
    {
        if (input == blockVec[i])
        {
            invoker->execute(10);
        }
    }
    
    for (int i = 0; i <= unblockVec.capacity(); i ++)
    {
        if (input == unblockVec[i])
        {
            invoker->execute(11);
        }
    }
    
    for (int i = 0; i <= showPCBVec.capacity(); i ++)
    {
        if (input == showPCBVec[i])
        {
            invoker->execute(12);
        }
    }
    
    for (int i = 0; i <= showAllVec.capacity(); i ++)
    {
        if (input == showAllVec[i])
        {
            invoker->execute(13);
        }
    }
    
    for (int i = 0; i <= showReadyVec.capacity(); i ++)
    {
        if (input == showReadyVec[i])
        {
            invoker->execute(14);
        }
    }
    
    for (int i = 0; i <= showBlockedVec.capacity(); i ++)
    {
        if (input == showBlockedVec[i])
        {
            invoker->execute(15);
        }
    }
    
    for (int i = 0; i <= generateRandomPCBsVec.capacity(); i ++)
    {
        if (input == generateRandomPCBsVec[i])
        {
            invoker->execute(16);
        }
    }
    
    for (int i = 0; i <= execVec.capacity(); i ++)
    {
        if (input == execVec[i])
        {
            invoker->execute(17);
        }
    }
    
    for (int i = 0; i <= setMaxMemoryVec.capacity(); i ++)
    {
        if (input == setMaxMemoryVec[i])
        {
            invoker->execute(18);
        }
    }
    
    for (int i = 0; i <= loadProcessesVec.capacity(); i ++)
    {
        if (input == loadProcessesVec[i])
        {
            invoker->execute(19);
        }
    }

    
    if (input == "batch")
    {
        std::ifstream fin;
        std::string input;
        std::string fileName;
        std::cout<<"Enter the filename with the extension"<<std::endl;
        std::cin>>fileName;
        fin.open(fileName);
        if(fin.fail())
            std::cout << "File failed to open." << std::endl;
        while (std::getline(fin, input))
        {
            osLoop(input);
            
        }
    }
    
    if (input == "aliasing")
    {
        std::cout<<"Enter the name of the new command name of your choice"<<std::endl;
        std::string newName;
        std::string command;
        std::cin >> newName;
        while (std::find(commandVecs.begin(), commandVecs.end(), newName) != commandVecs.end())
        {
            std::cout<<"Command is already mapped; try again"<<std::endl;
            std::cin>>newName;
        }
        std::cout<<"Enter the name of the command you wish to rename"<<std::endl;
        std::cin >> command;
        while (std::find(commandVecs.begin(), commandVecs.end(), command) == commandVecs.end())
        {
            std::cout<<"Error: Command isn't in the solar system!"<<std::endl;
            std::cin>>command;
        }
        
        
        if (command == "version")
        {
            versionVec.push_back(newName);
            commandVecs.push_back(newName);
            
        }
        
        if (command == "date")
        {
            dateVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "directory")
        {
            directoryVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "history")
        {
            historyVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        
        if (command == "batch")
        {
            batchVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "aliasing")
        {
            aliasingVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "exit")
        {
            exitVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "help")
        {
            helpVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "createPCB")
        {
            createPCBVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "deletePCB")
        {
            deletePCBVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "block")
        {
            blockVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "unblock")
        {
            unblockVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "showPCB")
        {
            showPCBVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "showAll")
        {
            showAllVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "showReady")
        {
            showReadyVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "showBlocked")
        {
            showBlockedVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "generateRandomPCBs")
        {
            generateRandomPCBsVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "exec")
        {
            execVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        if (command == "setMaxMemory")
        {
            setMaxMemoryVec.push_back(newName);
            commandVecs.push_back(newName);
        }
        
        
        input.clear();
    }
    std::cout<<"Please enter a command"<<std::endl;
    
}

