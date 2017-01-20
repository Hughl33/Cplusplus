//
//  Input.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 12/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Input_h
#define Input_h

#include <iostream>
#include <vector>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

class Input {
private:
    //Keys
    static bool keys[256];
    static std::vector<unsigned int> pressed_keys;
    static std::vector<unsigned int> clicked_buttons;
    
    //Mouse Properties
    static int mx, my, mb;
public:
    Input();
    static void keyboardDown(unsigned char key, int x, int y);
    static void keyboardUp(unsigned char key, int x, int y);
    static void mouseMove(int button, int state, int x, int y);
    std::vector<unsigned int> get_pressed_keys();
    static bool key_pressed(unsigned int key);
    static bool key_typed(unsigned int key);
    static bool mouse_clicked(unsigned int button);
    static float get_DX();
    static float get_DY();
    static float get_X();
    static float get_Y();
};

#endif /* Input_h */
