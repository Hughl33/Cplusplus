//
//  Drawer.h
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 4/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#ifndef Drawer_h
#define Drawer_h

#include <stdio.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <vector>
#include "Colour.h"
#include "Input.h"
#include "Maze.h"
#include "Vector2f.h"
#include "Vector2i.h"

class Drawer {
private:
    //
    Input input;
    Vector2f one;
    Vector2f two;
    Maze mazeGenerator;
    
    //Properties
    int size;
    int segments;
    float radius;
    int offset;
    int state;
    int animateT;
    int animateC;
    int animateP;
    bool triAni;
    bool cirAni;
    bool pthAni;
    bool catchC; //This is the value that will catch the first click (See Update Function in .cpp file)
    
    //Calculations
    float transform(float a);
    float distance(Vector2f a, Vector2f b);
    Vector2f shrink(Vector2f a, float size, float offset);
    Vector2i coords_to_cell(Vector2f a, int offst = 0);
    Vector2f cell_to_coords(Vector2i a, float offst = 0.0);
    float gcd(float a, float b);
    
    //Value Settings
    void SetOne(float x, float y);
    void SetTwo(float x, float y);
    void Clear();
    
    //Shape Rendering Functions
    void LineGL(Vector2f  a, Vector2f  b, Colour::Code colour);
    std::vector<Vector2f> LineDDA(Vector2f a, Vector2f b, Colour::Code colour);
    void CircleLine(Vector2f a, float r, Colour::Code colour);
    std::vector<Vector2f> SemiCircleLine(Vector2f a, Vector2f b, Colour::Code colour);
    void CircleFill(Vector2f a, float r, Colour::Code colour);
    std::vector<Vector2f> TriangleLine(Vector2f a, Vector2f b, Vector2f c, Colour::Code colour);
    void TriangleFill(Vector2f a, Vector2f b, Vector2f , Colour::Code colour  );
    void MazeLine();
    std::vector<Vector2f> Path();
public:
    Drawer(int s);
    void init();
    bool Running();
    void Update();
    void Draw();
    void TestDraw();
};

#endif /* Drawer_h */
