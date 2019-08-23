#pragma once
#include "Player.h"
#include <vector>
#include <array>
class Board
{
public:
    Board(int size);
    Board(){}
    void display();
    void setCurrentPosition(int position[], Player *p);    
    void initPlayer(Player *p1, Player *p2); // Display Two Players' start position
    void update(Player *p, char mark);
    int getSize();
    vector<array<int, 2>> getDeadZone();
    ~Board()
    {
    /* cout << "End of :Board"<<endl; */
    }

private:
    int size;
    void initVector(int size);
    void initDeadZone();
};

