#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human(int id, string name, string color, array<int,2> position);
private:
	char generateChoice();
};

