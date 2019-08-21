#include <iostream>
#include <array>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player(int id, string name, char color,int row, int col)
{
    this->id = id;
    this->name = name;
    this->color = color;
    this->position[0] = row;
    this->position[1] = col;
}

void Player::move(char direction)
{
    switch (direction)
    {
    case 'U': moveUp();break;
    case 'D': moveDown();break;
    case 'L': moveLeft();break;
    case 'R': moveRight();break;
    default: cout<<"Incorrect instruction!"<<endl;
    }
    cout<<"Current Position" <<endl;
    cout<<"["<<position[0]<<", "<<position[1]<<"]"<<endl;


}

bool Player::crash(Player p, vector<array<int, 2>> trace)
{
    if (position == p.getPosition())
        return true;
    for (array<int,2> pass:trace)
        if(position == pass)
            return true;
    return false;
}

// Accessors
array<int,2> Player::getPosition()
{   
    // For Draw
    return position;
}

char Player::getColor()
{
    return color;
}


// Moves
void Player::moveUp()
{
    position[0]--;
}

void Player::moveDown()
{
    position[0]++;
}
void Player::moveLeft()
{
    position[1]--;
}
void Player::moveRight()
{
    position[1]++;
}

