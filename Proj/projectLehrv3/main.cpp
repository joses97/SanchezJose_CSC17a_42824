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
const int SIZE=10;
const int NUMPLAY=2;
//Structures
struct players{
    string name;
    char board[SIZE][SIZE];
    int hit[NUMPLAY];
    int miss[NUMPLAY];
};
//Function prototypes
bool game(players []);
void rules();
void getInfo(players []);
void board(players []);
void locatn(players [], int);
void display(players [], int);
void display2(char board[][SIZE][SIZE], int);
//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    fstream file;
    int p1=0;
    int p2=1;
    
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
    
    //enter 5 ships
    for(int i=0; i<NUMPLAY; i++){
        cout<<"Enter Ships for Player "<<i+1<<endl;
        display(stats, i);  
        locatn(stats, i);
    }
    cout<<"Player 1"<<endl;
    display(stats, p1);
    cout<<"Player 2"<<endl;
    display(stats, p2);
    
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
    int row=0;
    int col=0;
    //enter for aircraft carrier
    for(int i=0; i<aircr; i++){
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
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row-1][col-1]='A';
        display(strctr, p);
        cout<<endl;
    }
    //reset row and col
    row=0;
    col=0;
    //enter for battleship
    for(int i=0; i<bShip; i++){
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
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row-1][col-1]='B';
        display(strctr, p);
        cout<<endl;
    }
    //enter for cruiser
    for(int i=0; i<crsr; i++){
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
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row-1][col-1]='C';
        display(strctr, p);
        cout<<endl;
    }
    //enter for submarine
    for(int i=0; i<sub; i++){
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
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row-1][col-1]='S';
        display(strctr, p);
        cout<<endl;
    }
    //enter for destroyer
    for(int i=0; i<dest; i++){
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
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;
            cout<<endl;
            cout<<"Column: ";
            cin>>col;
        }
        strctr[p].board[row-1][col-1]='D';
        display(strctr, p);
        cout<<endl;
    }
    
}
//display the board
//******************************************************************************
//******************************************************************************
void display(players strctr[], int plyr){
    cout<<"     1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0; i<SIZE; i++){
        cout << left << setw(3) << setfill(' ') <<i+1<<"| ";
        for(int j=0; j<SIZE; j++){
            cout<<strctr[plyr].board[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//display the board
//******************************************************************************
//******************************************************************************
void display2(char board[][SIZE][SIZE], int p){
    cout<<"     1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0; i<SIZE; i++){
        cout << left << setw(3) << setfill(' ') <<i+1<<"| ";
        for(int j=0; j<SIZE; j++){
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
    for(int i=0; i<NUMPLAY; i++){
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
    int x=0;
    int y=0;
    char boardC[NUMPLAY][SIZE][SIZE];
    bool endGame=false;
    fstream p1board;
    fstream p2board;
    
    //for loop to copy boards for user reference
    for(int p=0; p<NUMPLAY; p++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                boardC[p][i][j]=strctr[p].board[i][j];
            }
        }
    }
    
    while(!endGame){
        //player 1 turn
        for(int p=0, p2=1; p<NUMPLAY; p++, p2--){
            //display board and guesses
            cout<<strctr[p].name<<" Board"<<endl;
            display(strctr, p);
            cout<<strctr[p].name<<" Guesses"<<endl;
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
            cout<<strctr[p].name<<" Board"<<endl;
            display(strctr, p);
            cout<<strctr[p].name<<" Guesses"<<endl;
            display2(boardC, p);


            //next players turn 
            cout<<"Press enter for next players turn!"<<endl;
            cin.ignore();
            cin.get();

            x=0;
            y=0;
            
            int count[NUMPLAY]={0};
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
}