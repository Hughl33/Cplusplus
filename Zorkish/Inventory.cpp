//
//  Inventory.cpp
//  Zorkish
//
//  Created by Hugh Lee on 28/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Inventory.h"
Inventory::Inventory() {
    items = *new std::vector<Item>();
}

Item Inventory::getItemByName(std::string name) {
    Item item = *new Item("empty", "empty", "empty");
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == name) item = items[i];
    }
    return item;
}

std::vector<Item> Inventory::getAllItems() {
    return items;
}

void Inventory::addItem(Item item) {
    items.push_back(item);
}

void Inventory::removeItem(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == name) items.erase(i);
    }
}