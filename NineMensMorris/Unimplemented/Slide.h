//
//  Slide.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Slide__
#define __NineMensMorris__Slide__

#include <iostream>
#include "Move.h"

class Slide : public Move {
private:
public:
    bool static performMove(Vertex& a, Vertex& b);
};
#endif /* defined(__NineMensMorris__Slide__) */
