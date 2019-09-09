#include "Game.h"


#define log(x) cout<<x 

using namespace std;
int numOfCells;

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
	cout << "3. Easy Bot vs. Easy Bot" << endl;


	char choice;
	log("Choice --------> ");
	cin >> choice;

	switch (choice)
	{
	case '1': initPVP(); break;
	case '2': initPVC(); break;
	case '3': initCVC(); break;
	default: cout << "Please Enter A valid choice!" << endl; menu(); break;
	}
	RUN();
}
void Game::initPVP()
{
	p1 = humanPlayer("RED", {1, 1});
	p2 = humanPlayer("BLUE", {size - 2, size - 2});
}
void Game::initPVC()
{
	p1 = humanPlayer("RED", {1, 1});
	p2 = new EasyBot(++playerID, "Easy Bot - TACO", "BLUE", { size - 2, size - 2 }, size, &tails);

}
void Game::initCVC()
{
	p1 = new EasyBot(++playerID, "Easy Bot - TACO", "RED", {1, 1}, size, &tails);
	p2 = new EasyBot(++playerID, "Easy Bot - Jason", "BLUE", {size - 2, size - 2}, size, &tails);

}
Player* Game::humanPlayer(string color, array<int,2> position)
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
	for (int i = 0; i < round; i++)
	{
		if (p1->getPosition() == p1_Tail[i])
		{
			cout << p1->getColor() << " Crashed self trace! LOL" << endl;
			return true;
		}
		if (p1->getPosition() == p2_Tail[i])
		{
			cout << p1->getColor() << " Crashed " << p2->getColor() << "'s Trace!" << endl;
			// cout << p1->getColor() << " Position --> [" << p1->getPosition()[0] << " " << p1->getPosition()[1]
			//	<< endl;
			return true;
		}

		if (p2->getPosition() == p2_Tail[i])
		{
			cout << p2->getColor() << " Crashed self trace LOL" << endl;
			return true;
		}
		if (p2->getPosition() == p1_Tail[i])
		{
			cout << p2->getColor() << " Crashed " << p1->getColor() << "'s Trace!" << endl;
			// cout << p2->getColor() << " Position --> [" << p2->getPosition()[0] << " " << p2->getPosition()[1]
			//	<< endl;
			return true;
		}
	}
	return false;
}
void Game::RUN()
{

	cout << "Create Player 1 - " << p1->getColor() << " " << p1->getName() << endl;
	cout << "Create Player 2 - " << p2->getColor() << " " << p2->getName() << endl;
	tails.push_back(p1->getPosition());
	tails.push_back(p2->getPosition());
	cout << "Initialize Players complete!" << endl;
	b1->update(p1);
	b1->update(p2);
	b1->display();

	 while (!endGame()) 
	 {
		p1_Tail.push_back(p1->getPosition());
		updateGame(p1);
		
		p2_Tail.push_back(p2->getPosition());
		updateGame(p2);
		round++;
		cout << endl << endl;
		b1->display();
	}
	
	cout << "\t####GAME OVER####" << endl;
}
void Game::updateGame(Player* p)
{
	
	b1->update(p, '0');
	cout << p->getColor()<< " Turn: " << endl;
	p->move();
	tails.push_back(p->getPosition());
	cout << "[" << p->getPosition()[0] << " " << p->getPosition()[0] << "] " << endl;
	b1->update(p);
}

int Game::getBoardSize()
{
	return size;
}
vector<array<int, 2>> Game::getTail()
{
	return tails;
}

Game::~Game()
{
	delete b1, p1, p2;
}

