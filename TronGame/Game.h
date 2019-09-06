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
	int** getTail(); // ÿ�����ÿ��һ���ͻ�ѵ�ǰ���괫��
private: // methods
	void menu();
	void initPVP();
	void initPVC();
	void initCVC();
	bool endGame(); // �ж���Ϸ�Ƿ����
	void RUN(); // ��Ϸһ�غϵ�����
	void updateGame(Player* p);
	Player* humanPlayer(string color, int position[2]);

private: // Attributes
	int playerID = 0;
	int size;
	int turn = 1; // ÿ����һ���غ� ++
	int round = 0;
	int** tail;
	int** p1_Tail;
	int** p2_Tail;
	Board* b1;
	Player* p1;
	Player* p2;

};

