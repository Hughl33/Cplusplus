//
//  Player.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Player.h"

Player::Player(std::string n, std::string m, int h, int d, int c, int s, std::string p) {
    name = n;
    mode = m;
    health = h;
    damage = d;
    chance = c;
    score = s;
    place = p;
    won = false;
}


std::string Player::getName() {
    return name;
}

int Player::getHealth() {
    return health;
}

int Player::getDamage() {
    return damage;
}

int Player::getChance() {
    return chance;
}

int Player::getScore() {
    return score;
}

std::string Player::getPlace() {
    return place;
}

void Player::move(std::string p) {
    place = p;
}

void Player::takeDamage(int d) {
    health -= d;
}

bool Player::getWin() {
    return won;
}

void Player::setWin() {
    won = true;
}

std::vector<std::string> Player::save() {
    std::string item = *new std::string();
    std::vector<std::string> temp = *new std::vector<std::string>();
    temp.push_back(name);
    temp.push_back(mode);
    temp.push_back(std::to_string(health));
    temp.push_back(std::to_string(damage));
    temp.push_back(std::to_string(chance));
    temp.push_back(std::to_string(score));
    temp.push_back(place);
    return temp;
}
