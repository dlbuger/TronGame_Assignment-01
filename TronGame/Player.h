#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(int id, string name, string color, int position[2]);
	void move();
	int* getPosition(); // ������ҵ����� [x, y]
	string getColor(); // ������ҵ���ɫ

protected:
	virtual char generateChoice() = 0;
	int* position; // ���Ŀǰλ�õ�����ָ��

	
private: // Attributes
	int id;
	string name;
	string color;
	
	int** tail; // ����߹���λ��

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

