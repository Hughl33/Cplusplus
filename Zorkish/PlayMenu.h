//
//  PlayMenu.h
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__PlayMenu__
#define __Zorkish__PlayMenu__

#include <iostream>
#include "Menu.h"

class PlayMenu: public Menu {
private:
public:
    PlayMenu();
    void Render();
    int SelectAdventure();
};
#endif /* defined(__Zorkish__PlayMenu__) */
