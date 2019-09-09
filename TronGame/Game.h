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
	vector<array<int, 2>> getTail(); // ÿ�����ÿ��һ���ͻ�ѵ�ǰ���괫��
	~Game(); 
private: // methods
	void menu();
	void initPVP();
	void initPVC();
	void initCVC();
	bool endGame(); // �ж���Ϸ�Ƿ����
	void RUN(); // ��Ϸһ�غϵ�����
	void updateGame(Player* p);
	Player* humanPlayer(string color, array<int,2> position);

private: // Attributes
	int playerID = 0;
	int size;
	int turn = 1; // ÿ�����ÿ���ƶ�һ�ξ�++
	int round = 0; // ��λ��ҷֱ��ƶ���Ϻ�++

	vector<array<int,2>> tails; // Shape(-1, 2)
	vector<array<int, 2>> p1_Tail; // Shape(numOfCells / 2 + 1, 2)
	vector<array<int, 2>> p2_Tail; // Shape(numOfCells / 2 + 1, 2)
	Board* b1;
	Player* p1;
	Player* p2;

};

