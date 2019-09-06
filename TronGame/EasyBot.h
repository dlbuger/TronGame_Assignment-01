#pragma once
#include "Bot.h"

class EasyBot : virtual public Bot
{
public:
	EasyBot(int id, string name, string color, int position[2], int mapSize, int** tails);

	char generateChoice();
};

