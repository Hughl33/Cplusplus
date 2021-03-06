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
    std::vector<std::string> containers;
    std::vector<std::string> enemies;
public:
    Place();
    Place(std::string n, std::string t, std::string d);
    std::string getName();
    std::string getType();
    std::string getDesc();
    std::string getContainer(int i);
    std::string getItem(int i);
    std::string getEnemy(int i);
    void addItem(std::string item);
    void addContainer(std::string container);
    void addEnemy(std::string enemy);
    void removeItem(std::string item);
    void removeContainer(std::string container);
    void removeEnemy(std::string enemy);
    bool hasItem(std::string item);
    bool hasContainer(std::string container);
    bool hasEnemy(std::string enemy);
    int itemCount();
    int containerCount();
    int enemyCount();
    std::string saveItems();
    std::string saveContainers();
    std::string saveEnemies();
};
#endif /* defined(__Zorkish__Place__) */
