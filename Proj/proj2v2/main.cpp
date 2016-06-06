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

//global constants

//Function Prototypes
void inputS(board&, int);
char checkC(board, int, int, int, int, int);
void rules();
void enterG(board&, board&, info[], int i);

//Execution begins here
int main(int argc, char** argv) {
    float p1=0;
    float p2=0;
    bool win=false;
    bool win2=false;
    bool winner=true;
    info *players = new info[NUMPLAY];
    fstream file;
    fstream rFile;
    
    //make 4 boards
    board player1;
    board player2;
    board copy1;
    board copy2;
    board p1Fstrm;
    board p2Fstrm;
    
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
    for(int i=0; i<NUMPLAY; i++)
    {
        cout<<"Enter name of player "<<i+1<<" ";
        getline(cin, players[i].names);
    }
    
    cout<<"Enter bet for "<<players[0].names<<endl;
    cin>>p1;
    cout<<"Enter bet for "<<players[1].names<<endl;
    cin>>p2;
    bets <float> pot(p1, p2);
    
    cout<<"The pot is: "<<pot.getBets()<<endl;
    
    
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
        cout<<"Congrats to the winner "<<players[0].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player1.getHits()<<endl;
        cout<<"Total Misses: "<<player1.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player1.getGss()<<endl;
        cout<<"The pot awarded: "<<pot.getBets()<<endl;
    }
    
    if(win2==true)
    {
        cout<<"Congrats to the winner "<<players[1].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player2.getHits()<<endl;
        cout<<"Total Misses: "<<player2.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player2.getGss()<<endl;
        cout<<"The pot awarded: "<<pot.getBets()<<endl;
    }
    
    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&player1), sizeof(player1));
    file.close();  
    
    //open the "Stats.dat" binary file and read it into a structure
    rFile.open("Stats.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&p1Fstrm), sizeof(p1Fstrm));
    //display contents of structure for loop p<NUMPLAY
    p1Fstrm.display();
    cout<<players[0].names<<"'s Board"<<endl; //output readIn[p].name
    
    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats2.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&player2), sizeof(player2));
    file.close();  
    
    //open the "Stats2.dat" binary file and read it into a structure
    rFile.open("Stats2.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&p2Fstrm), sizeof(p2Fstrm));
    //display contents of structure for loop p<NUMPLAY
    p2Fstrm.display();
    cout<<players[1].names<<"'s Board"<<endl; //output readIn[p].name
    
    
    //delete dynamically created array
    delete [] players;
    
    return 0;
}