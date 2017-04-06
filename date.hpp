//
//  date.hpp
//  testproj
//
//  Created by Jared Craddock on 8/28/16.
//  Copyright © 2016 Jared Craddock. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

#include <stdio.h>
#include "Commands.hpp"
#include "receiver.hpp"

class date : public Commands
{
public:
    date(receiver *receiver) : receiver(receiver) {}
    virtual void execute();
    
private:
    receiver* receiver;
};


#endif /* date_hpp */
