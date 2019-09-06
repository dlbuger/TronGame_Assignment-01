#include "Game.h"


#define log(x) cout<<x 

using namespace std;

Game::Game()
{
	log("Enter the Board's size length - (20 < input < 3): ");
	cin >> size;
	b1 = new Board(size);
	tail = new int*[size*size]; // ø…”≈ªØ
	p1_Tail = new int* [size];
	p2_Tail = new int* [size];

	
	for (int i = 0; i < size*size; i++)
		tail[i] = new int[2];
	for (int i = 0; i < size * size / 2 + 1; i++)
	{
		p1_Tail[i] = new int[2];
		p2_Tail[i] = new int[2];
	}
		
		
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
	default: cout << "Please Enter A valid choice!" << endl; menu(); break;
	}
	RUN();
}
void Game::initPVP()
{
	p1 = humanPlayer("RED", new int[2]{1, 1});
	p2 = humanPlayer("BLUE", new int[2] {size - 2, size - 2});
}
void Game::initPVC()
{
	p1 = humanPlayer("RED", new int[2] {1, 1});
	p2 = new EasyBot(++playerID, "Easy Bot - TACO", "BLUE", new int[2]{ size - 2, size - 2 }, size, tail);

}
void Game::initCVC()
{
	p1 = new EasyBot(++playerID, "Easy Bot - TACO", "RED", new int[2] {1, 1}, size, tail);
	p2 = new EasyBot(++playerID, "Easy Bot - Jason", "BLUE", new int[2] {size - 2, size - 2}, size, tail);

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

	for (int i = 0; i < turn * 2; i++)
	{
		if (p1->getPosition() == p2_Tail[i])
		{
			cout << p1->getColor() << " Crashed " << p2->getColor() << "'s Trace!" << endl;
			cout << p1->getColor() << " Position --> [" << p1->getPosition()[0] << " " << p1->getPosition()[1]
				<< endl;
			return true;
		}
		if (p2->getPosition() == p1_Tail[i])
		{
			cout << p2->getColor() << " Crashed " << p1->getColor() << "'s Trace!" << endl;
			cout << p2->getColor() << " Position --> [" << p2->getPosition()[0] << " " << p2->getPosition()[1]
				<< endl;
			return true;
		}
	}
	return false;
}
void Game::RUN()
{

	cout << "Create Player 1 - " << p1->getColor() << " " << p1->getName() << endl;
	cout << "Create Player 2 - " << p2->getColor() << " " << p2->getName() << endl;
	cout << "Initialize Players complete!" << endl;
	b1->update(p1);
	b1->update(p2);
	b1->display();
	
	do{
		updateGame(p1);
		updateGame(p2);
		cout << endl << endl;
		b1->display();
	} while (!endGame());
	
	cout << "\t####GAME OVER####" << endl;
}
void Game::updateGame(Player* p)
{
	p1_Tail[round] = p1->getPosition();
	p2_Tail[round] = p2->getPosition();

	tail[turn] = p->getPosition();
	turn++;
	b1->update(p, '0');
	cout << p->getColor()<< " Turn: " << endl;
	p->move();
	b1->update(p);
}

int Game::getBoardSize()
{
	return size;
}
int** Game::getTail()
{
	return tail;
}

