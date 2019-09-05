#include "Player.h"


Player::Player(int id, string name, string color, int position[2])
{
	this->id = id;
	this->name = name;
	this->color = color;
	this->position = position;
	tail = new int* [20];
	for (int i = 0; i < 20; i++)
		tail[i] = new int[2];
}

void Player::move()
{
	switch (generateChoice())
	{
	case 'U': moveUp(); break;
	case 'D': moveDown(); break;
	case 'L': moveLeft(); break;
	case 'R': moveRight(); break;
	default: cout << "Incorrect Instruction!" << endl;
	}
	// 走了后需要把新的坐标记录下来 --> 移到了Game类里
}
int* Player::getPosition()
{
	return position;
}
string Player::getColor()
{
	return color;
}
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


