//
//  Player.h
//  GridWorld
//
//  Created by Hugh Lee on 5/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef GridWorld_Player_h
#define GridWorld_Player_h
#include <iostream>

class Player {
private:
    int posX;
    int posY;
    
public:
    Player (int posX, int posY);
    int PositionX ();
    int PositionY ();
    
    void up();
    void down();
    void left();
    void right();
};

#endif
