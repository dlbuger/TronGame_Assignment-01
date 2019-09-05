#include "EasyBot.h"

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