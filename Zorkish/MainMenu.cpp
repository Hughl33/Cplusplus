//
//  MainMenu.cpp
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "MainMenu.h"
MainMenu::MainMenu() : about(), help(), hof(), play() {
    end = false;
    start = false;
}

void MainMenu::SelectMenu(int i) {
    switch (i) {
        case 1:
            play.Render();
            switch (play.SelectAdventure()) {
                case 1:
                    mode = "Void";
                    start = true;
                    break;
                case 2:
                    mode = "Adventure";
                    start = true;
                    break;
                default:
                    std::cout << "Please Select an Option from the List." << std::endl;
                    break;
            };
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

bool MainMenu::End() {
    return end;
}

bool MainMenu::Start() {
    return start;
}

std::string MainMenu::Mode() {
    return mode;
}

void MainMenu::Update() {
    std::cout << "Select 1-5:> ";
    std::getline (std::cin,move);
    SelectMenu(atoi(move.c_str()));
}

void MainMenu::Check() {
    
}

void MainMenu::Render() {
    std::cout << hr << std::endl;
    std::cout << "Welcome to Zorkish Adventures" << std::endl;
    std::cout << "  1. Select Adventure and Play" << std::endl;
    std::cout << "  2. Hall Of Fame" << std::endl;
    std::cout << "  3. Help" << std::endl;
    std::cout << "  4. About" << std::endl;
    std::cout << "  5. Quit" << std::endl;
}