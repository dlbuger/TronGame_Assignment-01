#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "EasyBot.h"
#include <vector>

class Game
{
public:
	Game();
	int getBoardSize();
	vector<array<int, 2>> getTail(); // 每个玩家每走一步就会把当前坐标传入
	~Game(); 
private: // methods
	void menu();
	void initPVP();
	void initPVC();
	void initCVC();
	bool endGame(); // 判定游戏是否结束
	void RUN(); // 游戏一回合的周期
	void updateGame(Player* p);
	Player* humanPlayer(string color, array<int,2> position);

private: // Attributes
	int playerID = 0;
	int size;
	int turn = 1; // 每个玩家每次移动一次就++
	int round = 0; // 两位玩家分别移动完毕后++

	vector<array<int,2>> tails; // Shape(-1, 2)
	vector<array<int, 2>> p1_Tail; // Shape(numOfCells / 2 + 1, 2)
	vector<array<int, 2>> p2_Tail; // Shape(numOfCells / 2 + 1, 2)
	Board* b1;
	Player* p1;
	Player* p2;

};

