//
//  testMain.cpp
//  testproj
//
//  Created by Jared Craddock on 9/2/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//


/*
#define CATCH_CONFIG_MAIN
#include <stdio.h>
#include "catch.hpp"
#include "version.hpp"
#include "Commands.hpp"
#include "help.hpp"
#include "date.hpp"
#include "history.hpp"
#include "directory.hpp"
#include "batch.hpp"
#include "aliasing.hpp"
#include "exit.hpp"
#include "receiver.hpp"
#include "invoker.hpp"
#include "client.hpp"


TEST_CASE("historyVec")
{
    client client;
    REQUIRE(client.historyVec[0] == "history");
    
}

TEST_CASE("verisonVec")
{
    client client;
    REQUIRE(client.versionVec[0] == "version");
    
}

TEST_CASE("dateVec")
{
    client client;
    REQUIRE(client.dateVec[0] == "date");
    
}

TEST_CASE("directoryVec")
{
    client client;
    REQUIRE(client.directoryVec[0] == "directory");
    
}

TEST_CASE("batchVec")
{
    client client;
    REQUIRE(client.batchVec[0] == "batch");
    
}

TEST_CASE("aliasingVec")
{
    client client;
    REQUIRE(client.aliasingVec[0] == "aliasing");
    
}


TEST_CASE("exitVec")
{
    client client;
    REQUIRE(client.exitVec[0] == "exit");
    
}


TEST_CASE("helpVec")
{
    client client;
    REQUIRE(client.helpVec[0] == "help");
    
}

TEST_CASE("versionCommand")
{
    receiver *receiver = new class receiver;
    class version *version = new class version(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(0, version);
    
    REQUIRE(invoker->commandvec[0] == version);
}

TEST_CASE("dateCommand")
{
    receiver *receiver = new class receiver;
    class date *date = new class date(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(1, date);
    
    REQUIRE(invoker->commandvec[1] == date);
}


TEST_CASE("directoryCommand")
{
    receiver *receiver = new class receiver;
    class directory *directory = new class directory(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(2, directory);
    
    REQUIRE(invoker->commandvec[2] == directory);
}


TEST_CASE("historyCommand")
{
    receiver *receiver = new class receiver;
    class history *history = new class history(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(3, history);
    
    REQUIRE(invoker->commandvec[3] == history);
}


TEST_CASE("batchCommand")
{
    receiver *receiver = new class receiver;
    class batch *batch = new class batch(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(4, batch);
    
    REQUIRE(invoker->commandvec[4] == batch);
}


TEST_CASE("aliasingCommand")
{
    receiver *receiver = new class receiver;
    class aliasing *aliasing = new class aliasing(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(5, aliasing);
    
    REQUIRE(invoker->commandvec[5] == aliasing);
}


TEST_CASE("exitCommand")
{
    receiver *receiver = new class receiver;
    class exit *exit = new class exit(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(6, exit);
    
    REQUIRE(invoker->commandvec[6] == exit);
}


TEST_CASE("helpCommand")
{
    receiver *receiver = new class receiver;
    class help *help = new class help(receiver);
    invoker *invoker = new class invoker;
    
    invoker->setCommand(7, help);
    
    REQUIRE(invoker->commandvec[7] == help);
}


TEST_CASE("createPCBFunctionality")
{
    receiver receive;
    REQUIRE(receive.createPCB(5, 5) == true);
    receive.createPCB(5, 5);
    // Duplicate, so should get false
    REQUIRE(receive.createPCB(5, 5) == false);
    receive.maxMemory = 5000;
    // exceeds system memory, should get false.
    REQUIRE(receive.createPCB(5, 5001) == false);
    
}


TEST_CASE("deletePCBFunctionality")
{
    receiver receive;
    receive.createPCB(5, 5);
    REQUIRE(receive.deletePCB(5) == true);
    // doesn't exist, should get false
    REQUIRE(receive.deletePCB(6) == false);
}

TEST_CASE("blockCommandFunctionality")
{
    receiver receive;
    receive.createPCB(1, 1);
    REQUIRE(receive.block(1) == true);
    // Should return false if doesn't exist.
    REQUIRE(receive.block(2) == false);
    // Blocked size should be 1, from when we blocked PID 1
    REQUIRE(receive.blocked.size() == 1);
}

TEST_CASE("unblockCommandFunctionality")
{
    receiver receive;
    receive.createPCB(1, 1);
    receive.block(1);
    // verify process got blocked
    REQUIRE(receive.blocked.size() == 1);
    // verify it unblocked it
    REQUIRE(receive.unblock(1) == true);
    // verify blocked size is now 0, and ready is now 1
    REQUIRE(receive.blocked.size() == 0);
    REQUIRE(receive.ready.size() == 1);
}



TEST_CASE("generateRandomPCBsCommand")
{
    receiver receive;
    receive.generateRandomPCBs(25);
    REQUIRE(receive.ready.size() == 25);
    // if test fails, was because rng duplicated duplicate ID's. processes must have unique id's.
    
}

TEST_CASE("execCommand")
{
    receiver receive;
    receive.generateRandomPCBs(200);
    REQUIRE(receive.ready.size() > 0);
    receive.exec();
    REQUIRE(receive.ready.size() == 0);
    REQUIRE(receive.blocked.size() == 0);
}


*/


