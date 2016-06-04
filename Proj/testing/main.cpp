/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jose
 *
 * Created on May 27, 2016, 1:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include "board.h"
#include "plyrInfo.h"
using namespace std;

/*
 * 
 */

//functions
void inputS(board&, int);
char checkC(board, int, int, int, int, int);
void rules();
void playG(board&, board&, board&, board&);

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
    
    delete [] players;
    
    return 0;
}