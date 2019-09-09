#include "EasyBot.h"
EasyBot::EasyBot(int id, string name, string color, array<int,2> position, int mapSize, vector<array<int, 2>>* tails)
{
	Player::id = id;
	Player::name = name;
	Player::color = color;
	Player::position = position;
	Bot::mapSize = mapSize;
	Bot::tails = tails;
}
char EasyBot::generateChoice()
{
	char botChoice = popChoice();
	while (isSuicide(botChoice))
	{
		botChoice = popChoice();
		counter++;
		if (counter == 1000)
		{
			cout << "Tried Time ---> " << counter << endl;
			return popChoice();
		}
	}
	cout << "Tried Time ---> " << counter << endl;
	return botChoice;
}