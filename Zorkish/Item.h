//
//  Item.h
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Item__
#define __Zorkish__Item__

#include <iostream>
class Item {
private:
    std::string name;
    std::string type;
    std::string desc;
public:
    Item(std::string n, std::string t, std::string d);
    std::string getName();
    std::string getType();
    std::string getDesc();
};
#endif /* defined(__Zorkish__Item__) */
