//
//  Direction.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 22/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include "Direction.h"

/*
 * Constructor that will initialise the Direction class with the Direction's bit value, x increment/
 * decrement, y increment/decrement, and opposite bit value
 */
Direction::Direction(int b, int x, int y, int o) {
    bit = b;
    dx = x;
    dy = y;
    opposite = o;
}

/*
 * Returns the Bit value for the direction
 */
int Direction::getBit() {
    return bit;
}

/*
 * Returns the x increment/decrement for the cooresponding direction
 */
int Direction::getDX() {
    return dx;
}

/*
 * Returns the y increment/decrement for the cooresponding direction
 */
int Direction::getDY() {
    return dy;
}

/*
 * Returns the bit value of the opposite direction
 */
int Direction::getOpposite() {
    return opposite;
}
