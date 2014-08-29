//
//  Inventory.h
//  Zorkish
//
//  Created by Hugh Lee on 28/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Inventory__
#define __Zorkish__Inventory__

#include <iostream>
#include <vector>
#include "Item.h"
class Inventory {
private:
    std::vector<Item> items;
public:
    Inventory();
    Item getItemByName(std::string name);
    std::vector<Item> getAllItems();
    void addItem(Item item);
    void removeItem(std::string name);
};

#endif /* defined(__Zorkish__Inventory__) */
