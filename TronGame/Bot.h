#pragma once
#include "Player.h"
#include <vector>

class Bot : public Player
{


protected: // methods
	char popChoice(); // ��������ƶ�����
	bool isSuicide(char direction); // �ж�������ɵ��ƶ������Ƿ�ᵼ������
	int counter = 0;
	virtual char generateChoice() = 0; // ����һ����Ч���ƶ�����
	int mapSize;
	vector<array<int, 2>>* tails; // �Լ��Ͷ����ƶ���������
	

private:
	array<int,2> preMove(char direction);
	

};

