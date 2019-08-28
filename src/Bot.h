#pragma once
#include "Player.h"

class Bot: virtual public Player
{
public:
    Bot(int id,string name, string color, int row, int col, int difficulty): Player(id,name,color,row,col)
    {
        this->difficulty = difficulty;
    }
    ~Bot() {}

private:
    int difficulty;
    bool isSuicide(char direction);
    array<int, 2> preMove(char direction);
    char generateChoice();
    char popChoice();
    char MCTS();
};

