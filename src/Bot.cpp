#include <iostream>
#include "Bot.h"
using namespace std;

Bot::Bot(int id,string name, string color, int row, int col, int difficulty)
{
    Player(id, name, color, row, col);
    this->difficulty = difficulty;
}

char Bot::randomWalk()
{
    return 'a';
}
