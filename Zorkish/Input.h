//
//  Input.h
//  Zorkish
//
//  Created by Hugh Lee on 2/09/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Input__
#define __Zorkish__Input__

#include <iostream>
#include <vector>
#include <string>
#include "Data.h"
#include "Player.h"
#include "Container.h"

class Input {
private:
public:
    void static process(std::string n, Player& p, Structure s);
    void static player(std::vector<std::string> input, Player& p, Structure s);//go
    void static info(std::vector<std::string> input, Player& p);//look
    void static item(std::vector<std::string> input, Player& p);//take, drop
    
    //void static attack();//
    //void static defend();
    //void static flee();
};
#endif /* defined(__Zorkish__Input__) */
