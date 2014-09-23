//
//  Container.cpp
//  Zorkish
//
//  Created by Hugh Lee on 28/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Container.h"

Container::Container(std::string n, std::string t, std::string d, int s, bool o, bool a, std::vector<std::string> i) {
    ID = n;
    type = t;
    desc = d;
    items = i;
    maxSize = s;
    open = o;
    takeable = a;
}

std::string Container::getID() {
    return ID;
}

std::string Container::getType() {
    return type;
}

std::string Container::getDesc() {
    return desc;
}

void Container::dumpAllItems(std::vector<std::string> i) {
    items = i;
}

std::vector<std::string> Container::getAllItems() {
    return items;
}

std::vector<std::string> Container::emptyInventory() {
    std::vector<std::string> temp = *new std::vector<std::string>();
    for (int i = 0; i < items.size(); i++) {
        temp.push_back(items[i]);
    }
    items.clear();
    return temp;
}

void Container::addItem(std::string item) {
    if (items.size() >= maxSize) {
        std::cout << "Can't do that! Not enough Space!" << std::endl;
    } else {
        items.push_back(item);
    }
}

void Container::removeItem(std::string name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == name) items.erase(items.begin() + i);
    }
}

void Container::changeMax(int i) {
    maxSize = i;
}

void Container::toggleAccess() {
    open = !open;
}

int Container::max() {
    return maxSize;
}

int Container::size() {
    return (int)items.size();
}

bool Container::hasItem(std::string item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}

bool Container::empty() {
    return items.empty();
}

bool Container::isOpen() {
    return open;
}

bool Container::isTakeable() {
    return takeable;
}

std::string Container::save() {
    std::string temp = type + "|";
    if (open) {
        temp += "true|";
    } else {
        temp += "false|";
    }
    std::string item;
    if (items.empty()) {
        item = "empty";
    } else {
        for (int i = 0; i < items.size(); i++) {
            if (i != 0) item += ",";
            item += items[i];
        }
    }
    temp += item;
    return temp;
}