//
//  Enemy.cpp
//  Zorkish
//
//  Created by Hugh Lee on 11/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Enemy.h"
Enemy::Enemy(std::string n, int h, int a, int c, std::string d) {
    name = n;
    hp = h;
    atk = a;
    chance = c;
    desc = d;
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

int Enemy::getChance() {
    return chance;
}

void Enemy::takeDamage(int d) {
    hp -= d;
}