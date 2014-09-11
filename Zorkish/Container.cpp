//
//  Container.cpp
//  Zorkish
//
//  Created by Hugh Lee on 28/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Container.h"
Container::Container() {
    items = *new std::vector<Item>();
}

Item Container::getItemByName(std::string name) {
    Item item = *new Item("empty", "empty", "empty");
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == name) item = items[i];
    }
    return item;
}

std::vector<Item> Container::getAllItems() {
    return items;
}

void Container::addItem(Item item) {
    items.push_back(item);
}

void Container::removeItem(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == name) items.erase(items.begin() + i);
    }
}

int Container::size() {
    return (int)items.size();
}

bool Container::empty() {
    return items.empty();
}