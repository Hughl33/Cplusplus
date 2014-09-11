//
//  Game.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Game.h"

Game::Game(std::string m, Structure s, std::vector<std::string> p) : player(p[0], atoi(p[1].c_str()), atoi(p[2].c_str()), atoi(p[3].c_str()), atoi(p[4].c_str()), p[5], Data::split(p[6], ',')), struc(s) {
    mode = m;
    place = " ";
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
    Input::process(move, player, struc);
}

void Game::update() {
    Data::save(player.save(), mode);
}