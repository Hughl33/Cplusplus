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
    std::string mode;
    std::string place;
    int health;
    int damage;
    int chance;
    int score;
    bool won;
public:
    Player(std::string n, std::string m, int h, int d, int c, int s, std::string p);
    std::string getName();
    int getHealth();
    int getDamage();
    int getChance();
    int getScore();
    std::string getPlace();
    void move(std::string p);
    void takeDamage(int d);
    void addItem(std::string item);
    void dropItem(std::string item);
    bool getWin();
    void setWin();
    std::vector<std::string> save();
};
#endif /* defined(__Zorkish__Player__) */
