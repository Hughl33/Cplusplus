//
//  HallOfFame.cpp
//  Zorkish
//
//  Created by Hugh Lee on 19/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "HallOfFameMenu.h"
HallOfFameMenu::HallOfFameMenu() {
    title = "Hall of Fame";
}

void HallOfFameMenu::Render() {
    std::vector<std::string> hof = Data::getHOF();
    std::cout << hr << std::endl;
    std::cout << "Zorkish :: " << title << std::endl;
    std::cout << hr << std::endl;
    for (int i = 0; i < hof.size(); i++) {
        std::cout << hof[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
    std::cin.get();
}