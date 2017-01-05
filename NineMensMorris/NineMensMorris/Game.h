//
//  Game.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Game__
#define __NineMensMorris__Game__

#include <iostream>
#include <curses.h>
#include <vector>
#include "Board.h"
#include "Colour.h"
#include "Interface.h"
#include "Setup.h"
#include "Mill.h"
#include "Player.h"
#include "PlayState.h"
#include "Move.h"

class Game {
private:
    Board board;
    Interface gui;
    Mill mill;
    int current;
    int selected;
    int turn;
    bool end;
public:
    Game(int w, int h);
    bool isRunning();
    void update();
    void render();
    void close();
    
};

#endif /* defined(__NineMensMorris__Game__) */
