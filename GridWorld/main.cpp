//
//  main.cpp
//  GridWorld
//
//  Created by Hugh Lee on 5/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include <iostream>
#include "Game.h"

int main(int argc, const char * argv[]) {
    Game game = *new Game();
    cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: n, s, e and w for direction. q to quit the game. (No CAPS)" << endl;
    while (!game.End()) {
        game.RenderMap();
        game.CheckMoves();
        game.Turn();
        if (game.CheckInput()) {
            game.Update ();
            game.CheckStatus();
        }
    }
    
    cout << "Thanks for playing. Maybe next time." << endl;
    
    return 0;
}

