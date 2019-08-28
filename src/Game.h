#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include <vector>
#include "Bot.h"
#include <iostream>
class Game
{
public:
    Game();
    ~Game();
    void menu();

private:
    int id = 0;
    int size;
    Board* b1;
    Player* p1;
    Player* p2;
    void setup();

    void update();
    // Person vs Person
    void RUN();
    // Person vs Compuer
    void initPVC();
    void initPVP();
    void initCVC();

    Player* initHuman(string color, int row, int col);
    Player* initBot(string name, string color, int row, int col, int difficulty);

    vector<array<int, 2>> trace;
    void initDeadZone();
};

