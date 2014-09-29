//
//  Game.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Game.h"

Game::Game(std::string m, Structure s, std::vector<std::string> p) : player(p[0], p[1], atoi(p[2].c_str()), atoi(p[3].c_str()), atoi(p[4].c_str()), atoi(p[5].c_str()), p[6]), struc(s) {
    mode = m;
    place = " ";
    finish = false;
}

void Game::render() {
    if (Data::equals(player.getPlace(), place)) {
        std::cout << "What would you like to do now?" << std::endl;
    } else {
        std::cout << Data::toProper(player.getPlace()) << std::endl;
        std::cout << Data::getPlace(player.getPlace()).getDesc() << std::endl;
        place = player.getPlace();
    }
}

void Game::userInput() {
    std::cout << ":> ";
    std::getline (std::cin,move);
    finish = Input::process(move, player, struc);
}

void Game::update() {
    Data::save(player.save(), mode);
}

bool Game::endGame() {
    return finish;
}

bool Game::outcome() {
    if (player.getHealth() == 0) {
        std::cout << "You Lost!" << std::endl;
        std::cout << "Score: " << player.getScore() << std::endl;
    } else if (player.getWin()) {
        std::cout << "You Won!" << std::endl;
        std::cout << "Score: " << player.getScore() << std::endl;
    }
    std::cout << "Would you like to view the Hall of Fame?" << std::endl;
    std::cout << "Enter y - yes, any other key - no" << std::endl;
    std::string temp = " ";
    std::cout << ":> ";
    std::getline (std::cin,temp);
    if (temp == "y") {
        return true;
    } else {
        return false;
    }
}