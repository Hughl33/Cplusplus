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
#include <string>
#include "Item.h"
class Container {
private:
    std::string ID;
    std::string type;
    std::string desc;
    std::vector<std::string> items;
    int maxSize;
    bool open;
    bool takeable;
public:
    Container(std::string n, std::string t, std::string d, int s, bool o, bool a, std::vector<std::string> i);
    ~Container() {}
    std::string getID();
    std::string getType();
    std::string getDesc();
    void dumpAllItems(std::vector<std::string> i);
    std::vector<std::string> getAllItems();
    std::vector<std::string> emptyInventory();
    void addItem(std::string item);
    void removeItem(std::string name);
    void changeMax(int i);
    void toggleAccess();
    int max();
    int size();
    bool hasItem(std::string item);
    bool empty();
    bool isOpen();
    bool isTakeable();
    std::string save();
};

#endif /* defined(__Zorkish__Container__) */
