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
    b1 = new Board(size);
    p1 = new Player(1,"Jason",'R',1,1);
    p2 = new Player(2,"ReCo",'B',b1->getSize()-2,b1->getSize()-2);
}

void Game::run()
{
    b1->initPlayer(p1,p2);   
    b1->display();
}

void Game::menu()
{
    char choice;
    cin>>choice;
    /* switch(choice) */
    /* { */
    /*     case '' */
    /* } */
}

Game::~Game()
{
    cout<<"End of :Game"<<endl;
    // Report
    
    delete b1;
    delete p1;
    delete p2;
}


