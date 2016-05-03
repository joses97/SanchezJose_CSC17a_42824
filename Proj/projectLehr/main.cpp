/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: 
 * Created on 
 */

//System Libraries
#include <iostream> //i/o
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
const int MAXH=18;
const int MAXM=84;
const int SIZE=10;
const int NUMPLAY=2;
//Structures
struct players{
    string name;
    char board[SIZE][SIZE];
    int hit[MAXH];
    int miss[MAXM];
    int sunkships;
};
//Function prototypes
void rules();
void getInfo(players []);
void board(players []);
void locatn(players [], int);
void display(players [], int);
//Execution Begins Here
int main(int argc, char** argv) {
    //create dynamic struct
    players* stats = new players[NUMPLAY];
    
    //display rules
    rules();
    
    //get user names
    getInfo(stats);
    

    //create board 10x10 for player 1
    board(stats);
    
    //enter 5 ships
    cout<<"Enter ships for Player 1"<<endl;
    for(int i=0; i<NUMPLAY; i++){
      display(stats, i);  
      locatn(stats, i);
    }
    
    //delete dynamic array
    delete[] stats;
    
    return 0;
}
//Functions
//Display the rules of the game
//******************************************************************************
//******************************************************************************
void rules(){
    fstream rules;
    string line;
    rules.open("rules.txt", ios::in);
    
    if (rules.fail()){
        cout<<"rules.txt not found!"<<endl;
    }
    else{
        while(! rules.eof()){
            getline(rules, line);
            cout<<line<<endl;
        }
    }
    cout<<endl<<endl<<endl;
}
//create player 1's board.
//******************************************************************************
//******************************************************************************
void board(players strctr[]){
    //create the board
    for(int p=0; p<NUMPLAY; p++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                strctr[p].board[i][j]='-';
            }  
        }
    }
}
//create player 1's board.
//******************************************************************************
//******************************************************************************
void locatn(players strctr[], int p){
    //fill the board with players
    int aircr=5;
    int bShip=4;
    int crsr=3;
    int sub=3;
    int dest=2;
    int row1=0;
    int col=0;
    //enter for aircraft carrier
    for(int i=0; i<aircr; i++){
        cout<<"Enter row1 Aircraft Carrier (1-10)(5 Units in length)"<<endl;
        cin>>row1;
        while(row1>10||row1<1){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Aircraft Carrier (1-10)(5 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<1){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        while(strctr[p].board[row1-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row1: ";
            cin>>row1;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row1-1][col-1]='A';
        display(strctr, p);
        cout<<endl;
    }
    //reset row1 and col
    row1=0;
    col=0;
    //enter for battleship
    for(int i=0; i<bShip; i++){
        cout<<"Enter row1 Battleship (1-10)(4 Units in length)"<<endl;
        cin>>row1;
        while(row1>10||row1<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Battleship (1-10)(4 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        while(strctr[p].board[row1-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row1: ";
            cin>>row1;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row1-1][col-1]='B';
        display(strctr, p);
        cout<<endl;
    }
    //enter for cruiser
    for(int i=0; i<crsr; i++){
        cout<<"Enter row1 Cruiser (1-10)(3 Units in length)"<<endl;
        cin>>row1;
        while(row1>10||row1<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Cruiser (1-10)(5 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        while(strctr[p].board[row1-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row1: ";
            cin>>row1;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row1-1][col-1]='C';
        display(strctr, p);
        cout<<endl;
    }
    //enter for submarine
    for(int i=0; i<sub; i++){
        cout<<"Enter row1 Submarine (1-10)(3 Units in length)"<<endl;
        cin>>row1;
        while(row1>10||row1<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Submarine (1-10)(3 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        while(strctr[p].board[row1-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row1: ";
            cin>>row1;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row1-1][col-1]='S';
        display(strctr, p);
        cout<<endl;
    }
    //enter for destroyer
    for(int i=0; i<dest; i++){
        cout<<"Enter row1 Destroyer (1-10)(2 Units in length)"<<endl;
        cin>>row1;
        while(row1>10||row1<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Destroyer (1-10)(2 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        while(strctr[p].board[row1-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row1: ";
            cin>>row1;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row1-1][col-1]='D';
        display(strctr, p);
        cout<<endl;
    }
    
}
//display the board
//******************************************************************************
//******************************************************************************
void display(players strctr[], int plyr){
    cout<<"  1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<"| ";
        for(int j=0; j<SIZE; j++){
            cout<<strctr[plyr].board[i][j]<<" | ";
        }
        cout<<i+1<<endl;
    }
}
//get user info
//******************************************************************************
//******************************************************************************
void getInfo(players strctr[]){
    cout<<"Enter names"<<endl;
    for(int i=0; i<NUMPLAY; i++){
        cout<<"Name of Player "<<i+1<<endl;
        cin>>strctr[i].name;
        cout<<endl;
    }
}