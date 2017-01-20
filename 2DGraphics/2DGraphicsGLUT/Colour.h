//
//  Colour.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 24/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Colour_h
#define Colour_h

/*
 * Colour Class
 * The colour class will be used as the 
 */
class Colour {
public:
    enum Code {
        NONE = 0,
        RED = 1,
        GREEN = 2,
        BLUE = 3,
        WHITE = 4
    };
    
    static void set_colour(Code c) {
        switch(c) {
            case RED: glColor3f(1.0,0.0,0.0);
                break;
            case GREEN: glColor3f(0.0,1.0,0.0);
                break;
            case BLUE: glColor3f(0.0,0.0,1.0);
                break;
            case WHITE: glColor3f(1.0,1.0,1.0);
                break;
            default:
                break;
        }
    }
    
    static Code int_to_colour(int i) {
        if (i == 1) return RED;
        else if (i == 2) return GREEN;
        else if (i == 3) return BLUE;
        else if (i == 4) return WHITE;
        else return NONE;
    }
};

#endif /* Colour_h */
