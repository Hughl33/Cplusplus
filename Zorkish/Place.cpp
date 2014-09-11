//
//  Place.cpp
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Place.h"
Place::Place() {
    
}

Place::Place(std::string n, std::string t, std::string d) {
    name = n;
    type = t;
    desc = d;
}

std::string Place::getName() {
    return name;
}

std::string Place::getType() {
    return type;
}

std::string Place::getDesc() {
    return desc;
}

std::string Place::getItem(int i) {
    return items[i];
}

void Place::addItem(std::string item) {
    items.push_back(item);
}

void Place::removeItem(std::string item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            items.erase(items.begin() + i);
        }
    }
}

bool Place::hasItem(std::string item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) return true;
    }
    return false;
}

int Place::itemCount() {
    return (int)items.size();
}

std::string Place::save() {
    std::string item = *new std::string();
    if (items.empty()) {
        item = "empty";
    } else {
        for (int i = 0; i < items.size(); i++) {
            if (i != 0) item += ",";
            item += items[i];
        }
    }
    return item;
}