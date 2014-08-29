//
//  Game.h
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Game__
#define __Zorkish__Game__

#include <iostream>
#include "Player.h"
#include "Data.h"

class Game {
private:
    Player player;
    std::string move;
public:
    Game();
    void Render();
    void UserInput();
    void Update();
    bool CheckInput();
};

#endif /* defined(__Zorkish__Game__) */
