#include "Board.h"

using namespace std;

string** track;
string* borderAs;

Board::Board(int size)
{
	this->size = size;
	initVector();
}

void Board::initVector()
{
	string const borderA = " ---";
	string const borderB = "|   ";

	borderAs = new string[size];
	string* borderBs = new string[size];
	
	for (int i = 0; i < size; i++)
	{
		*(borderAs + i) = borderA;
		*(borderBs + i) = borderB;
	}

	track = new string* [size];
	for (int i = 0; i < size; i++)
		track[i] = borderBs;

}
void Board::display()
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
			cout << borderAs[i];
		cout << endl;
		for (int j = 0; j < size; j++)
			cout << *(track[0]+j);
		cout << "|" << endl;
	}
	for (int i = 0; i < size; i++)
		cout << borderAs[i];
}
void Board::update(Player* p, char mark)
{

}
void Board::update(Player* p)
{

}