#pragma once
#include "Player.h"
#include "Board.h"

class Game
{
public:
    Game();
    ~Game();
    void setup();
    void run();
    void menu();

private:
    int size;
    Board *b1;
    Player *p1;
    Player *p2;
};

