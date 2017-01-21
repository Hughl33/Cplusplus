//
//  PathFinder.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 26/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef PathFinder_h
#define PathFinder_h

#include <iostream>
#include <vector>
#include "Vector2f.h"

class PathFinder {
private:
    std::vector<std::vector<int>> maze;
public:
    PathFinder(std::vector<std::vector<int>> maze);
    void generate(Vector2f a, Vector2f b);
};

#endif /* PathFinder_h */
