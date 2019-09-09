#pragma once
#include "Player.h"

class Board
{
public:
	Board(int size);
	void display();;
	void update(Player* p, char mark);
	void update(Player* p);
	~Board();

private:
	int size;
	void initVector();
	string** track;
	string* borderAs;
	bool isInside(int x, int y);
};