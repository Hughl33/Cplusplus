//
//  Vector2f.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 12/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Vector2f_h
#define Vector2f_h

#include <iostream>

class Vector2f {
private:
public:
    Vector2f(float x = 0.0, float y = 0.0) {
        this->x = x;
        this->y = y;
    }
    float x;
    float y;
};

#endif /* Vector2f_h */
