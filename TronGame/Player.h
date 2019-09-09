#pragma once
#include <iostream>
#include <array>
using namespace std;

class Player
{
public:
	/*Player(int id, string name, string color, int position[2]);*/
	void move();
	array<int,2> getPosition(); // 返回玩家的坐标 [x, y]
	string getName(); //返回玩家的名字
	string getColor(); // 返回玩家的颜色
	virtual char generateChoice() = 0; // 生成Move
	~Player(); // 解析函数

protected:
	array<int,2> position; // 玩家目前位置的坐标指针
	int id;
	string name;
	string color;

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

