//
//  Structure.cpp
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Structure.h"

Structure::Structure(): nodes() {
}

void Structure::addNode(Node n) {
    nodes.push_back(n);
}

std::vector<std::string> Structure::getLinks(std::string node) {
    std::vector<std::string> temp = *new std::vector<std::string>();
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].getName() == node) {
            return nodes[i].getLinks();
        }
    }
    return temp;
}
