#pragma once
#include "Player.h"
#include <vector>

class Bot : public Player
{


protected: // methods
	char popChoice(); // 随机生成移动方向
	bool isSuicide(char direction); // 判断随机生成的移动方向是否会导致死亡
	int counter = 0;
	virtual char generateChoice() = 0; // 生成一个有效的移动方向
	int mapSize;
	vector<array<int, 2>>* tails; // 自己和对手移动过的坐标
	

private:
	array<int,2> preMove(char direction);
	

};

