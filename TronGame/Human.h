#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human(int id, string name, string color, int position[]);
private:
	char generateChoice();
};

