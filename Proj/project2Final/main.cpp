/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on June 4th 2016
 */

//System Libraries 
#include <iostream>
#include <fstream>
using namespace std;

//user libraries
#include "board.h"
#include "bets.h"

//global constants

//Function Prototypes
void inputS(board&, int);
char checkC(board, int, int, int, int, int);
void rules();
void enterG(board&, board&, info[], int i);
void names(info[]);
//Execution begins here
int main(int argc, char** argv) {
    float p1=0; //player 1 bet
    float p2=0; //player 2 bet
    bool win=false; //win for player 1
    bool win2=false;    //win for player 2
    bool winner=true;   //winner=true
    info *players = new info[NUMPLAY];  //dynamic array of structs
    fstream file;   //file 
    fstream rFile;  //rFile
    
    //display of polymorphism knowledge.
    poly forPoly;
    warShip *test = &forPoly;
    test->info();
    
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
    
    //copy board of one player to their respective copy boards
    copy1=player1;
    copy2=player2;
    
    //enter the info of the players
    for(int i=0; i<NUMPLAY; i++) //loop ten twice for each player
    {
        cout<<"Enter name of player "<<i+1<<" ";
        getline(cin, players[i].names);
    }
    
    //call function names
    names(players);
    
    //enter the bets for each player
    cout<<"Enter bet for "<<players[0].names<<endl;
    cin>>p1;
    cout<<"Enter bet for "<<players[1].names<<endl;
    cin>>p2;
    //create templated class of float
    bets <float> pot(p1, p2);
    //display the pot total using a templated class
    cout<<"The pot is: "<<pot.getBets()<<endl;
    
    //loop twice for each player
    for(int i=0; i<NUMSHIP; i++)
    {
        player1.display();  //displays the board
        inputS(player1, i); //gets the inputs of the player
        player1.display();  //displays the board
    }
    //creates space
    cout<<endl<<endl<<endl;
    
    //loop twice for each player
    for(int i=0; i<NUMSHIP; i++)
    {
        player2.display();  //displays the board
        inputS(player2, i); //gets the inputs of the player
        player2.display();  //displays the board
    }
    //creates space
    cout<<endl<<endl<<endl; 
    //do 
    do
    {
        //enter the gueeses for player 1
        enterG(player1, copy1, players, 0); //enter the  guesses
        player2.check(player1.getYGss(), player1.getXGss(), copy1); //check 
        copy1.display(); //show player 1 guess
        cin.ignore(); //ignore input
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore(); //need to press enter 
        win=player1.chekWin(); //check for the win
        //if win==true
        if(win==true)
        {   //set winner to false
            winner=false;
        }
        //enter guesses for player 2
        enterG(player2, copy2, players, 1); //enter guesses for player 2
        player1.check(player2.getYGss(), player2.getXGss(), copy2); //plr check
        copy2.display();    //show player 2 guess board
        cin.ignore();   //ignore input
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore(); //press enter to continue
        win2=player2.chekWin(); //check for the win 
        //if win2==true
        if(win2==true)
        { //set winner = false
            winner=false;
        }    
    }while(winner); //while winner
    //if player 1 won
    if(win==true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[0].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player1.getHits()<<endl;
        cout<<"Total Misses: "<<player1.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player1.getGss()<<endl;
        cout<<"The pot awarded: "<<pot.getBets()<<endl;
    }
    //if player 2 won
    if(win2==true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[1].names<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total Hits:   "<<player2.getHits()<<endl;
        cout<<"Total Misses: "<<player2.getMiss()<<endl;
        cout<<"Total number of guesses: "<<player2.getGss()<<endl;
        cout<<"The pot awarded: "<<pot.getBets()<<endl;
    }
    
    //loop to fill in structured data to send to file;
    for(int i=0; i<SIZE; i++)
    { //loop 10 times
        for(int j=0; j<SIZE; j++)
        {   //loop 10 times
            players[0].arr[i][j]=player1.getGrd(i, j);//get the coordinates(i,j)
        }
    }
    
    //loop to fill in structured data to send to file;
    for(int i=0; i<SIZE; i++)
    {   //loop 10 times
        for(int j=0; j<SIZE; j++)
        {   //loop 10 times
            players[1].arr[i][j]=player2.getGrd(i, j);//get the coordinates(i,j)
        }
    }

    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&players), sizeof(players));
    file.close();  
    
    //open the "Stats.dat" binary file and read it into a structure
    rFile.open("Stats.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&players), sizeof(players));
    //display contents of structure for loop p<NUMPLAY
    cout<<players[0].names<<"'s Board"<<endl; //output readIn[p].name
    //loop to display
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    //loop for 10 times
    for(int i=0; i<SIZE; i++)
    {   //output static cast of p
        cout<<static_cast<char>('a'+i);
        //loop 10 time for the columns
        for(int j=0; j<SIZE; j++)
        {   //output array[i][j]
            cout<<" | "<<players[0].arr[i][j];
        }  
        cout<<endl;
    } 
    
    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats2.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&player2), sizeof(player2));
    file.close();  
    
    //open the "Stats2.dat" binary file and read it into a structure
    rFile.open("Stats2.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&players), sizeof(players));
    //display contents of structure for loop p<NUMPLAY
    cout<<players[1].names<<"'s Board"<<endl; //output readIn[p].name
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    //loop for 10 times
    for(int i=0; i<SIZE; i++)
    {   //output static cast of p
        cout<<static_cast<char>('a'+i);
        //loop 10 time for the columns
        for(int j=0; j<SIZE; j++)
        {   //output array[i][j]
            cout<<" | "<<players[1].arr[i][j];
        }  
        cout<<endl;
    } 

    //delete dynamically created array
    delete [] players;
    
    return 0;
}