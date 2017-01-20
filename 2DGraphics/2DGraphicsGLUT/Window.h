//
//  Window.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 19/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>

class Window {
private:
    int width;
    int height;
    std::string title;
public:
    Window(int w, int h);
    static void reshape(int w, int h);
    void init();
    void clear();
    void update();
    int get_width();
    int get_height();
};

#endif /* Window_h */
