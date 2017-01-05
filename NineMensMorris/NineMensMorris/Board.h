//
//  Board.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Board__
#define __NineMensMorris__Board__

#include <iostream>
#include <vector>
#include <curses.h>
#include "Vertex.h"
#include "Player.h"
#include "Move.h"

class Board {
private:
    std::vector<Player> players;
    std::vector<Vertex> vertices;
public:
    Board(std::vector<Vertex> i);
    Vertex* getVertex(int i);
    int numberOfVertices();
    std::vector<Vertex> getVertices();
    Player* getPlayer(int i);
    std::vector<Player> getPlayers();
    bool move(int turn, int current, int selected);
    void move(int a, int b);
    bool update(int& turn);
};

#endif /* defined(__NineMensMorris__Board__) */
