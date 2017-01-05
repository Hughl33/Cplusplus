//
//  GameManager.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "GameManager.h"

GameManager::GameManager(const char *t, int w, int h) : game() {
    running = true;
}

bool GameManager::isRunning() {
    return !(game.isEnd());
}

void GameManager::update() {
    game.update();
}

void GameManager::render() {
    game.render();
}