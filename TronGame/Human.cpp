#include "Human.h"

Human::Human(int id, string name, string color, int position[])
{
	Player::id = id;
	Player::name = name;
	Player::color = color;
	Player::position = position;
}
char Human::generateChoice()
{
	cout << "\tPlease Enter your choice - U D L R: ";
	string choice;
	cin >> choice;
	return toupper(choice[0]);
}