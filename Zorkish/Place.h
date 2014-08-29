//
//  Place.h
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Place__
#define __Zorkish__Place__

#include <iostream>
#include <vector>

class Place {
private:
    std::string name;
    std::string type;
    std::string desc;
    std::vector<std::string> items;
public:
    Place(std::string n, std::string t, std::string d, std::vector<std::string> i);
    std::string getName();
    std::string getType();
    std::string getDesc();
    std::string getItem(int i);
    int itemCount();
    
};
#endif /* defined(__Zorkish__Place__) */
