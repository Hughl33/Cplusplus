//
//  GameManager.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__GameManager__
#define __NineMensMorris__GameManager__

#include <iostream>
#include <cmath>
#include <curses.h>
#include "Game.h"

class GameManager {
private:
    Game game;
    bool running;
    
public:
    GameManager(const char *t, int w, int h);
    bool isRunning();
    void update();
    void render();
    void testRender();
};

#endif /* defined(__NineMensMorris__GameManager__) */
