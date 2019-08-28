#pragma once
#include "Player.h"

class Bot: public Player
{
public:
    Bot(int id,string name, string color, int row, int col, int difficulty);
    ~Bot() {}

private:
    int difficulty;
    char popChoice();
    bool isSuicide(char direction);
    array<int, 2> preMove(char direction);
    char randomWalk();
    char MCTS();
};

