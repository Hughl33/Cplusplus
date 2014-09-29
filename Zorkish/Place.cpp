//
//  Place.cpp
//  Zorkish
//
//  Created by Hugh Lee on 26/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Place.h"
Place::Place() {
    
}

Place::Place(std::string n, std::string t, std::string d) {
    name = n;
    type = t;
    desc = d;
}

std::string Place::getName() {
    return name;
}

std::string Place::getType() {
    return type;
}

std::string Place::getDesc() {
    return desc;
}

std::string Place::getItem(int i) {
    return items[i];
}

std::string Place::getContainer(int i) {
    return containers[i];
}

std::string Place::getEnemy(int i) {
    return enemies[i];
}

void Place::addItem(std::string item) {
    items.push_back(item);
}

void Place::addContainer(std::string container) {
    containers.push_back(container);
}

void Place::addEnemy(std::string enemy) {
    enemies.push_back(enemy);
}

void Place::removeItem(std::string item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            items.erase(items.begin() + i);
        }
    }
}

void Place::removeContainer(std::string container) {
    for (int i = 0; i < containers.size(); i++) {
        if (containers[i] == container) {
            containers.erase(containers.begin() + i);
        }
    }
}

void Place::removeEnemy(std::string enemy) {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i] == enemy) {
            enemies.erase(enemies.begin() + i);
        }
    }
}

bool Place::hasItem(std::string item) {
    for (int i = 0; i < items.size(); i++) {
//        std::cout << items[i] << ", " << item << std::endl;
        if (items[i] == item) return true;
    }
    return false;
}

bool Place::hasContainer(std::string container) {
    for (int i = 0; i < containers.size(); i++) {
        if (containers[i] == container) return true;
    }
    return false;
}

bool Place::hasEnemy(std::string enemy) {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i] == enemy) return true;
    }
    return false;
}

int Place::itemCount() {
    return (int)items.size();
}

int Place::containerCount() {
    return (int)containers.size();
}

int Place::enemyCount() {
    return (int)enemies.size();
}

std::string Place::saveItems() {
    std::string item = *new std::string();
    if (items.empty()) {
        item = "empty";
    } else {
        for (int i = 0; i < items.size(); i++) {
            if (i != 0) item += ",";
            item += items[i];
        }
    }
    return item;
}

std::string Place::saveContainers() {
    std::string container = *new std::string();
    if (containers.empty()) {
        container = "empty";
    } else {
        for (int i = 0; i < containers.size(); i++) {
            if (i != 0) container += ",";
            container += containers[i];
        }
    }
    return container;
}

std::string Place::saveEnemies() {
    std::string enemy = *new std::string();
    if (enemies.empty()) {
        enemy = "empty";
    } else {
        for (int i = 0; i < enemies.size(); i++) {
            if (i != 0) enemy += ",";
            enemy += enemies[i];
        }
    }
    return enemy;
}