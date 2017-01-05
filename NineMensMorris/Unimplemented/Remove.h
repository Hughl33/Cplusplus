//
//  Remove.h
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//

#ifndef __NineMensMorris__Remove__
#define __NineMensMorris__Remove__

#include <iostream>
#include "Move.h"

class Remove : public Move {
private:
public:
    bool static performMove(Player& p, Vertex& a);
};

#endif /* defined(__NineMensMorris__Remove__) */
