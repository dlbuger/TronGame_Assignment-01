#include "Bot.h"
#include <algorithm>
using namespace std;

Bot::Bot(int id,string name, string color, int row, int col, int difficulty)
{
    Player(id, name, color, row, col);
    this->difficulty = difficulty;
}

char Bot::randomWalk()
{
    
}

char Bot::popChoice()
{
    char choices[] = {'U','D','L','R'};
    srand (time(NULL)); // random seed
    return choices[rand()%4];
}

bool Bot::isSuicide(char direction)
{

}

array<int, 2> Bot::preMove(char direction)
{   
    array<int, 2> privatePosition = position;
    switch (direction)
    {
    case 'U': privatePosition[0]-1;break;
    case 'D': privatePosition[0]+1;break;
    case 'L': privatePosition[1]-1;break;
    case 'R': privatePosition[1]+1;break;
    }
    return privatePosition;
}
