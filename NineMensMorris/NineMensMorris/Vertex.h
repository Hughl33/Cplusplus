//
//  Vertex.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#ifndef __NineMensMorris__Vertex__
#define __NineMensMorris__Vertex__

#include <iostream>
#include <vector>
#include <curses.h>
#include "Colour.h"
#include "Point2d.h"
#include "Piece.h"
#include "Link.h"

class Vertex {
private:
    std::vector<Link> neighbours;
    int ID;
    Point2d coords;
    bool occupied;
    Piece piece;
public:
    Vertex(int i, Point2d c, std::vector<Link> n);
    int getID();
    Piece* getPiece();
    Point2d getCoords();
    std::vector<Link> getNeighbours();
    int getNeighbour(int i);
    int neighbourSize();
    bool ifOccupied();
    void place(Piece a);
    void remove();
};

#endif /* defined(__NineMensMorris__Vertex__) */
