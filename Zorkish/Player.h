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
#include "Item.h"

class Player {
private:
    int health;
    int level;
    int experience;
    int score;
    std::vector<Item> inventory;
public:
    std::string getName();
    int getLevel();
    int getExperience();
    int getScore();
    
};
#endif /* defined(__Zorkish__Player__) */
