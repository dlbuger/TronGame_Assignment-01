#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"

using namespace std;

Game::Game()
{
    setup();
    cout<<"Board Size: "<<b1->getSize()<<endl;
    run();
}

void Game::setup()
{
    int size;
    cout<<"Enter the Board's size length: ";
    cin>>size;
    //initialize Board
    b1 = new Board(size);
    p1 = new Player(1,"Jason","RED",1,1);
    p2 = new Player(2,"ReCo","BLUE",b1->getSize()-2,b1->getSize()-2);
    b1->initPlayer(p1,p2);   
    trace.push_back(p1->getPosition());
    trace.push_back(p2->getPosition());
    b1->display();
}

void Game::run()
{
    PVP();
    while(!p1->crash(*p2,trace) && !p2->crash(*p1,trace)  )
    {
        PVP();
    }
    b1->display();
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
    // Get direction
    cout<<"Red Turn:"<<endl;
    cout<<"\tPlease Enter your choice - U D L R!:";
    string p1Move;
    cin>>p1Move;

    cout<<"Blue Turn:"<<endl;
    cout<<"\tPlease Enter your choice - U D L R!:";
    string p2Move;
    cin>>p2Move;

    b1->update(p1,'0');
    b1->update(p2,'0');

    p1->move(toupper(p1Move[0]));
    p2->move(toupper(p2Move[0]));
    b1->update(p1,'R');
    b1->update(p2,'B');
    
    b1->display();
}

Game::~Game()
{
    /* cout<<"Calling Game Class Destructor!"<<endl; */
    delete b1;
    delete p1;
    delete p2;
}


