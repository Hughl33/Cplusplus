//
//  Enemy.cpp
//  Zorkish
//
//  Created by Hugh Lee on 11/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Enemy.h"
Enemy::Enemy() {
    
}

std::string Enemy::getName() {
    return name;
}

std::string Enemy::getDesc() {
    return desc;
}

int Enemy::getHP() {
    return hp;
}

int Enemy::getAtk() {
    return atk;
}

int Enemy::getDef() {
    return def;
}