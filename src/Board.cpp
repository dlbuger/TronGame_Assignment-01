#include <iostream>
#include "Board.h"
#include <vector>
#include <array>

using namespace std;

vector<vector<string>> track; // position
vector<vector<string>> frame;

Board::Board(int size){
    this->size = size;
    initVector(size);
}


void Board::initVector(int size){

    // Initialize two types of frame
    string const borderA = " ---";
    string const borderB = "|   ";
    vector<string> borderAs;
    vector<string> borderBs;
    for(int i=0;i<size;i++){
        borderAs.insert(borderAs.end(),borderA);
        borderBs.insert(borderBs.end(), borderB);
    }
    borderAs.insert(borderAs.end(), "\n");

    for (int i=0;i<size;i++){
        frame.push_back(borderAs);
        track.push_back(borderBs);
    }   
    frame.push_back(borderAs);
}


void Board::initPlayer(Player *p1, Player *p2)
{
    update(p1, p1->getColor()[0]);
    update(p2, p2->getColor()[0]);
}

void Board::display(){
    for(int i=0;i<size;i++)
    {
        for(string j:frame[i])
            cout<<j;
        for(string k:track[i])
            cout<<k;
        cout<<"|\n";
    }
    for(string j:frame[0])
        cout<<j;
    cout<<endl;
}

int Board::getSize()
{
    return size;
}

void Board::update(Player *p, char mark)
{
    int x = p->getPosition()[0];
    int y = p->getPosition()[1];
    try{
        track.at(x).at(y)[2]=mark;  //use at() to acess element in order to check list range;
    }catch(out_of_range){
        cout<<endl<<"\tGame Over!"<<endl;
        cout<<p->getColor()<<" Entered Dead Zone."<<endl;
        exit(0);
    }
}


void Board::update(Player *p)
{
    int x = p->getPosition()[0];
    int y = p->getPosition()[1];
    try{
        track.at(x).at(y)[2]=p->getColor()[0];  //use at() to acess element in order to check list range;
    }catch(out_of_range){
        cout<<endl<<"\tGame Over!"<<endl;
        cout<<p->getColor()<<" Entered Dead Zone."<<endl;
        exit(0);
    }
}