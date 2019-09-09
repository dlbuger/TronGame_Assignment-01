#pragma once
#include <iostream>
#include <array>
using namespace std;

class Player
{
public:
	/*Player(int id, string name, string color, int position[2]);*/
	void move();
	array<int,2> getPosition(); // ������ҵ����� [x, y]
	string getName(); //������ҵ�����
	string getColor(); // ������ҵ���ɫ
	virtual char generateChoice() = 0; // ����Move
	~Player(); // ��������

protected:
	array<int,2> position; // ���Ŀǰλ�õ�����ָ��
	int id;
	string name;
	string color;

private: // Methods
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

