//
//  Maze.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 22/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Maze_h
#define Maze_h

#include <iostream>
#include <random>
#include <vector>
#include "Direction.h"
#include "Vector2i.h"

class Maze {
private:
    int x;
    int y;
    std::vector<std::vector<int>> maze;
    std::vector<int> currPath;
//    std::vector<Vector2f> frontier;
//    std::vector<Vector2f> searched;
    static bool between(int v, int upper) {return (v >= 0) && (v < upper);}
    static int myrandom (int i) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<float> dist(0, i);
        return dist(mt);
    }
    void generate(int cx, int cy);
    Direction NORTH;
    Direction SOUTH;
    Direction EAST;
    Direction WEST;
public:
    Maze(int x, int y);
    std::vector<Direction> values(std::vector<Direction> result);
    void solve(Vector2i current, Vector2i end, std::vector<int> p = *new std::vector<int>);
    std::vector<std::vector<int>> output();
    std::vector<int> path();
};

#endif /* Maze_h */
