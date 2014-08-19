//
//  Game.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Game.h"
Game::Game() : about(), help(), hof(), player() {
    end = false;
}

void Game::SelectMenu(int i) {
    switch (i) {
        case 1:
            break;
        case 2:
            hof.Render();
            break;
        case 3:
            help.Render();
            break;
        case 4:
            about.Render();
            break;
        case 5:
            end = true;
            std::cout << "Good-Bye!" << std::endl;
            break;
        default:
            std::cout << "Please Select an Option from the List." << std::endl;
            break;
    }
}

bool Game::End() {
    return end;
}

void Game::Update() {
    std::cout << "Select 1-5:> ";
    std::cin >> move;
    SelectMenu(atoi(move.c_str()));
}

void Game::Check() {
    
}

void Game::Render() {
    std::cout << hr << std::endl;
    std::cout << "Welcome to Zorkish Adventures" << std::endl;
    std::cout << "    1. Select Adventure and Play" << std::endl;
    std::cout << "    2. Hall Of Fame" << std::endl;
    std::cout << "    3. Help" << std::endl;
    std::cout << "    4. About" << std::endl;
    std::cout << "    5. Quit" << std::endl;
}