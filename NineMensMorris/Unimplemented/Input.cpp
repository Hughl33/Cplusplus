//
//  Input.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#include "Input.h"
Input::Input(int w, int h) {
    width = w;
    height = h;
    for (unsigned int i = 0; i < 65536; i++) {
        keys[i] = false;
    }
}

//Keys
bool Input::keys[65536];
std::vector<SDL_Scancode> Input::pressed_keys;
std::vector<unsigned int> Input::clicked_buttons;

//Mouse Properties
int Input::width;
int Input::height;
int Input::mx;
int Input::my;
int Input::mb;

void Input::update() {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                keys[event.key.keysym.scancode] = true;
                break;
            case SDL_KEYUP:
                keys[event.key.keysym.scancode] = false;
                if (!pressed_keys.empty() && std::find(pressed_keys.begin(), pressed_keys.end(), event.key.keysym.scancode) != pressed_keys.end()) {
                    pressed_keys.erase(std::find(pressed_keys.begin(), pressed_keys.end(), event.key.keysym.scancode));
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mb = event.button.button;
                break;
            case SDL_MOUSEBUTTONUP:
                mb = 0;
                if (!clicked_buttons.empty() && std::find(clicked_buttons.begin(), clicked_buttons.end(), event.button.button) != clicked_buttons.end()) {
                    clicked_buttons.erase(std::find(clicked_buttons.begin(), clicked_buttons.end(), event.button.button));
                }
                break;
        }
    }
    if (key_typed(SDL_SCANCODE_ESCAPE)) {
        quit = true;
    }
    SDL_GetMouseState(&mx, &my);
}

std::vector<SDL_Keycode> Input::get_pressed_keys() {
    std::vector<int> result;
    for (unsigned int i = 0; i < 65536; i++) {
        if (keys[i]) result.push_back(i);
    }
    return result;
}

bool Input::key_pressed(SDL_Scancode key) {
    return keys[key];
}

bool Input::key_typed(SDL_Scancode key) {
    bool pressed = key_pressed(key);
    if (!pressed) return false;
    if(!pressed_keys.empty() && std::find(pressed_keys.begin(), pressed_keys.end(), key) != pressed_keys.end()) {
        return false;
    }
    pressed_keys.push_back(key);
    return true;
}

bool Input::mouse_clicked(unsigned int button) {
    bool clicked = mb == button;
    if (!clicked) return false;
    if(!clicked_buttons.empty() && std::find(clicked_buttons.begin(), clicked_buttons.end(), button) != clicked_buttons.end()) {
        return false;
    }
    clicked_buttons.push_back(button);
    return true;
}

int Input::get_DX() {
    return (mx - width/2)/3;
    //    return dx;
}

int Input::get_DY() {
    return (height/2 - my)/3;
    //    return dy;
}

int Input::get_mouse_button() {
    return mb;
}

bool Input::mouse_in_circle(float x, float y, float r) {
    return powf(((float)get_DX()/100) - x, 2) + powf(((float)get_DY()/100) - y, 2) < powf(r, 2);
}

bool Input::mouse_in_rect(float x, float y, float l, float w) {
    return (((x - (w/2)) < ((float)get_DX()/100) < (x + (w/2))) && ((y + (l/2)) < ((float)get_DY()/100) < (y + (l/2))));
}


bool Input::window_closed() {
    return quit;
}





