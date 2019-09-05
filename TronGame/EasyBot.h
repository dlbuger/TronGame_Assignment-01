#pragma once
#include "Bot.h"
class EasyBot: public Bot
{
public:
	EasyBot(int id, string name, string color, int position[2], Game* g1) :Bot(id, name, color, position, g1){};
	char generateChoice();

};

