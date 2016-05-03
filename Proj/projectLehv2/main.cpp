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
const int SIZE=10;
const int NUMPLAY=2;
//Structures
struct players{
    string name;
    char board[SIZE][SIZE];
};

//Function prototypes
void rules();
void board(players **);
void locatn(char [][SIZE]);
void display(players **);
//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    players *testStruct;
    testStruct = new players[NUMPLAY];
    
    //display rules
    rules();
    
    
    //create board 10x10 
    board(&testStruct);
    
    
    //display(&testStruct);
    
    //enter 5 ships
    //locatn(boardS);
    
    //display board
    display(&testStruct);
    
    
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
void board(players **play){
    //create dynamic struct array
    *play= new players[NUMPLAY];
    
    //create the board
    for(int p=0; p<NUMPLAY; p++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                play[p]->board[i][j]='-';
            }  
        }
    }
}
//create player 1's board.
//******************************************************************************
//******************************************************************************
/*void locatn(char board[][SIZE]){
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
        while(row1>10||row1<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>row1;
        }
        cout<<"Enter Column Aircraft Carrier (1-10)(5 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid position!"<<endl;
            cin>>col;            
        }
        board[row1-1][col-1]='A';
        display(board);
        cout<<endl;
    }
    //reset row1 and col
    row1=0;
    col=0;
    //enter for aircraft carrier
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
        board[row1-1][col-1]='B';
        display(board);
        cout<<endl;
    }
        //enter for aircraft carrier
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
        board[row1-1][col-1]='C';
        display(board);
        cout<<endl;
    }
        //enter for aircraft carrier
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
        board[row1-1][col-1]='S';
        display(board);
        cout<<endl;
    }
        //enter for aircraft carrier
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
        board[row1-1][col-1]='D';
        display(board);
        cout<<endl;
    }
    
}
*/
//display the board
//******************************************************************************
//******************************************************************************
void display(players **play){
    //create dynamic array of structs
    *play = new players[NUMPLAY];
    
    //for loop 
    for(int p=0; p<NUMPLAY; p++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                cout<<play[p]->board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}