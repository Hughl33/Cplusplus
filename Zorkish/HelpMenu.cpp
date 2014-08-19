//
//  HelpMenu.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "HelpMenu.h"
HelpMenu::HelpMenu() {
    title = "Help";
}

void HelpMenu::Render() {
    std::cout << hr << std::endl;
    std::cout << "Zorkish :: " << title << std::endl;
    std::cout << hr << std::endl;
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "  quit" << std::endl;
    std::cout << "  hiscore (for testing)" << std::endl;
    std::cout << std::endl;
    std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
    std::cin.get();
    std::cin.get();
}