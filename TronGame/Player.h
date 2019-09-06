#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	/*Player(int id, string name, string color, int position[2]);*/
	void move();
	int* getPosition(); // 返回玩家的坐标 [x, y]
	string getName(); //返回玩家的名字
	string getColor(); // 返回玩家的颜色
	virtual char generateChoice() = 0; // 生成Move
	~Player() {}; // 解析函数

protected:
	int* position; // 玩家目前位置的坐标指针
	int id;
	string name;
	string color;

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

