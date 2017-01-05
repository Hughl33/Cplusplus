//
//  main.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include <iostream>
#include "Game.h"
#include "Setup.h"

int main(int argc, const char * argv[]) {
    Game game = *new Game(160, 50);
    while (game.isRunning()) {
        game.update();
        game.render();
    }
    game.close();
    return 0;
}

