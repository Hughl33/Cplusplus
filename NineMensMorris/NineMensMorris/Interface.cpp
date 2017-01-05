//
//  Interface.cpp
//  NineMensMorris
//
//  Created by Hugh Lee on 06/05/2016.
//  Copyright (c) 2016 OysterFinish. All rights reserved.
//  Adapted from my assignment in semester 1 2015
//

#include "Interface.h"
std::string Interface::event = "White - 'O' goes first.";

Interface::Interface(Layout l, int w, int h) {
    layout = l;
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    clear();
    maxX = w;
    maxY = h;
    menu_win = newwin(h, w, y, x);
    keypad(menu_win, TRUE);
    refresh();
}

WINDOW *Interface::getWindow() {
    return menu_win;
}

int Interface::getX() {
    return x;
}

int Interface::getY() {
    return y;
}

int Interface::getMaxX() {
    return maxX;
}

int Interface::getMaxY() {
    return maxY;
}

void Interface::broadcast(std::string e) {
    event = e;
}

void Interface::render(std::vector<Vertex> v, int current, std::vector<Player> p, int selected) {
    clear();
    renderLayout();
    renderInstructions();
    renderInfo(p);
    renderPiece(v);
    renderSelector(v, current, selected);
    renderEvent();
    refresh();
}

void Interface::renderEvent() {
    y = 42;
    x = 3;
    for (int i = 0; i < event.length(); i++) {
        move(y, x);
        delch();
        insch(event[i]);
        x++;
    }
}

void Interface::renderPiece(std::vector<Vertex> v) {
    char piece = '\0';
    for (int i = 0; i < v.size(); i++) {
        if (v[i].ifOccupied()) {
            if (v[i].getPiece()->getColour() == Colour::WHITE) piece = 'O';
            else if (v[i].getPiece()->getColour() == Colour::BLACK) piece = 'X';
            y = v[i].getCoords().y - 1;
            for (int j = 0; j < layout.piece.size(); j++) {
                x = v[i].getCoords().x - 2;
                for (int k = 0; k < layout.piece[j].length(); k++) {
                    move(y, x);
                    delch();
                    insch(piece);
                    x++;
                }
                y++;
            }
        }
    }
    
}

void Interface::renderInfo(std::vector<Player> p) {
    char piece;
    for (int i = 0; i < p.size(); i++) {
        if (p[i].getPiece(0)->getColour() == Colour::WHITE) piece = 'O';
        else piece = 'X';
        
        y = 3 + (i * 20);
        for (int j = 0; j < layout.info.size(); j++) {
            x = 86;
            for (int k = 0; k < layout.info[j].length(); k++) {
                move(y, x);
                delch();
                insch(layout.info[j][k]);
                x++;
            }
            y++;
        }

        for (int j = 0; j < p[i].piecesLeft(); j++) {
            y = (8 + (i * 20)) + (((j/3) % 3) * 4);
            for (int k = 0; k < layout.piece.size(); k++) {
                x = 89 + (j % 3 * 10);
                for (int l = 0; l < layout.piece[k].length(); l++) {
                    move(y, x);
                    delch();
                    if (p[i].getPiece(j)->getState()) insch(piece);
                    else insch(layout.piece[k][l]);
                    x++;
                }
                y++;
            }
        }

        y = 5 + (i * 20);
        x = 90;
        std::string name = "Player i (E)";
        for (int j = 0; j < name.length(); j++) {
            move(y, x);
            delch();
            if (name[j] == 'i') insch(*std::to_string(i + 1).c_str());
            else if (name[j] == 'E') insch(piece);
            else insch(name[j]);
            x++;
        }
    }
}

void Interface::renderInstructions() {
    y = 3;
    for (int i = 0; i < layout.instructions.size(); i++) {
        x = 122;
        for (int j = 0; j < layout.instructions[i].length(); j++) {
            move(y,x);
            delch();
            insch(layout.instructions[i][j]);
            x++;
        }
        y++;
    }
}

void Interface::renderSelector(std::vector<Vertex> v, int current, int selected) {
    y = v[current - 1].getCoords().y;
    for (int i = 0; i < layout.selector.size(); i++) {
        x = v[current - 1].getCoords().x;
        for (int j = 0; j < layout.selector[i].length(); j++) {
            if (!isspace(layout.selector[i][j])) {
                move(y - 2, x - 4);
                delch();
                insch(layout.selector[i][j]);
            }
            x++;
        }
        y++;
    }
    if (selected > 0) {
        y = v[selected - 1].getCoords().y;
        for (int i = 0; i < layout.selected.size(); i++) {
            x = v[selected - 1].getCoords().x;
            for (int j = 0; j < layout.selected[i].length(); j++) {
                if (!isspace(layout.selected[i][j])) {
                    move(y - 2, x - 4);
                    delch();
                    insch(layout.selected[i][j]);
                }
                x++;
            }
            y++;
        }
    }
}

void Interface::renderLayout() {
    for (int i = 0; i < layout.board.size(); i++) {
        for (int j = 0; j < layout.board[i].length(); j++) {
            move(i, j);
            delch();
            insch(layout.board[i][j]);
        }
    }
}

void Interface::close() {
    int d = ' ';
    while (true) {
        d = wgetch(menu_win);
        if (d == '\n') break;
    }
    endwin();
    delwin(menu_win);
}