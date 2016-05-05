/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on 5/3/16
 */


//Global constant
const int SIZE=10;

//Libraries
#include <string>
using namespace std;

//header file
#ifndef PROJ_H
#define PROJ_H

//Structure 
struct players{
    string name; //name of player
    char board[SIZE][SIZE]; //board of player
};

//end
#endif /* PROJ_H */

