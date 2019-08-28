#include "Game.h"
using namespace std;

Game::Game()
{
    setup();
    menu();
}

void Game::setup()
{
    int size = 0;
    while (size < 4)
    {
        cout<<"Enter the Board's size length - (input > 3): ";
        cin>>size;
    }
    //initialize Board and Players
    b1 = new Board(size);
    cout<<"Board Size: "<<b1->getSize()<<endl;
}

void Game::menu()
{
    //Menu details
    cout<<"1. Human Player With Another Human Player - PVP"<<endl;
    cout<<"2. Human Player with Bot - difficult: Easy"<<endl;
    cout<<"3. Human Player with Bot - diffculty: Hard"<<endl;
    cout<<"4. Bot with Bot - "<<endl;

    cout<<"Choice --------> ";
    char choice;
    cin>>choice;

    switch(choice)
    {
    case '1': initPVP();break;
    case '2': initPVC();break;
    }
    RUN();
}
void Game::RUN()
{   
    
    cout<<"Create Player 1 - "<<p1->getColor()<<" "<<p1->getName()<<endl;
    cout<<"Create Player 2 - "<<p2->getColor()<<" "<<p2->getName()<<endl;
    cout<<"Initialize Players complete!"<<endl;
    b1->initPlayer(p1,p2); 
    b1->display();

    update();
    while(!p1->crash(*p2,trace) && !p2->crash(*p1,trace)){
        trace.push_back(p1->getPosition());
        trace.push_back(p2->getPosition());
        update();
    }
}

void Game::update()
{
    b1->update(p1,'0');
    b1->update(p2,'0');
    // Get direction
    cout<<"Red Turn:"<<endl;
    p1->move(p1->generateChoice());

    cout<<"Blue Turn:"<<endl;
    p2->move(p2->generateChoice());

    b1->update(p1,'R'); 
    b1->update(p2,'B');

    cout<<endl<<endl;
    b1->display();
}

void Game::initPVC()
{
    p1 = initHuman("RED",1,1);
    p2 = initBot("Computer1","BLUE",b1->getSize()-2,b1->getSize()-2,1);

}

void Game::initPVP()
{
    p1 = initHuman("RED", 1, 1);
    p2 = initHuman("BLUE",b1->getSize()-2, b1->getSize()-2);
}

Player* Game::initHuman(string color, int row, int col)
{
    string name;
    cout<<"Please enter your Name"<<endl;
    cin>>name;
    return new Human(++id, name,color,row, col);
}

Player* Game::initBot(string name,string color, int row, int col, int difficulty)
{
    return new Bot(++id, name, color,row, col, difficulty);
}
Game::~Game()
{
    delete b1;
    delete p1;
    delete p2;
}


