#pragma once
#include "Player.h"

class Board
{
public:
	Board(int size);
	void display();;
	void update(Player* p, char mark);
	void update(Player* p);
	int getSize();
	~Board() {};

private:
	int size;
	void initVector();
};