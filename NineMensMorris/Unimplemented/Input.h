//
//  Input.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Input__
#define __NineMensMorris__Input__

#include <iostream>
#include <vector>
#include <cmath>
#include <curses.h>

class Input {
private:
    //Keys
    SDL_Event event;
    static bool keys[65536];
    static std::vector<SDL_Scancode> pressed_keys;
    static std::vector<unsigned int> clicked_buttons;
    
    //Screen properties
    static int width, height;
    
    //States
    bool quit = false;
    
    //Mouse Properties
    static int mx, my, mb;
public:
    Input(int w, int h);
    void update();
    std::vector<SDL_Keycode> get_pressed_keys();
    static bool key_pressed(SDL_Scancode key);
    static bool key_typed(SDL_Scancode key);
    static bool mouse_clicked(unsigned int button);
    static int get_DX();
    static int get_DY();
    static int get_mouse_button();
    static bool mouse_in_circle(float x, float y, float r);
    static bool mouse_in_rect(float x, float y, float l, float w);
    bool window_closed();
};

#endif /* defined(__NineMensMorris__Input__) */
