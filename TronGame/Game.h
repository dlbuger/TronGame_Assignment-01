#pragma once
#include "Player.h"
#include "Board.h"

class Game
{
public:
	Game();
private: // methods
	void menu();
	void initPVP();
	void initPVC();
	void initCVC();
	Player* humanPlayer(string color, int position[2]);

private: // Attributes
	int playerID = 0;
	int size;
	Board* b1;
	Player* p1;
	Player* p2;
};

