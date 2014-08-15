//
//  Game.cpp
//  GridWorld
//
//  Created by Hugh Lee on 5/08/2014.
//  Copyright (c) 2014 OysterFinish. All rights reserved.
//

#include "Game.h"

Game::Game() : player (6, 3) {
    end = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = "#";
        }
    }
    map[1][1] = "G";
    map[1][3] = "D";
    map[1][5] = "D";
    map[3][6] = "D";
    map[1][2] = " ";
    map[1][6] = " ";
    map[2][1] = " ";
    map[2][2] = " ";
    map[2][3] = " ";
    map[2][5] = " ";
    map[2][6] = " ";
    map[3][3] = " ";
    map[3][5] = " ";
    map[4][1] = " ";
    map[4][2] = " ";
    map[4][3] = " ";
    map[4][5] = " ";
    map[4][6] = " ";
    map[5][1] = " ";
    map[5][6] = " ";
    map[6][1] = " ";
    map[6][2] = " ";
    map[6][3] = " ";
    map[6][4] = " ";
    map[6][5] = " ";
    map[6][6] = " ";
    map[player.PositionY()][player.PositionX()] = "X";
}

bool Game::End() {
    return end;
}

void Game::Turn () {
    cout << "You can move ";
    for (int i = 0; i < 4; i++) {
        if (moves[i] != "#") cout << moves[i] << " ";
    }
    cout << ":> ";
    cin >> move;
}

void Game::RenderMap () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void Game::Update () {
    map[player.PositionY()][player.PositionX()] = " ";
    
    if (move == "n") player.up();
    else if (move == "e") player.right();
    else if (move == "w") player.left();
    else if (move == "s") player.down();
    
    map[player.PositionY()][player.PositionX()] = "X";
}

bool Game::CheckInput() {
    for (int i = 0; i < 4; i++) {
        if (moves[i] != "#") {
            if (move == moves[i]) return true;
        }
    }
    if (move == "q") end = true;
    else cout << "That is an invalid input" << endl;
    return false;
}

void Game::CheckMoves() {
    if (map[player.PositionY()-1][player.PositionX()] != "#") moves[0] = "n";
        else moves[0] = "#";
    
    if (map[player.PositionY()+1][player.PositionX()] != "#") moves[1] = "s";
        else moves[1] = "#";
    
    if (map[player.PositionY()][player.PositionX()-1] != "#") moves[2] = "w";
        else moves[2] = "#";
    
    if (map[player.PositionY()][player.PositionX()+1] != "#") moves[3] = "e";
        else moves[3] = "#";
}

void Game::CheckStatus() {
    if ((player.PositionY() == 1 && player.PositionX() == 3) || (player.PositionY() == 1 && player.PositionX() == 5) || (player.PositionY() == 3 && player.PositionX() == 6)) {
        end = true;
        cout << "Arrrrgh... you've fallen down a pit." << endl;
        cout << "YOU HAVE DIED!" << endl;
    }
    
    if (player.PositionY() == 1 && player.PositionX() == 1) {
        end = true;
        cout << "Wow - you've discovered a large chest filled with GOLD coins!" << endl;
        cout << "YOU WIN!" << endl;
    }
}

