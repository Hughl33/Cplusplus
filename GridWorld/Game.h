//
//  Game.h
//  GridWorld
//
//  Created by Hugh Lee on 5/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef GridWorld_Game_h
#define GridWorld_Game_h
#include "Player.h"
#include <iostream>
using namespace std;

class Game {
private:
    string map[8][8];
    Player player;
    bool end;
    string moves[4];
    string move;
    
public:
    Game ();
    bool End ();
    void RenderMap ();
    void Turn ();
    void Update ();
    bool CheckInput ();
    void CheckMoves ();
    void CheckStatus ();
};

#endif
