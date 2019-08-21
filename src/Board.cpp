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
    borderBs.insert(borderBs.end(), "|\n");

    for (int i=0;i<size;i++){
        frame.push_back(borderAs);
        track.push_back(borderBs);
    }   
    frame.push_back(borderAs);
}

void Board::initPlayer(Player *p1, Player *p2)
{
    update(p1, p1->getColor());
    update(p2, p2->getColor());
}

void Board::display(){
    for(int i=0;i<size;i++)
    {
        for(string j:frame[i])
            cout<<j;
        for(string k:track[i])
            cout<<k;
    }
    for(string j:frame[0])
        cout<<j;
    cout<<endl<<endl;
}

int Board::getSize()
{
    return size;
}


void Board::update(Player *p, char mark)
{
    track[p->getPosition()[0]][p->getPosition()[1]][2] = mark;
}

Board::~Board(){
    cout << "End of :Board"<<endl;
}
