#pragma once
#include "Bot.h"

class EasyBot : virtual public Bot
{
public:
	EasyBot(int id, string name, string color, array<int,2> position, int mapSize, vector<array<int, 2>>* tails);

	char generateChoice();
};

