#include "Game.h"
using namespace std;

Game::Game()
{
    setup();
    cout<<"Board Size: "<<b1->getSize()<<endl;
    run();
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
    p1 = new Human(1,"Jason","RED",1,1);
    cout<<"Create Player 1 - "<<p1->getColor()<<endl;
    p2 = new Human(2,"ReCo","BLUE",b1->getSize()-2,b1->getSize()-2);
    cout<<"Create Player 2 - "<<p2->getColor()<<endl;
    b1->initPlayer(p1,p2); 
    cout<<"Initialize Players complete!"<<endl;
    b1->display();
}


void Game::run()
{
    PVP();
    while(!p1->crash(*p2,trace) && !p2->crash(*p1,trace)){
        trace.push_back(p1->getPosition());
        trace.push_back(p2->getPosition());
        PVP();

    }
}

void Game::menu()
{
    char choice;
    cin>>choice;
    switch(choice)
    {
    case '1': PVP();
    }
}
void Game::PVP()
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

Game::~Game()
{
    delete b1;
    delete p1;
    delete p2;
}


