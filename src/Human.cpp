#include <iostream>
#include "Human.h"
using namespace std;



char Player::generateChoice()
{
    cout<<"\tPlease Enter your choice - U D L R: ";
    string choice;
    cin>>choice;
    return toupper(choice[0]);
}

