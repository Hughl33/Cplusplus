//
//  PlayMenu.cpp
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "PlayMenu.h"
PlayMenu::PlayMenu() {
    
}

void PlayMenu::Render() {
    std::cout << hr << std::endl;
    std::cout << "Zorkish :: " << title << std::endl;
    std::cout << hr << std::endl;
    std::cout << "Choose you Adventure:" << std::endl;
    std::cout << "  1. Mountain World" << std::endl;
    std::cout << "  2. Water World" << std::endl;
    std::cout << "  3. Box World" << std::endl;
}

int PlayMenu::SelectAdventure() {
    std::cout << "Select 1-5:> ";
    std::string move;
    std::cin >> move;
    return atoi(move.c_str());
}