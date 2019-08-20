#include <iostream>
#include "Board.h"
#include <vector>
using namespace std;



vector<vector<string>> scene;


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
    

    // Add the borders into the vector;
    for (int i=0;i<size;i++){
        scene.push_back(borderAs);
        scene.push_back(borderBs);
    }   
    scene.push_back(borderAs);
}

void Board::display(){
    for (auto i:scene)
        for(string k:i)
            cout<< k;
}



Board::Board(int size){
    initVector(size);
}


Board::~Board(){
    cout << "finish!";
}
