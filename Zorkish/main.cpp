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

int main(int argc, const char * argv[])
{
    MainMenu menu = *new MainMenu();
    while (!menu.End()) {
        menu.Render();
        menu.Update();
        if (menu.Start()) {
            Game game = *new Game();
            while (menu.Start()) {
                game.UserInput();
                game.Render();
                break;
                //if (game.CheckInput())
                //  game.Update();
            }
        }
    }
    return 0;
}

