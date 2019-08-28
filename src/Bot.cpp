#include "Bot.h"
#include <algorithm>
using namespace std;


// Random Walk
char Bot::generateChoice()
{
    int counter = 0;
    char botChoice = popChoice();
    while(isSuicide(botChoice))
    {
        botChoice = popChoice();
        counter++;

        if (counter % 3080000 == 0)
            cout<<"Tried Time ---> "<<counter<<endl;
        /*     return popChoice(); */
    }
    cout<<"Tried Time ---> "<<counter<<endl;
    return botChoice;
}

char Bot::popChoice()
{
    char choices[] = {'U','D','L','R'};
    srand (time(NULL)); // random seed
    return choices[rand()%4];
}

bool Bot::isSuicide(char direction)
{   
    for (array<int, 2> c:selfTrace)
        if (preMove(direction) == c)
            return true;
    
    if (preMove(direction)[0] == -1)
        return true;
    else if (preMove(direction)[0] == mapSize)
        return true;
    
    if (preMove(direction)[1] == -1)
        return true;
    else if (preMove(direction)[1] == mapSize)
        return true;

    return false;
}

array<int, 2> Bot::preMove(char direction)
{   
    array<int, 2> privatePosition = position;
    switch (direction)
    {
    case 'U': privatePosition[0]-=1;break;
    case 'D': privatePosition[0]+=1;break;
    case 'L': privatePosition[1]-=1;break;
    case 'R': privatePosition[1]+=1;break;
    }
    return privatePosition;
}
