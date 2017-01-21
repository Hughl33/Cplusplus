//
//  Maze.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 22/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include "Maze.h"

Maze::Maze(int x, int y) : NORTH(1, 0, -1, 2), SOUTH(2, 0, 1, 1), EAST(4, 1, 0, 8), WEST(8, -1, 0, 4) {
    this->x = x;
    this->y = y;
    maze = *new std::vector<std::vector<int>>;
    currPath = *new std::vector<int>;
    for (int i = 0; i < y; i++) {
        maze.push_back(*new std::vector<int>);
        for (int j = 0; j < x; j++) maze[i].push_back(0);
    }
    generate(0, 0);
    //Output Maze to Console
//    for (int i = 0; i < y; i++) {
//        // draw the north edge
//        for (int j = 0; j < x; j++) {
//            if ((maze[j][i] & 1) == 0) std::cout << "+---";
//            else std::cout << "+   ";
//        }
//        std::cout << "+" << std::endl;
//        // draw the west edge
//        for (int j = 0; j < x; j++) {
//            if ((maze[j][i] & 8) == 0) std::cout << "|   ";
//            else std::cout << "    ";
//        }
//        std::cout << "|" << std::endl;
//    }
//    // draw the bottom line
//    for (int j = 0; j < x; j++) {
//        std::cout << "+---";
//    }
//    std::cout << "+" << std::endl;
    //Output Maze Bits to Console
//    for (int i = 0; i < y; i++) {
//        for (int j = 0; j < x; j++) {
//            std::cout << maze[j][i] << " ";
//        }
//        std::cout << std::endl;
//    }
    //Output Solution Bits to Console
//    solve(Vector2f(0,0), Vector2f(14,14));
//    for (int i = 0; i < currPath.size(); i++) std::cout << currPath[i] << std::endl;
}

std::vector<Direction> Maze::values(std::vector<Direction> result){
    result.push_back(NORTH);
    result.push_back(SOUTH);
    result.push_back(EAST);
    result.push_back(WEST);
    return result;
}

void Maze::generate(int cx, int cy) {
    std::vector<Direction> dirs;
    dirs = values(dirs);
    std::random_shuffle(dirs.begin(), dirs.end(), myrandom);
    for (int i = 0; i < 4; i++) {
        int nx = cx + dirs[i].getDX();
        int ny = cy + dirs[i].getDY();
        if (between(nx, x) && between(ny, y) && (maze[nx][ny] == 0)) {
            maze[cx][cy] |= dirs[i].getBit();
            maze[nx][ny] |= dirs[i].getOpposite();
            generate(nx, ny);
        }
    }
}

void Maze::solve(Vector2i current, Vector2i end, std::vector<int> p) {
    std::vector<int> path = p;
    if (path.empty()) path.push_back(0);
    std::vector<Direction> dirs;
    dirs = values(dirs);
    if ((current.x == end.x) && (current.y == end.y)) {
        path.erase(path.begin());
        currPath = path;
    } else {
        Vector2i next;
        for (int i = 0; i < 4; i++) {
            if (dirs[i].getOpposite() != path.back()) {
                if ((maze[current.x][current.y] & dirs[i].getBit()) == dirs[i].getBit()) {
                    next.x = current.x + dirs[i].getDX();
                    next.y = current.y + dirs[i].getDY();
                    path.push_back(dirs[i].getBit());
                    solve(next, end, path);
                    path.pop_back();
                }
            }
        }
    }
}

std::vector<std::vector<int>> Maze::output() {
    return maze;
}

std::vector<int> Maze::path() {
    return currPath;
}









































