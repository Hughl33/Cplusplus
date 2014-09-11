//
//  Container.h
//  Zorkish
//
//  Created by Hugh Lee on 28/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Container__
#define __Zorkish__Container__

#include <iostream>
#include <vector>
#include "Item.h"
class Container {
private:
    std::vector<Item> items;
public:
    Container();
    Item getItemByName(std::string name);
    std::vector<Item> getAllItems();
    void addItem(Item item);
    void removeItem(std::string name);
    int size();
    bool empty();
};

#endif /* defined(__Zorkish__Container__) */
