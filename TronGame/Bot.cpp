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
	// ���ж��Ƿ񳬳���ͼ
	if (preMove(direction)[0] == -1)
		return true;
	else if (preMove(direction)[0] == mapSize)
		return true;
	if (preMove(direction)[1] == -1)
		return true;
	else if (preMove(direction)[1] == mapSize)
		return true;
	// ���ж��Ƿ�ײ�ϵ��˻��Լ��Ĺ켣
	for (array<int,2> tail: *tails)
		if (preMove(direction) == tail)
			return true;
	// Ĭ�Ϸ���false
	return false;
}
array<int,2> Bot::preMove(char direction)
{
	array<int,2> positionCopy = position;
	switch (direction)
	{
	case 'U': positionCopy[0] -= 1; break;
	case 'D': positionCopy[0] += 1; break;
	case 'L': positionCopy[1] -= 1; break;
	case 'R': positionCopy[1] += 1; break;
	}
	return positionCopy;
}
