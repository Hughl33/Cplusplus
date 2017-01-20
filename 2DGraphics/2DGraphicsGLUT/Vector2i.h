//
//  Vector2i.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 26/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Vector2i_h
#define Vector2i_h

#include <iostream>

class Vector2i {
private:
public:
    Vector2i(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

#endif /* Vector2i_h */
