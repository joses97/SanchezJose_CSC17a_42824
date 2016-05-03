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
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const int MAXH=18;
const int MAXM=84;
const int SIZE=10; //max size for grid 
const int NUMPLAY=2;    //number of players
//Structures
struct players{
    string name; //name of player
    char board[SIZE][SIZE]; //board of player
    int hit[MAXH]; //hit 
    int miss[MAXM]; //misses
};
//Function prototypes
bool game(players []); //game itself
void rules();           //rules of the game
void getInfo(players []);   //get info of the players
void board(players []);     //create the board of the players
void locatn(players [], int);   //fill in the board of the players
void display(players [], int);  //display the board of the players
void display2(char board[][SIZE][SIZE], int);   //display the guesses of the players
//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    fstream file; //file to output
    int p1=0;    //player 1 
    int p2=1;    //player 2
    
    //create dynamic structure
    players* stats = new players[NUMPLAY];
    
    //open file
    file.open("Stats.dat", ios::out | ios::in | ios::binary);
    
    //display rules
    rules();
    
    //get user names
    getInfo(stats);

    //create board 10x10 for players
    board(stats);
    
    //display and fill in grid, loop twice for both players
    for(int i=0; i<NUMPLAY; i++){
        cout<<"Enter Ships for "<<stats[i].name<<endl;
        display(stats, i);  
        locatn(stats, i);
    }

    
    //play the game
    while(!game(stats));
    
    //write struct contents to 
    file.write(reinterpret_cast<char *>(&stats), sizeof(stats));
    
    file.close();  
    
    //delete dynamic array
    delete[] stats;
    
    return 0;
}
//Functions
//Display the rules of the game
//******************************************************************************
//******************************************************************************
void rules(){
    fstream rules; //rules fstream
    string line;  //to read into 
    
    //open the file rules.txt for input
    rules.open("rules.txt", ios::in);
    
    //if failed to open  tell user failed to open
    if (rules.fail()){
        cout<<"rules.txt not found!"<<endl;
    }
    //else display contents of the .txt
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
    //create the board loop for 2 players, initialize array to '-'
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
    unsigned short int aircr=5; //size of aircraft carrier
    short unsigned int bShip=4; //size of battleship
    short unsigned int crsr=3;  //size of cruiser
    short unsigned int sub=3;   //size of submarine
    short unsigned int dest=2;  //sie of destroyer
    short unsigned int row=0;   //row of grid
    short unsigned int col=0;   //column of grid
    //enter for aircraft carrier
    for(int i=0; i<aircr; i++){
        //enter row and column and validate input for range of 1-10
        cout<<"Enter row Aircraft Carrier (1-10)(5 Units in length)"<<endl;
        cin>>row;
        while(row>10||row<1){
            cout<<"Off the Grid! Enter valid row position!"<<endl;
            cin>>row;
        }
        cout<<"Enter Column Aircraft Carrier (1-10)(5 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<1){
            cout<<"Off the Grid! Enter valid column position!"<<endl;
            cin>>col;            
        }
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        //set char at [row-1][col-1] of board to 'A' for aircraft carrier
        strctr[p].board[row-1][col-1]='A';
        display(strctr, p);
        cout<<endl;
    }
    //reset row and col
    row=0;
    col=0;
    //enter for battleship
    for(int i=0; i<bShip; i++){
        //enter row and column, and input validate for range;
        cout<<"Enter row Battleship (1-10)(4 Units in length)"<<endl;
        cin>>row;
        while(row>10||row<0){
            cout<<"Off the Grid! Enter valid row position!"<<endl;
            cin>>row;
        }
        cout<<"Enter Column Battleship (1-10)(4 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid column position!"<<endl;
            cin>>col;            
        }
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        //set board at [row-1][col-1] of strctr[p];
        strctr[p].board[row-1][col-1]='B';
        display(strctr, p);
        cout<<endl;
    }
    //enter for cruiser
    for(int i=0; i<crsr; i++){
        //enter row and column, input validate for range 1-10
        cout<<"Enter row Cruiser (1-10)(3 Units in length)"<<endl;
        cin>>row;
        while(row>10||row<0){
            cout<<"Off the Grid! Enter row valid position!"<<endl;
            cin>>row;
        }
        cout<<"Enter Column Cruiser (1-10)(3 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid column position!"<<endl;
            cin>>col;            
        }
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        //set board at [row-1][col-1] of player at [p] to 'C' and display board
        strctr[p].board[row-1][col-1]='C';
        display(strctr, p);
        cout<<endl;
    }
    //enter for submarine
    for(int i=0; i<sub; i++){
        //enter row and column, input validate for range 1-10
        cout<<"Enter row Submarine (1-10)(3 Units in length)"<<endl;
        cin>>row;
        while(row>10||row<0){
            cout<<"Off the Grid! Enter valid row position!"<<endl;
            cin>>row;
        }
        cout<<"Enter Column Submarine (1-10)(3 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter column valid position!"<<endl;
            cin>>col;            
        }
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        //strctr[p].board[row-1][col-1]='S' and display board 
        strctr[p].board[row-1][col-1]='S';
        display(strctr, p);
        cout<<endl;
    }
    //enter for destroyer
    for(int i=0; i<dest; i++){
        //input row and col, input validate for range 1-10
        cout<<"Enter row Destroyer (1-10)(2 Units in length)"<<endl;
        cin>>row;
        while(row>10||row<0){
            cout<<"Off the Grid! Enter valid row position!"<<endl;
            cin>>row;
        }
        cout<<"Enter Column Destroyer (1-10)(2 Units in Length)"<<endl;
        cin>>col;
        while(col>10||col<0){
            cout<<"Off the Grid! Enter valid column position!"<<endl;
            cin>>col;            
        }
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        //strctr[p].board[row-1][col-1]='D' and run display function
        strctr[p].board[row-1][col-1]='D';
        display(strctr, p);
        cout<<endl;
    }
    
}
//display the board
//******************************************************************************
//******************************************************************************
void display(players strctr[], int plyr){
    //out top row for grid
    cout<<"     1   2   3   4   5   6   7   8   9   10"<<endl;
    //for loop
    for(int i=0; i<SIZE; i++){
        //output i+1 for left aligned grid
        cout << left << setw(3) << setfill(' ') <<i+1<<"| ";
        //for looper
        for(int j=0; j<SIZE; j++){
            //display strctr[plyr].board[i][j]<<" | "
            cout<<strctr[plyr].board[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//display the board copies
//******************************************************************************
//******************************************************************************
void display2(char board[][SIZE][SIZE], int p){
    //display top of grid 1-10
    cout<<"     1   2   3   4   5   6   7   8   9   10"<<endl;
    //for loop
    for(int i=0; i<SIZE; i++){
        //display i+1 left aligned for grid
        cout << left << setw(3) << setfill(' ') <<i+1<<"| ";
        //for loop
        for(int j=0; j<SIZE; j++){
            //display board[p][i][j]<<" | "
            cout<<board[p][i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//get user info
//******************************************************************************
//******************************************************************************
void getInfo(players strctr[]){
    cout<<"Enter names"<<endl;
    //for loop
    for(int i=0; i<NUMPLAY; i++){
        //enter strctr[i].name
        cout<<"Name of Player "<<i+1<<endl;
        cin>>strctr[i].name;
        cout<<endl;
    }
}
//play the game
//******************************************************************************
//******************************************************************************
bool game(players strctr[]){
    //declare and initialize variables
    int x=0, y=0;   //x position =0, y position =0;
    char boardC[NUMPLAY][SIZE][SIZE]; //3d character array holds user guesses
    bool endGame=false;             //bool for ending the game
    fstream p1board;
    fstream p2board;
    
    //for loop to create copy boards to keep track of users info
    for(int p=0; p<NUMPLAY; p++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                boardC[p][i][j]='-';
            }
        }
    }
    //while (!endGame)
    while(!endGame){
        //player 1 turn
        for(int p=0, p2=1; p<NUMPLAY; p++, p2--){
            //display board and guesses
            cout<<strctr[p].name<<"'s Board"<<endl;
            display(strctr, p);
            cout<<strctr[p].name<<"'s Guesses"<<endl;
            display2(boardC, p);

            //Player 1 turn, input guess for x and y location
            cout<<strctr[p].name<<"'s Turn!"<<endl;
            cout<<"Input Guess for Row: ";
            cin>>x;
            cout<<endl;
            cout<<"Input Guess for Column: ";
            cin>>y;
            cout<<endl;

            //if the the x and y == letter then mark hit on player 1's copy board
            if(strctr[p2].board[x-1][y-1]!='-'){
                strctr[p2].board[x-1][y-1]='X';
                cout<<" HIT "<<endl;
                boardC[p][x-1][y-1]='X';
            }
            //if x and y!= letter then mark 0 for miss on player 1's copy board
            else if(strctr[p2].board[x-1][y-1]=='-'){
                cout<<"MISSED!"<<endl;
                boardC[p][x-1][y-1]='O';
            }
            //display board and guesses
            cout<<strctr[p].name<<"'s Board"<<endl;
            display(strctr, p);
            cout<<strctr[p].name<<"'s Guesses"<<endl;
            display2(boardC, p);


            //next players turn 
            cout<<"Press enter for next players turn!"<<endl;
            cin.ignore();
            cin.get();
            
            //reset x and y position guesses
            x=0;
            y=0;
            
            //declare and initialize variables
            int count[NUMPLAY]={0}; //2d array to hold number of hits
            //run test for endgame
            for(int p=0; p<NUMPLAY; p++){
                for(int i=0; i<SIZE; i++){
                    for(int j=0; j<SIZE; j++){
                        if(boardC[p][i][j]=='X'){
                            count[p]++;
                        }
                    }
                }
            }
            for(int i=0; i<NUMPLAY; i++){
                if(count[i]>=17){
                    cout<<"GAME OVER! "<<strctr[i].name<<" WINS!"<<endl;
                    endGame=true;
                }
            }
        }
    }
    return endGame;
}