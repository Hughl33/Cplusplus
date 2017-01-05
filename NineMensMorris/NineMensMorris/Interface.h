//
//  Interface.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Interface__
#define __NineMensMorris__Interface__

#include <iostream>
#include <vector>
#include <curses.h>
#include "Vertex.h"
#include "Player.h"
#include "Layout.h"
#include "Colour.h"

class Interface {
private:
    WINDOW *menu_win;
    int x = 0;
    int y = 0;
    int maxX;
    int maxY;
    Layout layout;
    std::string static event;
    void renderEvent();
    void renderPiece(std::vector<Vertex> v);
    void renderInfo(std::vector<Player> p);
    void renderInstructions();
    void renderSelector(std::vector<Vertex> v, int current, int selected);
    void renderLayout();
public:
    Interface(Layout l, int w, int h);
    void static broadcast(std::string e);
    WINDOW *getWindow();
    int getX();
    int getY();
    int getMaxX();
    int getMaxY();
    void render(std::vector<Vertex> v, int current, std::vector<Player> p, int selected);
    void close();
};

#endif /* defined(__NineMensMorris__Interface__) */
