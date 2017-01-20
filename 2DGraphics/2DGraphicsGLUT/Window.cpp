//
//  Window.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 19/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include "Window.h"

Window::Window(int w, int h) {
    width = w;
    height = h;
}

void Window::reshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    gluPerspective(45, (float)w/h, 0.01, 1000);
}

void Window::init() {
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("LineMakerGLUT");
}

void Window::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void Window::update() {
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        std::cerr << error << std::endl;
    }
    glutSwapBuffers();
}
