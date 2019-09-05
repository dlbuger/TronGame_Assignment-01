#include "Game.h"
#include "Human.h"
#define log(x) cout<<x 

using namespace std;

Game::Game()
{
	log("Enter the Board's size length - (20 < input < 3): ");
	cin >> size;
	b1 = new Board(size);
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
	cout << "Choice --------> ";
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
	p1 = humanPlayer("RED", new int[2]{1, 1});
	p2 = humanPlayer("BLUE", new int[2] {size - 2, size - 2});
}
void Game::initPVC()
{

}
void Game::initCVC()
{

}
Player* Game::humanPlayer(string color, int position[2])
{
	string name;
	log("Please Enter Your Name --> ");
	cin >> name;
	return new Human(++playerID, name, color, position);
}

