#pragma once
#include <iostream>
#include <array>
#include <vector>
using namespace std;


class Player
{
public:
    Player(int id, string name, char color, int row, int col);
    Player(){}
    void move(char direction);
    bool crash(Player p,vector<array<int, 2>> trace);
    array<int, 2> getPosition();
    char getColor();
    ~Player(){
        cout<<"End of :Player "<<endl;
    }

private:
    int id;
    string name;
    char color;
    array<int,2> position; // current coordinate
    /* vector<int [2]> trace; // Passed position */
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

