#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(int id, string name, string color, int position[2]);
	void move();
	int* getPosition(); // 返回玩家的坐标 [x, y]
	string getName(); //返回玩家的名字
	string getColor(); // 返回玩家的颜色

protected:
	virtual char generateChoice() = 0;
	int* position; // 玩家目前位置的坐标指针

	
private: // Attributes
	int id;
	string name;
	string color;
	
	int** tail; // 玩家走过的位置

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

