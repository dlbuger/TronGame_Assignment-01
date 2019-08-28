#include <iostream>
#include <array>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player(int id, string name, string color,int row, int col)
{
    this->id = id;
    this->name = name;
    this->color = color;
    this->position[0] = row;
    this->position[1] = col;
    selfTrace.push_back(position);
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
    selfTrace.push_back(position);
    cout<<"\t["<<position[0]<<", "<<position[1]<<"]"<<endl;
}

bool Player::crash(Player p, vector<array<int, 2>> trace)
{
    if (position == p.getPosition())
    {   
        cout<< "Draw." << endl;
        return true;
    }
    for (array<int,2> pass:trace){
        cout<<"Passed Potions"<<endl;
        cout<<"\t["<<pass[0]<<", "<<pass[1]<<"]"<<endl;
        if(position == pass){
            cout << color << " Crashed, Game Over!" << endl;
            return true;
        }
    }
    return false;
}

// Accessors
array<int,2> Player::getPosition()
{   
    // For Draw
    return position;
}

string Player::getColor()
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

