#pragma once

class Board
{
public:
    Board(int size);
    void display();
    ~Board();

private:
    int size;
    void initVector(int size);
};

