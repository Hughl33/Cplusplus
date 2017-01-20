//
//  Direction.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 22/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Direction_h
#define Direction_h
#include <iostream>
#include <vector>

/*
 * Direction Class
 * The Direction Class is utilised by the Maze Class in the maze generation process. This will allow the
 * Maze class to create Directions that would concatenate the bit value of each direction. This Direction
 * class will also be able to keep track of it's oppostie direction to allow for backtracking and visit
 * checks.
 */
class Direction {
private:
    int bit;
    int dx;
    int dy;
    int opposite;
public:
    Direction(int b, int x, int y, int o);
    int getBit();
    int getDX();
    int getDY();
    int getOpposite();
};

#endif /* Direction_h */
