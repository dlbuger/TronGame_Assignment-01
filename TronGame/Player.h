#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	/*Player(int id, string name, string color, int position[2]);*/
	void move();
	int* getPosition(); // ������ҵ����� [x, y]
	string getName(); //������ҵ�����
	string getColor(); // ������ҵ���ɫ
	virtual char generateChoice() = 0; // ����Move
	~Player() {}; // ��������

protected:
	int* position; // ���Ŀǰλ�õ�����ָ��
	int id;
	string name;
	string color;

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

