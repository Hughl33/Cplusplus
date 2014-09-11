//
//  Player.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Player.h"

Player::Player(std::string n, int h, int l, int e, int s, std::string p, std::vector<std::string> i) {
    name = n;
    health = h;
    level = l;
    experience = e;
    score = s;
    place = p;
    inventory = i;
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

bool Player::hasItem(std::string item) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) return true;
    }
    return false;
}

std::vector<std::string> Player::getInventory() {
    return inventory;
}

void Player::addItem(std::string item) {
    inventory.push_back(item);
}

void Player::dropItem(std::string item) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory.erase(inventory.begin() + i);
        }
    }
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
    for (int i = 0; i < inventory.size(); i++) {
        if (i != 0) item += ",";
        item += inventory[i];
    }
    temp.push_back(item);
    return temp;
}
