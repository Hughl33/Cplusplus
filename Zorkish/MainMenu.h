//
//  MainMenu.h
//  Zorkish
//
//  Created by Hugh Lee on 25/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#ifndef __Zorkish__MainMenu__
#define __Zorkish__MainMenu__

#include <iostream>
#include "Menu.h"
#include "AboutMenu.h"
#include "HelpMenu.h"
#include "HallOfFameMenu.h"
#include "PlayMenu.h"

class MainMenu: public Menu {
private:
    AboutMenu about;
    HelpMenu help;
    HallOfFameMenu hof;
    PlayMenu play;
    
    std::string mode;
    std::string move;
    std::string hr = "===================================";
    bool start;
    bool end;
public:
    MainMenu();
    
    void SelectMenu(int i);
    
    bool End();
    bool Start();
    void Update();
    void Check();
    void Render();
};

#endif /* defined(__Zorkish__MainMenu__) */
