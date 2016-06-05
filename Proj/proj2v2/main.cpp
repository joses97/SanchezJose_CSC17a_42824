/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on June 4th 2016
 */

//System Libraries 
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//user libraries
#include "board.h"
#include "plyrInfo.h"

//global constants

//Function Prototypes
void inputS(board&, int);
char checkC(board, int, int, int, int, int);
void rules();
void playG(board&, board&, board&, board&, info[]);

//Execution begins here
int main(int argc, char** argv) {
    int count;
    info *players = new info[NUMPLAY];
    
    //make 4 boards
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    //display the rules of the game
    rules();
    
    //set the names of the ships to the ships created
    player1.setSNms();
    player1.setSize(); //set the size of the ships to the ships created
    
    //set the names of the ships to the ships created
    player2.setSNms();
    player2.setSize(); //set the size of the ships to the ships created
    
    copy1=player1;
    copy2=player2;
    
    //enter the info of the players
    for(int i=0; i<NUMPLAY; i++){
        cout<<"Enter name of player "<<i+1<<" ";
        getline(cin, players[i].names);
    }
    
    for(int i=0; i<NUMSHIP; i++){
        player1.display();
        inputS(player1, i);
        player1.display();
    }
    for(int i=0; i<NUMSHIP; i++){
        player2.display();
        inputS(player2, i);
        player2.display();
    }
    
    playG(player1, player2, copy1, copy2, players);
    
    //delete dynamically created array
    delete [] players;
    
    return 0;
}