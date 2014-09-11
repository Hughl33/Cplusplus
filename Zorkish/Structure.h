//
//  Structure.h
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Structure__
#define __Zorkish__Structure__

#include <iostream>
#include <vector>
#include <string>
#include "Node.h"

class Structure {
private:
    std::vector<Node> nodes;
public:
    Structure();
    void addNode(Node n);
    std::vector<std::string> getLinks(std::string node);
    void process();
};
#endif /* defined(__Zorkish__Structure__) */
