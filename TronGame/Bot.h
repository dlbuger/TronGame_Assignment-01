#pragma once
#include "Player.h"
#include "Game.h"

class Bot : public Player
{
public:
	Bot(int id, string name, string color, int position[2], Game& g1) 
		:Player(id, name, color, position) 
	{
		this->currentGame = g1;
		this->mapSize = g1.getBoardSize();
	};
protected: // methods
	char popChoice();
	bool isSuicide(char direction);
	int counter = 0;
	Game currentGame; // ��¼���Լ��͵з��߹�������

private:
	int mapSize;
	int* preMove(char direction);
	

};

