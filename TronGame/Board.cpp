#include "Board.h"

using namespace std;



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
	
	for (int i = 0; i < size; i++)
		*(borderAs + i) = borderA;
	
	track = new string* [size];
	for (int k = 0; k < size; k++)
		track[k] = new string[size];

	for (int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			track[i][j] = borderB;

}
void Board::display()
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
			cout << borderAs[i];
		cout << endl;
		for (int j = 0; j < size; j++)
			cout << *(track[k]+j);
		cout << "|" << endl;
	}
	for (int i = 0; i < size; i++)
		cout << borderAs[i];
	cout << endl;
}
void Board::update(Player* p, char mark)
{
	int x = p->getPosition()[0];
	int y = p->getPosition()[1];
	track[x][y][2] = mark;
}
void Board::update(Player* p)
{
	int x = p->getPosition()[0];
	int y = p->getPosition()[1];
	if (isInside(x,y)) {
		track[x][y][2] = p->getColor()[0];
	}
	else{
		cout << "\t Game Over" << endl;
		cout << p->getColor() << " Entered Dead Zone." << endl;
		exit(0);
	}
}
bool Board::isInside(int x, int y)
{
	if (x == -1 || x == size || y == -1 || y == size)
		return false;
	else
		return true;
}
Board::~Board()
{
	for (int i = 0; i < size; i++)
		delete[] track;
	delete track, borderAs;

	
}