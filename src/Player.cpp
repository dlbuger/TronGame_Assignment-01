#include <iostream>
#include <array>
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
    }
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
    position[0]++;
}

void Player::moveDown()
{
    position[0]--;
}
void Player::moveLeft()
{
    position[1]--;
}
void Player::moveRight()
{
    position[1]++;
}

