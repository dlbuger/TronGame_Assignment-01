#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(int id, string name, string color, int position[2]);
	void move();
	int* getPosition();

protected:
	virtual char generateChoice() = 0;
	

	
private: // Attributes
	int id;
	string name;
	string color;
	int* position; // ���Ŀǰλ�õ�����ָ��
	int** tail; // ����߹���λ��

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

