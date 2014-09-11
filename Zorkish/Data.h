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
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include "Item.h"
#include "Place.h"
#include "Structure.h"
#include "Node.h"

class Data {
public:
    std::vector<std::string> static &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> static split(const std::string &s, char delim);
    std::string static inBetween(std::string, char a, char b);
    std::string static toLower(std::string s);
    std::string static toUpper(std::string s);
    std::string static toProper(std::string s);
    bool static equals(std::string a, std::string b);
    bool static canMove(std::string s, std::vector<std::string> m);
    //std::vector<std::string> static getFiles(std::string entity, std::string name, std::string type);
    
    std::string static getMenu(std::string name);
    Item static getItem(std::string name);
    std::vector<std::string> static getPlaceItems(std::string name);
    Place static getPlace(std::string name);
    Structure static getStructure();
    //Enemy static getEnemy();
    
    void static copyFile(std::string file, std::string name);
    void static copyFile(std::string file);
    void static save(std::string line, std::string name);
    void static save(std::vector<std::string> file, std::string name);
    std::vector<std::string> static load(std::string name);
    std::vector<std::string> static createNew(std::string name);
    bool static existingSave(std::string name); //redundant if multiple saves are implemented
};
#endif /* defined(__Zorkish__Data__) */
