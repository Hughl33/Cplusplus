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
#include <string>
#include "Player.h"
#include "Input.h"
#include "Structure.h"
#include "Place.h"

class Game {
private:
    Player player;
    Structure struc;
    std::string place;
    std::string mode;
    std::string move;
    bool finish;
public:
    Game(std::string m, Structure s, std::vector<std::string> p);
    void render();
    void userInput();
    void update();
    bool outcome();
    bool endGame();
};

#endif /* defined(__Zorkish__Game__) */
