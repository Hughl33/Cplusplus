//
//  main.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 4/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include "Window.h"
#include "Drawer.h"

int size = 600;
Window window = *new Window (size, size);
Drawer drawer = *new Drawer (size);

void display () {
    drawer.Update();
    window.clear();
    drawer.TestDraw();
    drawer.Draw();
    window.update();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    window.init();
    glutReshapeFunc(window.reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    drawer.init();
    glutMainLoop();
    return 0;
}
