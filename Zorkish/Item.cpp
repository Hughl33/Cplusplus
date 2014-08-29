//
//  Item.cpp
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Item.h"
Item::Item(std::string n, std::string t, std::string d) {
    name = n;
    type = t;
    desc = d;
}

std::string Item::getName() {
    return name;
}

std::string Item::getType() {
    return type;
}

std::string Item::getDesc() {
    return desc;
}