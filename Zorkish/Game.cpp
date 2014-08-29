//
//  Game.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Game.h"

Game::Game() {
    player = *new Player();
}

void Game::Render() {
    
}

void Game::UserInput() {
    std::cout << ":>";
    std::cin >> move;
}

void Game::Update() {
    
}

bool Game::CheckInput() {
    return true;
}