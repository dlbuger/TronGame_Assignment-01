#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include <vector>
#include <iostream>
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
    Board* b1;
    Player* p1;
    Player* p2;
    void PVP();
    vector<array<int, 2>> trace;
    void initDeadZone();
};

