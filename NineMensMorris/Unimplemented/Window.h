//
//  Window.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Window__
#define __NineMensMorris__Window__

#include <iostream>
#include <curses.h>
#include "Input.h"

class Window {
private:
    SDL_Window *window;
    const char *title;
    int width;
    int height;
    bool mouse_grabbed = true;
    
public:
    Window(const char *t, int w, int h);
    ~Window();
    void clear();
    void update();
    int get_width();
    int get_height();
};

#endif /* defined(__NineMensMorris__Window__) */
