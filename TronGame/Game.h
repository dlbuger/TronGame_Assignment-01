#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "EasyBot.h"

class Game
{
public:
	Game();
	int getBoardSize();
	int** getTail(); // 每个玩家每走一步就会把当前坐标传入
private: // methods
	void menu();
	void initPVP();
	void initPVC();
	void initCVC();
	bool endGame(); // 判定游戏是否结束
	void RUN(); // 游戏一回合的周期
	Player* humanPlayer(string color, int position[2]);

private: // Attributes
	int playerID = 0;
	int size;
	int round = 0; // 每进行一个回合 ++
	int** tail;
	Board* b1;
	Player* p1;
	Player* p2;

};

