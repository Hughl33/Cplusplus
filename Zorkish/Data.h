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
#include "Container.h"
#include "Inventory.h"
#include "Enemy.h"

class Data {
public:
    std::vector<std::string> static &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> static split(const std::string &s, char delim);
    std::string static inBetween(std::string, char a, char b);
    std::string static toLower(std::string s);
    std::string static toUpper(std::string s);
    std::string static toProper(std::string s);
    bool static boolean(std::string b);
    bool static equals(std::string a, std::string b);
    bool static canMove(std::string s, std::vector<std::string> m);
    //std::vector<std::string> static getFiles(std::string entity, std::string name, std::string type);
    
    std::string static getMenu(std::string name);
    std::vector<std::string> static getHOF();
    Item static getItem(std::string name);
    std::vector<std::string> static getPlaceItems(std::string name);
    Place static getPlace(std::string name);
    std::vector<std::string> static getPlaceContainers(std::string name);
    std::vector<std::string> static getPlaceEnemies(std::string name);
    std::vector<std::string> static getContainerItems(std::string name);
    std::vector<std::string> static getContainers(std::string name);
    Container static getContainer(std::string place, std::string type);
    Container static getContainer(std::string ID);
    Enemy static getEnemy(std::string name);
    std::vector<std::string> static getEnemyItems(std::string name);
    Container static createCorpse(std::string name);
    Structure static getStructure();
    Inventory static getInventory(std::string name);
    //Enemy static getEnemy();
    
    void static copyFile(std::string file, std::string name);
    void static copyFile(std::string file);
    void static save(std::string line, std::string name, std::string file);
    void static save(std::vector<std::string> file, std::string name);
    void static save(std::string line, std::string file);
    void static clearSave(std::string save);
    std::vector<std::string> static load(std::string name);
    std::vector<std::string> static createNew(std::string name);
    bool static existingSave(std::string name); //redundant if multiple saves are implemented
};
#endif /* defined(__Zorkish__Data__) */
