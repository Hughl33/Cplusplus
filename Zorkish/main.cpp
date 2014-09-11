//
//  main.cpp
//  Zorkish
//
//  Created by Hugh Lee on 18/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "MainMenu.h"

int main(int argc, const char * argv[]) {
    MainMenu menu = *new MainMenu();
    while (!menu.End()) {
        menu.Render();
        menu.Update();
        if (menu.Start()) {
            std::vector<std::string> gameState = *new std::vector<std::string>();
            if (Data::existingSave(menu.Mode())) {
                gameState = Data::load(menu.Mode());
            } else {
                gameState = Data::createNew(menu.Mode());
            }
            
            Game game = *new Game(menu.Mode(), Data::getStructure(), gameState);
            std::cout << "Welcome to Zorkish: " << menu.Mode() << std::endl;
            while (menu.Start()) {
                game.render();
                game.userInput();
                game.update();
            }
        }
    }
    return 0;
}

