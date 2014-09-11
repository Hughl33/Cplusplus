//
//  PlayMenu.cpp
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "PlayMenu.h"
PlayMenu::PlayMenu() {
    title = "Play";
}

void PlayMenu::Render() {
    std::cout << hr << std::endl;
    std::cout << "Zorkish :: " << title << std::endl;
    std::cout << hr << std::endl;
    std::cout << "Choose you Adventure:" << std::endl;
    std::cout << "  1. Void World" << std::endl;
    std::cout << "  2. Adventure World" << std::endl;
}

int PlayMenu::SelectAdventure() {
    std::cout << "Select 1 or 2:> ";
    std::string move;
    std::getline (std::cin,move);
    return atoi(move.c_str());
}