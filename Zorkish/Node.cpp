//
//  Node.cpp
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Node.h"
Node::Node(std::string n, std::vector<std::string> l) {
    name = n;
    links = l;
}

std::string Node::getName() {
    return name;
}

std::vector<std::string> Node::getLinks() {
    return links;
}