//
//  Player.h
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Player__
#define __Zorkish__Player__

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

class Player {
private:
    std::string name;
    int health;
    int level;
    int experience;
    int score;
    std::string place;
    std::vector<std::string> inventory;
public:
    Player(std::string n, int h, int l, int e, int s, std::string p, std::vector<std::string> i);
    std::string getName();
    int getLevel();
    int getExperience();
    int getScore();
    std::string getPlace();
    void move(std::string p);
    bool hasItem(std::string item);
    std::vector<std::string> getInventory();
    void addItem(std::string item);
    void dropItem(std::string item);
    std::vector<std::string> save();
};
#endif /* defined(__Zorkish__Player__) */
