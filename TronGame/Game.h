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
	Player* humanPlayer(string color, int position[2]);

private: // Attributes
	int playerID = 0;
	int size;
	int round = 0; // ÿ����һ���غ� ++
	int** tail;
	Board* b1;
	Player* p1;
	Player* p2;

};

