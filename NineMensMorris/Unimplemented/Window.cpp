//
//  Window.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Window.h"
Window::Window(const char *t, int w, int h) {
    title = t;
    width = w;
    height = h;
    
    window = SDL_CreateWindow(t, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        throw new std::runtime_error("Could not create SDL window!");
    }
    SDL_GL_CreateContext(window);
    SDL_ShowCursor(SDL_ENABLE);
    
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, width, height);
    gluPerspective(45, (float)width / height, 0.01, 1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

Window::~Window() {
    SDL_DestroyWindow(window);
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
    SDL_GL_SwapWindow(window);
}

int Window::get_width() {
    return width;
}

int Window::get_height() {
    return height;
}