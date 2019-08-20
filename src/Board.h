#pragma once
#include "Player.h"
class Board
{
public:
    Board(int size);
    Board(){}
    void display();
    void setCurrentPosition(int position[], Player *p);    
    void update(Player *p, char mark);
    void initPlayer(Player *p1, Player *p2); // Display Two Players' start position
    int getSize();
    ~Board();

private:
    int size;
    void initVector(int size);
};

