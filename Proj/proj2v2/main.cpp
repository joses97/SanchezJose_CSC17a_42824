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
void enterG(board&, board&, info[], int i);

//Execution begins here
int main(int argc, char** argv) {
    bool win=false;
    bool win2=false;
    bool winner=true;
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
    
    for(int i=0; i<NUMSHIP; i++)
    {
        player1.display();
        inputS(player1, i);
        player1.display();
    }
    cout<<endl<<endl<<endl;
    for(int i=0; i<NUMSHIP; i++)
    {
        player2.display();
        inputS(player2, i);
        player2.display();
    }
    cout<<endl<<endl<<endl;
    while(winner)
    {
        //enter the gueeses for player 1
        enterG(player1, copy1, players, 0);
        player2.check(player1.getYGss(), player1.getXGss(), copy1);
        copy1.display(); //show player 1 guess
        cin.ignore();
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore();
        win=player1.chekWin(); //check for the win
        if(win==true)
        {
            winner=false;
        }
        //enter guesses for player 2
        enterG(player2, copy2, players, 1);
        player1.check(player2.getYGss(), player2.getXGss(), copy2);
        copy2.display();
        cin.ignore();
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore();
        win2=player2.chekWin(); //check for the win 
        if(win2==true)
        {
            winner=false;
        }    
    }
    
    if(win==true)
    {
        cout<<"Congrats to the winner "<<info[0].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player1.getHits()<<endl;
        cout<<"Total Misses: "<<player1.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player1.getGss()<<endl;
    }
    
    if(win2==true)
    {
        cout<<"Congrats to the winner "<<info[1].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player2.getHits()<<endl;
        cout<<"Total Misses: "<<player2.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player2.getGss()<<endl;
    }
    
    //delete dynamically created array
    delete [] players;
    
    return 0;
}