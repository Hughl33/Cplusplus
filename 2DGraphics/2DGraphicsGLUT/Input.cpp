//
//  Input.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 12/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include "Input.h"
Input::Input() {
    for (unsigned int i = 0; i < 256; i++) keys[i] = false;
}

//Keys
bool Input::keys[256];
std::vector<unsigned int> Input::pressed_keys;
std::vector<unsigned int> Input::clicked_buttons;

//Mouse Properties
int Input::mx;
int Input::my;
int Input::mb;
//bool Input::md;

void Input::keyboardDown(unsigned char key, int x, int y) {
    keys[key] = true;
}

void Input::keyboardUp(unsigned char key, int x, int y) {
    keys[key] = false;
}

void Input::mouseMove(int button, int state, int x, int y) {
    if (state == GLUT_UP) {
        mb = 3;
        if (!clicked_buttons.empty() && std::find(clicked_buttons.begin(), clicked_buttons.end(), button) != clicked_buttons.end()) {
            clicked_buttons.erase(std::find(clicked_buttons.begin(), clicked_buttons.end(), button));
        }
        mx = x;
        my = y;
    }
}

std::vector<unsigned int> Input::get_pressed_keys() {
    std::vector<unsigned int> result;
    for (unsigned int i = 0; i < 256; i++) if (keys[i]) result.push_back(i);
    return result;
}

bool Input::key_pressed(unsigned int key) {
    return keys[key];
}

bool Input::key_typed(unsigned int key) {
    bool pressed = key_pressed(key);
    if (!pressed) return false;
    if(!pressed_keys.empty() && std::find(pressed_keys.begin(), pressed_keys.end(), key) != pressed_keys.end()) {
        return false;
    }
    pressed_keys.push_back(key);
    return true;
}

bool Input::mouse_clicked(unsigned int button) {
    if(!clicked_buttons.empty() && std::find(clicked_buttons.begin(), clicked_buttons.end(), button) != clicked_buttons.end()) {
        return false;
    }
    clicked_buttons.push_back(button);
    return true;
}

float Input::get_DX() {
    return -(600/2 - mx);
//        return mx;
}

float Input::get_DY() {
    return (600/2 - my);
//        return my;
}

float Input::get_X() {
    return mx - 27;
}

float Input::get_Y() {
    return my - 27;
}
