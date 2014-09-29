//
//  Enemy.h
//  Zorkish
//
//  Created by Hugh Lee on 11/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Enemy__
#define __Zorkish__Enemy__

#include <iostream>
#include <string>
#include <vector>

class Enemy {
private:
    std::string name;
    std::string desc;
    int hp;
    int atk;
    int chance;
public:
    Enemy(std::string n, int h, int a, int c, std::string d);
    std::string getName();
    std::string getDesc();
    int getHP();
    int getAtk();
    int getChance();
    void takeDamage(int d);
};
#endif /* defined(__Zorkish__Enemy__) */
