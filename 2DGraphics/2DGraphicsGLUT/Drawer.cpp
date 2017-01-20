//
//  Drawer.cpp
//  2DGraphics_GLUT
//
//  Created by Hugh Lee on 4/08/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include "Drawer.h"

Drawer::Drawer(int s) : mazeGenerator(s/40, s/40) {
    size = s;
    segments = 500;
    radius = 10;
    offset = 50;
    state = 1;
    animateT = 0.0;
    animateC = 0.0;
    animateP = 0.0;
    triAni = false;
    cirAni = false;
    pthAni = false;
    catchC = false;
//    glutMotionFunc(input.mouseMove);
//    glutPassiveMotionFunc(input.mouseMove);
}

void Drawer::init() {
    glutKeyboardFunc(input.keyboardDown);
    glutKeyboardUpFunc(input.keyboardUp);
    glutMouseFunc(input.mouseMove);
}

float Drawer::transform(float a) {
    return a/(size/2);
}

float Drawer::distance(Vector2f a, Vector2f b) {
    return sqrtf(powf((b.x - a.x), 2) + powf((b.y - a.y), 2));
}

Vector2f Drawer::shrink(Vector2f a, float size, float offset) {
    return Vector2f((a.x * (size - offset))/size, (a.y * (size - offset))/size);
}

Vector2i Drawer::coords_to_cell(Vector2f a, int offst) {
    return Vector2i(((a.x * (size/40))/(size - offset)) + offst, ((a.y * (size/40))/(size - offset)) - offst);
}

Vector2f Drawer::cell_to_coords(Vector2i a, float offst) {
    return *new Vector2f(-((size/2) - (a.x * 40)) + offst, ((size/2) - (a.y * 40)) - offst);
}

float Drawer::gcd(float a, float b) {
    while(a != b) {
        if(b > a) {
            float c = b;
            b = a;
            a = c;
        }
        while(a > b) a -= b;
    }
    return(a);
}

void Drawer::SetOne(float x, float y) {
    one.x = x;
    one.y = y;
}

void Drawer::SetTwo(float x, float y) {
    two.x = x;
    two.y = y;
}

void Drawer::Clear() {
    animateT = 0.0;
    animateC = 0.0;
    animateP = 0.0;
    triAni = false;
    cirAni = false;
    pthAni = false;
    one = *new Vector2f();
    two = *new Vector2f();
}

void Drawer::Update() {
    if (Input::mouse_clicked(GLUT_LEFT_BUTTON)) {
        if (!catchC) {
            catchC = true; //This is utilised as for some reason GLUT clicks at the center of the window at the start of the program. This is to catch that click at the start.
        } else if (state < 3) {
            if ((one.x == 0 && one.y == 0)) SetOne(Input::get_DX(), Input::get_DY());
            else if ((two.x == 0 && two.y == 0)) SetTwo(Input::get_DX(), Input::get_DY());
            else Clear();
        } else if (state == 3) {
            if ((one.x == 0 && one.y == 0)) SetOne(Input::get_X(), Input::get_Y());
            else if ((two.x == 0 && two.y == 0)) SetTwo(Input::get_X(), Input::get_Y());
            else Clear();
        } else {
            Clear();
            std::cout << "Error: State is unknown" << std::endl;
        }
    }
    if (Input::key_pressed(27)) exit(0);
    if (Input::key_pressed('z') || Input::key_pressed('1') || Input::key_pressed('2') ||
        Input::key_pressed('3') || Input::key_pressed('4'))
            Clear(); //Clear the screen when the states are changed;
    if (Input::key_pressed('=') || Input::key_pressed('+'))
            if (radius < 20) radius += 0.5; //Added '=' so that shift key is not needed
    if (Input::key_pressed('-')) if (radius > 1) radius -= 0.5;
    if (Input::key_pressed('a')) {
        triAni = true;
        animateT = 0;
    }
    if (Input::key_pressed('c')) {
        cirAni = true;
        animateC = 0;
    }
    if (Input::key_pressed('s')) pthAni = true;
    if (Input::key_pressed('1')) state = 1;
    if (Input::key_pressed('2')) state = 2;
    if (Input::key_pressed('3')) state = 3;
}

void Drawer::Draw() {
    if (state == 1) {
        if (!((one.x == 0 && one.y == 0) || (two.x == 0 && two.y == 0))) {
            LineDDA(one, two, Colour::GREEN); //Drawing the DDA Line
        }
    } else if (state == 2) {
        if (!((one.x == 0 && one.y == 0) || (two.x == 0 && two.y == 0))) {
            if (!((one.x == two.x) && (one.y == two.y))) {
                if (!triAni && !cirAni) {
                    float dist = distance(one, two);
                    float buff = ((dist/radius) - floorf(dist/radius))/2;
                    int j = 1;
                    for (float i = buff + radius; i < dist; i += (radius*2)) {
                        float m = i/gcd(i, dist - i);
                        float n = (dist - i)/gcd(i, dist - i);
                        Vector2f pos = *new Vector2f(((one.x * m)/(m + n)) + ((two.x * n)/(m + n)), ((one.y * m)/(m + n)) + ((two.y * n)/(m + n)));
                        CircleFill(pos, radius, Colour::int_to_colour(j));
                        if (j < 3) j++;
                        else j = 1;
                    }
                }
                if (triAni) {
                    Vector2f three = *new Vector2f(two.x, one.y);
                    std::vector<Vector2f> points = TriangleLine(one, two, three, Colour::GREEN);
                    CircleFill(points[animateT], radius, Colour::RED);
                    if (animateT < points.size() - 1) animateT++;
                }
                if (cirAni) {
                    std::vector<Vector2f> points = SemiCircleLine(one, two, Colour::GREEN);
                    CircleFill(points[animateC], radius, Colour::RED);
                    if (animateC < points.size() - 1) animateC++;
                }
            }
        }
    } else if (state == 3) {
        MazeLine();
        std::vector<Vector2f> points = Path();
        if (!points.empty() && pthAni) {
            CircleFill(points[animateP], radius, Colour::RED);
            if (animateP < points.size() - 1) animateP++;
            else if (Input::key_pressed('s')) animateP = 0;
        }
    }
}

void Drawer::LineGL(Vector2f a, Vector2f b, Colour::Code colour) {
    glBegin(GL_LINES);
    Colour::set_colour(colour);
    glVertex2f(transform(a.x), transform(a.y));
    glVertex2f(transform(b.x), transform(b.y));
    glEnd();
}

std::vector<Vector2f> Drawer::LineDDA (Vector2f a, Vector2f b, Colour::Code colour) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    int steps = 0;
    Vector2f point = *new Vector2f(a.x, a.y);
    if (std::abs (dx) > std::abs (dy)) steps = std::abs (dx);
    else steps = std::abs (dy);
    Vector2f increment = *new Vector2f(float (dx) / float (steps), float (dy) / float (steps));
    std::vector<Vector2f> points = *new std::vector<Vector2f>;
    glBegin(GL_POINTS);
    Colour::set_colour(colour);
    glVertex2f(transform(point.x), transform(point.y));
    for (int k = 0; k < steps; k++) {
        points.push_back(point);
        point.x += increment.x;
        point.y += increment.y;
        glVertex2f(transform(point.x), transform(point.y));
    }
    glEnd();
    return points;
}

void Drawer::CircleLine(Vector2f a, float r, Colour::Code colour) {
    glBegin(GL_LINE_LOOP);
    Colour::set_colour(colour);
    for(int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);//get the current angle
        Vector2f cp = *new Vector2f(transform(r) * cosf(theta), transform(r) * sinf(theta));
        glVertex2f(cp.x + transform(a.x), cp.y + transform(a.y));//output vertex
    }
    glEnd();
}

std::vector<Vector2f> Drawer::SemiCircleLine(Vector2f a, Vector2f b, Colour::Code colour) {
    Vector2f temp;
    Vector2f mid = *new Vector2f((a.x + b.x)/2, (a.y + b.y)/2);
    float r = distance(a, b)/2;
    float angle = atan2(two.y - one.y, two.x - one.x);
    std::vector<Vector2f> points = *new std::vector<Vector2f>;
    glBegin(GL_LINE_STRIP);
    Colour::set_colour(colour);
    for(float i = 0; i < segments; i++) {
        float theta = M_PI * i / float(segments) + angle;//get the current angle
        Vector2f cp = *new Vector2f(r * cosf(theta), r * sinf(theta));
        glVertex2f(transform(cp.x + mid.x), transform(cp.y + mid.y));//output vertex
        temp = *new Vector2f(cp.x + mid.x, cp.y + mid.y);
        points.push_back(temp);
    }
    glEnd();
    std::vector<Vector2f> one = LineDDA(a, b, colour);
    std::reverse(points.begin(), points.end());
    std::reverse(one.begin(), one.end());
    for (int i = 0; i < one.size(); i++) points.push_back(one[i]);
    return points;
}

void Drawer::CircleFill(Vector2f a, float r, Colour::Code colour) {
    Vector2f b;
    glBegin(GL_TRIANGLE_FAN);
    Colour::set_colour(colour);
    glVertex2f(transform(a.x), transform(a.y));
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);//get the current angle
        b = *new Vector2f(r * cosf(theta), r * sinf(theta));
        glVertex2f(transform(b.x + a.x), transform(b.y + a.y));
    }
    glEnd();
}

std::vector<Vector2f> Drawer::TriangleLine(Vector2f a, Vector2f b, Vector2f c, Colour::Code colour) {
    std::vector<Vector2f> one = LineDDA(a, b, colour);
    std::vector<Vector2f> two = LineDDA(b, c, colour);
    std::vector<Vector2f> three = LineDDA(c, a, colour);
    std::vector<Vector2f> result = *new std::vector<Vector2f>;
    result.reserve(one.size() + two.size() + three.size());
    result.insert(result.end(), one.begin(), one.end());
    result.insert(result.end(), two.begin(), two.end());
    result.insert(result.end(), three.begin(), three.end());
    return result;
}

void Drawer::TriangleFill(Vector2f a, Vector2f b, Vector2f c, Colour::Code colour) {
    glBegin(GL_TRIANGLES);
    Colour::set_colour(colour);
    glVertex2f(transform(a.x), transform(a.y));
    glVertex2f(transform(b.x), transform(b.y));
    glVertex2f(transform(c.x), transform(c.y));
    glEnd();
}

void Drawer::MazeLine() {
    std::vector<std::vector<int>> maze = mazeGenerator.output();
    Vector2f a;
    Vector2f b;
    for (int i = 0; i < (size/40); i++) {
        for (int j = 0; j < (size/40); j++) {
            a = *new Vector2f(-((size/2) - (j * 40)), ((size/2) - (i * 40)));
            if ((maze[j][i] & 1) == 0) {
                b = *new Vector2f(a.x + (size/(size/40)), a.y);
                LineGL(shrink(a, size, offset), shrink(b, size, offset), Colour::WHITE);
            }
            if ((maze[j][i] & 8) == 0) {
                b = *new Vector2f(a.x, a.y - (size/(size/40)));
                LineGL(shrink(a, size, offset), shrink(b, size, offset), Colour::WHITE);
            }
        }
    }
    b = *new Vector2f(-(size/2 - size), (size/2 - size));
    a = *new Vector2f(-(size/2 - size), (size/2 - 0));
    LineGL(shrink(a, size, offset), shrink(b, size, offset), Colour::WHITE);
    a = *new Vector2f(-(size/2 - 0), (size/2 - size));
    LineGL(shrink(a, size, offset), shrink(b, size, offset), Colour::WHITE);
}

std::vector<Vector2f> Drawer::Path() {
    std::vector<Vector2f> points = *new std::vector<Vector2f>;
    if (!((one.x == 0 && one.y == 0) || (two.x == 0 && two.y == 0))) {
        Vector2f a;
        Vector2f b;
        Vector2i c = coords_to_cell(one);
        mazeGenerator.solve(c, coords_to_cell(two));
        std::vector<int> path = mazeGenerator.path();
        b = cell_to_coords(c, (((size - offset)/(size/40))/2));
        for (int i = 0; i < path.size(); i++) {
            a = b;
            if ((path[i] & 1) == 1) {
                c.y--;
            } else if ((path[i] & 2) == 2) {
                c.y++;
            } else if ((path[i] & 4) == 4) {
                c.x++;
            } else if ((path[i] & 8) == 8) {
                c.x--;
            }
            b = cell_to_coords(c, (((size - offset)/(size/40))/2));
            std::vector<Vector2f> temp = LineDDA(shrink(a, size, offset), shrink(b, size, offset), Colour::RED);
            points.reserve(points.size() + temp.size());
            points.insert(points.end(), temp.begin(), temp.end());
        }
    }
    return points;
}

void Drawer::TestDraw() {
//    float cx = 0.0;
//    float cy = 0.0;
//    float r = transform(100);
//    
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    for(int i = 0; i < segments; i++) {
//        float theta = M_PI * float(i) / float(segments);//get the current angle
//        float x = r * cosf(theta);//calculate the x component
//        float y = r * sinf(theta);//calculate the y component
//        glVertex2f(x + transform(cx), y + transform(cy));//output vertex
//    }
//    glEnd();
    
    //Unused
    
    //Rotation
//    Vector2f a;
//    a.x = 0.0;
//    a.y = -100.0;
//    Vector2f b;
//    b.x = 0.0;
//    b.y = 100.0;
//    Vector2f mid;
//    mid.x = (a.x + b.x)/2;
//    mid.y = (a.y + b.y)/2;
//    float r = distance(a, b)/2;
//    Vector2f c;
//    c.x = a.x;
//    c.y = mid.y;
//    float distOne = distance(c, mid);
//    float distTwo = distance(a, c);
//    float angle = 0.0;
//    if (a.x == b.x) angle = M_PI_2;
//    else angle = acosf((powf(r, 2) + powf(distOne, 2) - powf(distTwo, 2))/(2 * r * distOne));
//    
////    std::cout << "angle:" << angle <<std::endl;
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    for(int i = (angle * 100)/3; i < segments + ((angle * 100)/3); i++) {
//        float theta = M_PI * float(i) / float(segments);//get the current angle
//        float x = r * cosf(theta);//calculate the x component
//        float y = r * sinf(theta);//calculate the y component
//        glVertex2f(transform(x + mid.x), transform(y + mid.y));//output vertex
//    }
//    glEnd();
    
    //Draw utilising distances
//    TriangleLine(one, two, three);
//    float distOne = distance(one, two);
//    float distTwo = distance(two, three);
//    float distThree = distance(three, one);
//    Vector2f pos;
//    if (animate < distOne) {
//        float m = animate/gcd(animate, distOne - animate);
//        float n = (distOne - animate)/gcd(animate, distOne - animate);
//        pos.x = ((one.x * m)/(m+n)) + ((two.x * n)/(m+n));
//        pos.y = ((one.y * m)/(m+n)) + ((two.y * n)/(m+n));
//        CircleLine(pos, radius);
//    } else if (animate < distTwo + distOne) {
//        float m = (animate - distOne)/gcd((animate - distOne), distTwo - (animate - distOne));
//        float n = (distTwo - (animate - distOne))/gcd((animate - distOne), distTwo - (animate - distOne));
//        pos.x = ((two.x * m)/(m+n)) + ((three.x * n)/(m+n));
//        pos.y = ((two.y * m)/(m+n)) + ((three.y * n)/(m+n));
//        CircleLine(pos, radius);
//    } else if (animate < distThree + distTwo + distOne) {
//        float m = (animate - distOne - distTwo)/gcd((animate - distOne - distTwo), distThree - (animate - distOne - distTwo));
//        float n = (distTwo - (animate - distOne - distTwo))/gcd((animate - distOne - distTwo), distThree - (animate - distOne - distTwo));
//        pos.x = ((three.x * m)/(m+n)) + ((one.x * n)/(m+n));
//        pos.y = ((three.y * m)/(m+n)) + ((one.y * n)/(m+n));
//        CircleLine(pos, radius);
//    }
//    if (animate < distOne + distTwo + distThree) animate += 0.1;
//    else animate = 0.0;
    //Rotating Semi Circle v1
//    Vector2f temp;
//    Vector2f mid = *new Vector2f((a.x + b.x)/2, (a.y + b.y)/2);
//    Vector2f c = *new Vector2f(a.x, mid.y);
//    float r = distance(a, b)/2;
//    float distOne = distance(c, mid);
//    float distTwo = distance(a, c);
//    float angle = 0.0;
//    if (a.x == b.x) angle = M_PI_2;
//    else angle = acosf((powf(r, 2) + powf(distOne, 2) - powf(distTwo, 2))/(2 * r * distOne));
//    if (a.y > b.y) angle *= -1;
//    std::vector<Vector2f> points = *new std::vector<Vector2f>;
//        float trans = ((angle * segments)/M_PI);
//    glBegin(GL_LINE_STRIP);
//    Colour::set_colour(colour);
//    for(float i = trans; i < segments + trans - 1; i++) {
//        float theta = M_PI * i / float(segments) + angle;//get the current angle
//        float x = r * cosf(theta);//calculate the x component
//        float y = r * sinf(theta);//calculate the y component
//        glVertex2f(transform(x + mid.x), transform(y + mid.y));//output vertex
//        temp = *new Vector2f(x + mid.x, y + mid.y);
//        points.push_back(temp);
//    }
//    glEnd();
//    std::vector<Vector2f> one = LineDDA(a, b, colour);
//    std::reverse(points.begin(), points.end());
//    std::reverse(one.begin(), one.end());
//    for (int i = 0; i < one.size(); i++) points.push_back(one[i]);
//    return points;
}
