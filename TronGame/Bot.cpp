#include "Bot.h"

char Bot::popChoice()
{	
	counter++;
	char choices[] = { 'U','D','L','R' };
	srand(counter);
	return choices[rand() % 4];
	
}
bool Bot::isSuicide(char direction)
{
	// 先判定是否超出地图
	if (preMove(direction)[0] == -1)
		return true;
	else if (preMove(direction)[0] == mapSize)
		return true;
	if (preMove(direction)[1] == -1)
		return true;
	else if (preMove(direction)[1] == mapSize)
		return true;
	// 再判定是否撞上敌人或自己的轨迹
	for (int i = 0; i < mapSize; i++)
		if (*(preMove(direction)) == (currentGame.getTail[i]))
			return true;
	// 默认返回false
	return false;
}
int* Bot::preMove(char direction)
{
	int* positionCopy = position;
	switch (direction)
	{
	case 'U': positionCopy[0] -= 1; break;
	case 'D': positionCopy[0] += 1; break;
	case 'L': positionCopy[1] -= 1; break;
	case 'R': positionCopy[1] += 1; break;
	}
	return positionCopy;
}
