#pragma once
#include "Player.h"

class Bot : public Player
{


protected: // methods
	char popChoice(); // ��������ƶ�����
	bool isSuicide(char direction); // �ж�������ɵ��ƶ������Ƿ�ᵼ������
	int counter = 0;
	virtual char generateChoice() = 0; // ����һ����Ч���ƶ�����
	int mapSize;
	int** tails; // �Լ��Ͷ����ƶ���������
	

private:
	int* preMove(char direction);
	

};

