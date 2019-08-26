#pragma once
#include "Player.h"


class Human: virtual public Player
{
public:
    Human(int id, string name, string color, int row, int col):Player(id, name, color, row, col){}
    ~Human() {}

private:

};

