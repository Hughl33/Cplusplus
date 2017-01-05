//
//  Fly.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Fly__
#define __NineMensMorris__Fly__

#include <iostream>
#include "Move.h"

class Fly : public Move {
private:
public:
    bool static performMove(Vertex& a, Vertex& b);
};

#endif /* defined(__NineMensMorris__Fly__) */
