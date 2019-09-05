#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(int id, string name, string color, int position[2]);
	void move();
	int* getPosition();

protected:
	virtual char generateChoice() = 0;
	

	
private: // Attributes
	int id;
	string name;
	string color;
	int* position; // 玩家目前位置的坐标指针
	int** tail; // 玩家走过的位置

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

