#pragma once
#include <iostream>
#include <array>
#include <vector>
using namespace std;


class Player
{
public:
    Player(int id, string name, string color, int row, int col);
    Player(){}
    string getName();
    void move(char direction);
    bool crash(Player p, vector<array<int, 2>> trace);
    array<int, 2> getPosition();
    string getColor();
    virtual char generateChoice();
    virtual ~Player(){

    }

protected:
    int id;
    string name;
    string color;
    array<int,2> position; // current coordinate
    vector<array<int, 2>> selfTrace;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
private:


};
