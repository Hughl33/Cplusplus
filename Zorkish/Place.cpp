//
//  Place.cpp
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Place.h"
Place::Place(std::string n, std::string t, std::string d, std::vector<std::string> i) {
    name = n;
    type = t;
    desc = d;
    items = i;
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

int Place::itemCount() {
    return (int)items.size();
}