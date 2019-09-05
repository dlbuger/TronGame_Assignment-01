#include "Game.h"


#define log(x) cout<<x 

using namespace std;

Game::Game()
{
	log("Enter the Board's size length - (20 < input < 3): ");
	cin >> size;
	b1 = new Board(size);
	int tailSize = size * size;
	tail = new int*[tailSize];
	for (int i = 0; i < size*size; i++)
		tail[i] = new int[2];
	menu();
}
void Game::menu()
{
	//Menu details
	cout << "1. Human Player With Another Human Player - PVP" << endl;
	cout << "2. Human Player with Bot - difficult: Easy" << endl;
	cout << "3. Human Player with Bot - diffculty: Hard" << endl;
	cout << "4. Bot with Bot - Easy vs. Hard" << endl;

	char choice;
	log("Choice --------> ");
	cin >> choice;

	switch (choice)
	{
	case '1': initPVP(); break;
	case '2': initPVC(); break;
	case '4': initCVC(); break;
	}
	b1->display();

}
void Game::initPVP()
{
	p1 = humanPlayer("RED", new int[]{1, 1});
	p2 = humanPlayer("BLUE", new int[] {size - 2, size - 2});
}
void Game::initPVC()
{
	p1 = humanPlayer("RED", new int[] {1, 1});
	p2 = new EasyBot(++playerID, "Easy Bot - TACO", "BLUE", new int[]{ size - 2, size - 2 }, this);

}
void Game::initCVC()
{
	p1 = new EasyBot(++playerID, "Easy Bot - TACO", "RED", new int[] {1, 1}, this);
	p2 = new EasyBot(++playerID, "Easy Bot - Jason", "BLUE", new int[] {size - 2, size - 2}, this);

}
Player* Game::humanPlayer(string color, int position[2])
{
	string name;
	log("Please Enter Your Name --> ");
	cin >> name;
	return new Human(++playerID, name, color, position);
}
bool Game::endGame()
{
	if (p1->getPosition() == p2->getPosition())
	{
		cout << "Draw!" << endl;
		return true;
	}

	for (int i = 0; i < round * 2; i++)
	{
		if (p1->getPosition() == tail[i])
		{
			cout << p1->getColor() << " Crashed " << p2->getColor() << "'s Trace!" << endl;
			return true;
		}
		if (p2->getPosition() == tail[i])
		{
			cout << p2->getColor() << " Crashed " << p1->getColor() << "'s Trace!" << endl;
			return true;
		}
	}
	return false;
}
void Game::RUN()
{

}

int Game::getBoardSize()
{
	return size;
}
int** Game::getTail()
{
	return tail;
}

