//
//  Inventory.h
//  Zorkish
//
//  Created by Hugh Lee on 11/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Inventory__
#define __Zorkish__Inventory__

#include <iostream>
#include "Container.h"

class Inventory : public Container {
private:
    std::string bagID;
    bool bag;
public:
    Inventory(std::string b, bool h, int i, std::vector<std::string> items);
    std::string getBagID();
    void getBag(std::vector<std::string> items, int i, std::string b);
    std::vector<std::string> dropBag();
    bool hasBag();
    std::string save(std::string name);
};
#endif /* defined(__Zorkish__Inventory__) */
