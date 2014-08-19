//
//  main.cpp
//  Zorkish
//
//  Created by Hugh Lee on 18/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include <iostream>
#include "Game.h"

int main(int argc, const char * argv[])
{
    Game game = *new Game();
    while (!game.End()) {
        game.Render();
        game.Update();
    }
    return 0;
}

