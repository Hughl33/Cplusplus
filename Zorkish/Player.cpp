//
//  Player.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Player.h"

Player::Player(std::string n, std::string m, int h, int l, int e, int s, std::string p) {
    name = n;
    mode = m;
    health = h;
    level = l;
    experience = e;
    score = s;
    place = p;
}


std::string Player::getName() {
    return name;
}

int Player::getLevel() {
    return level;
}

int Player::getExperience() {
    return experience;
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

std::vector<std::string> Player::save() {
    std::string item = *new std::string();
    std::vector<std::string> temp = *new std::vector<std::string>();
    temp.push_back(name);
    temp.push_back(std::to_string(health));
    temp.push_back(std::to_string(level));
    temp.push_back(std::to_string(experience));
    temp.push_back(std::to_string(score));
    temp.push_back(place);
    return temp;
}
