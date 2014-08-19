//
//  Game.h
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__Game__
#define __Zorkish__Game__

#include <iostream>
#include "AboutMenu.h"
#include "HelpMenu.h"
#include "HallOfFameMenu.h"
#include "UserInput.h"
#include "Player.h"

class Game {
private:
    AboutMenu about;
    HelpMenu help;
    HallOfFameMenu hof;
    
    Player player;
    std::string move;
    std::string hr = "===================================";
    bool end;
public:
    Game();
    
    void SelectMenu(int i);
    
    bool End();
    void Update();
    void Check();
    void Render();
    
};

#endif /* defined(__Zorkish__Game__) */
