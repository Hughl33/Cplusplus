//
//  Node.h
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Node__
#define __Zorkish__Node__

#include <iostream>
#include <vector>

class Node {
private:
    std::string name;
    std::vector<std::string> links;//direction:place
public:
    Node(std::string n, std::vector<std::string> l);
    std::string getName();
    std::vector<std::string> getLinks();
    void process();
};
#endif /* defined(__Zorkish__Node__) */
