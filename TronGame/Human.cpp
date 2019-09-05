#include "Human.h"

char Human::generateChoice()
{
	cout << "\tPlease Enter your choice - U D L R: ";
	string choice;
	cin >> choice;
	return toupper(choice[0]);
}