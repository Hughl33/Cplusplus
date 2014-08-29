//
//  Data.h
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Data__
#define __Zorkish__Data__

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Place.h"

class Data {
public:
    std::vector<std::string> static &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> static split(const std::string &s, char delim);
    
    std::string static getMenu(std::string name);
    Item static getItem(std::string name);
    Place static getPlace(std::string name);
    //Enemy static getEnemy();
    //Structure static getStructure();
};
#endif /* defined(__Zorkish__Data__) */
