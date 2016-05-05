/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on 5/3/16
 */

//System Libraries
#include <iostream> //i/o
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries
#include "proj.h"
//Global Constants
const int NUMPLAY=2;    //number of players

//Function prototypes
void game(players []); //game itself
void rules();           //rules of the game
void getInfo(players []);   //get info of the players
void board(players []);     //create the board of the players
void locatn(players [], int);   //fill in the board of the players
void display(players [], int);  //display the board of the players
void display2(char board[][SIZE][SIZE], int);   //display the guesses of the players
void names(players []);
//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    fstream file; //file to output
    fstream rFile; //read in file
    int p1=0;    //player 1 
    int p2=1;    //player 2
    
    //create dynamic structure
    players* stats = new players[NUMPLAY];
    players* readIn = new players[NUMPLAY];
    
    //display rules
    rules();
    
    //get user names
    getInfo(stats);
    
    //display sorted array
    names(stats);

    //create board 10x10 for players
    board(stats);
    
    //display and fill in grid, loop twice for both players
    for(int i=0; i<NUMPLAY; i++){
       cout<<"Enter Ships for "<<stats[i].name<<endl;
       //call display and locatn
       display(stats, i);  
       locatn(stats, i);
    }
    //play the game
    game(stats);
    
    //write struct contents to a file "Stats.dat" as binary information
    file.open("Stats.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&stats), sizeof(stats));
    file.close();  
    
    //open the "Stats.dat" binary file and read it into a structure
    rFile.open("Stats.dat", ios::in | ios::binary);
    rFile.read(reinterpret_cast<char *>(&readIn), sizeof(readIn));
    //display contents of structure for loop p<NUMPLAY
    for(int p=0; p<NUMPLAY; p++){
        cout<<readIn[p].name<<"'s Board"<<endl; //output readIn[p].name
        display(readIn, p); //call display
    }
    
    //close file
    rFile.close();
    
    //delete dynamic array
    delete stats;
    delete readIn;
    //exit
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
        while(! rules.eof()){       //while !rules.eof())
            getline(rules, line); //call get line
            cout<<line<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    //close rules file
    rules.close();
}
//create player 1's board.
//******************************************************************************
//******************************************************************************
void board(players strctr[]){
    //create the board loop for 2 players, initialize array to '-'
    for(int p=0; p<NUMPLAY; p++){ // p=0; p<NUMPLAY; p++
        for(int i=0; i<SIZE; i++){//i=0; i<SIZE; i++
            for(int j=0; j<SIZE; j++){//int j=0; j<SIZE; j++
                strctr[p].board[i][j]='-';//strctr[p].board[i][j]='-'
            }  
        }
    }
}
//create player 1's and 2's board
//******************************************************************************
//******************************************************************************
void locatn(players strctr[], int p){
    //fill the board with players
    short unsigned int aircr=5; //size of aircraft carrier
    short unsigned int bShip=4; //size of battleship
    short unsigned int crsr=3;  //size of cruiser
    short unsigned int sub=3;   //size of submarine
    short unsigned int dest=2;  //sie of destroyer
    short unsigned int row=0;   //row of grid
    short unsigned int col=0;   //column of grid
    //enter for aircraft carrier
    for(int i=0; i<aircr; i++){ //for loop  for aircraft carrier
        //enter row and column and validate input for range of 1-10
        do{ //do 
            cout<<"Enter row Aircraft Carrier X: 1-10 (5 Units in length)"<<endl;
            cin>>row; //enter row
        }while(row>10||row<1); //while row>10||row<1
        do{ //do 
            cout<<"Enter Column Aircraft Carrier (1-10)(5 Units in Length)"<<endl;
            cin>>col; //enter col
        }while(col>10||col<1); //while(col>10||col<1)
        
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row;       //enter row
            cout<<endl<<"Column: ";
            cin>>col;       //enter column
        }
        //set char at [row-1][col-1] of board to 'A' for aircraft carrier
        strctr[p].board[row-1][col-1]='A';
        display(strctr, p);     // call display
        cout<<endl;
    }
    //reset row and col
    row=0;
    col=0;
    //enter for battleship
    for(int i=0; i<bShip; i++){ //for loop battleship
        //enter row and column, and input validate for range;
        do{ //do loop
            cout<<"Enter row Battleship (1-10)(4 Units in length)"<<endl;
            cin>>row; //enter row
        }while(row>10||row<1); //while row>10||row<1
        do{ //do while loop
            cout<<"Enter Column Battleship (1-10)(4 Units in Length)"<<endl;
            cin>>col; //enter col
        }while(col>10||col<1); //while(col>10||col<1)
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"Row: ";
            cin>>row; //enter row 
            cout<<endl<<"Column: ";
            cin>>col; //enter column
        }
        //set board at [row-1][col-1] of strctr[p];
        strctr[p].board[row-1][col-1]='B';
        display(strctr, p); //call display function
        cout<<endl;
    }
    //enter for cruiser
    for(int i=0; i<crsr; i++){ //for loop for cruiser 
        //enter row and column, input validate for range 1-10
        do{     //do while loop
            cout<<"Enter row Cruiser (1-10)(3 Units in length)"<<endl;
            cin>>row; //enter row
        }while(row>10||row<1); //while row>10||row<1
        do{     //do while loop
            cout<<"Enter Column Cruiser (1-10)(3 Units in Length)"<<endl;
            cin>>col;   //enter col
        }while(col>10||col<1); //while(col>10||col<1)
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;       //enter row
            cout<<endl<<"Column: ";
            cin>>col;       //enter col
        }
        //set board at [row-1][col-1] of player at [p] to 'C' and display board
        strctr[p].board[row-1][col-1]='C';
        display(strctr, p);     //call display
        cout<<endl;
    }
    //enter for submarine
    for(int i=0; i<sub; i++){ //for loop for sub
        //enter row and column, input validate for range 1-10
        do{ //do while loop
            cout<<"Enter row Submarine (1-10)(3 Units in length)"<<endl;
            cin>>row; //enter row
        }while(row>10||row<1); //while row>10||row<1
        do{ //do while loop
            cout<<"Enter Column Submarine (1-10)(3 Units in Length)"<<endl;
            cin>>col;   //enter col
        }while(col>10||col<1);      //while(col>10||col<1)
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;       //enter row
            cout<<endl;
            cout<<"Column: ";
            cin>>col;       //enter column
        }
        //strctr[p].board[row-1][col-1]='S' and display board 
        strctr[p].board[row-1][col-1]='S';
        display(strctr, p);     //call display
        cout<<endl;
    }
    //enter for destroyer
    for(int i=0; i<dest; i++){  //for loop for destroyer
        //input row and col, input validate for range 1-10
        do{ //do while loop
            cout<<"Enter row Destroyer (1-10)(2 Units in length)"<<endl;
            cin>>row; //enter row
        }while(row>10||row<1); //while row>10||row<1
        do{     //do while loop
            cout<<"Enter Column Destroyer (1-10)(2 Units in Length)"<<endl;
            cin>>col;   //enter col
        }while(col>10||col<1);      //while(col>10||col<1)
        //if the input already had a letter, repeat input 
        while(strctr[p].board[row-1][col-1]!='-'){
            cout<<"Position occupied! Enter different position"<<endl;
            cout<<"row: ";
            cin>>row;   //enter row 
            cout<<endl;
            cout<<"Column: ";
            cin>>col;       //enter col
        }
        //strctr[p].board[row-1][col-1]='D' and run display function
        strctr[p].board[row-1][col-1]='D';
        display(strctr, p);     //call display
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
        //for loop
        for(int j=0; j<SIZE; j++){
            //display strctr[plyr].board[i][j]<<" | "
            cout<<strctr[plyr].board[i][j]<<" | ";
        } cout<<endl;
    } cout<<endl;
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
        }cout<<endl;
    }cout<<endl;
}
//get user info
//******************************************************************************
//******************************************************************************
void getInfo(players strctr[]){
    cout<<"Enter names"<<endl;
    //for loop i<NUMPLAY
    for(int i=0; i<NUMPLAY; i++){
        //enter strctr[i].name
        cout<<"Name of Player "<<i+1<<endl;
        getline(cin, strctr[i].name);
        cout<<endl;
    }
}
//play the game
//******************************************************************************
//******************************************************************************
void game(players strctr[]){
    //declare and initialize variables
    int x=0, y=0;   //x position =0, y position =0;
    char boardC[NUMPLAY][SIZE][SIZE]; //3d character array holds user guesses
    bool endGame=false;             //bool for ending the game
    
    //for loop to create copy boards to keep track of users info
    for(int p=0; p<NUMPLAY; p++){       //p=0; p<NUMPLAY; p++
        for(int i=0; i<SIZE; i++){      //i=0; i<SIZE; i++
            for(int j=0; j<SIZE; j++){  //int j=0; j<SIZE; j++
                boardC[p][i][j]='-';        //boardC[p][i][j]='-'
            }
        }
    }
    //while (!endGame)
    while(!endGame){
        //player turn and player 2 turn
        for(int p=0, p2=1; p<NUMPLAY; p++, p2--){
            //display board and guesses
            cout<<strctr[p].name<<"'s Board"<<endl;
            display(strctr, p);
            cout<<strctr[p].name<<"'s Guesses"<<endl;
            display2(boardC, p);

            //Player turn, input guess for x and y location and input validate
            cout<<strctr[p].name<<"'s Turn!"<<endl;
            do{ //do while
                cout<<"Input Guess for Row: ";
                cin>>x;     //enter x
                cout<<endl;
            }while(x>10||x<1); //while(x>10||x<1)

            do{ //do while
                cout<<"Input Guess for Column: ";
                cin>>y; //enter y
                cout<<endl;
            }while(y>10||y<1);  //while(y>10||y<1)

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
            display(strctr, p); //call display
            cout<<strctr[p].name<<"'s Guesses"<<endl;
            display2(boardC, p);    //call display2


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
            for(int p=0; p<NUMPLAY; p++){       //p=0; p<NUMPLAY; p++
                for(int i=0; i<SIZE; i++){      //i=0; i<SIZE; i++
                    for(int j=0; j<SIZE; j++){  //j=0; j<SIZE; j++
                        if(boardC[p][i][j]=='X'){   //if boardC[p][i][j]=='X'
                            count[p]++;         //calculate count[p]++;
                        }
                    }
                }
            }
            //check for win
            for(int i=0; i<NUMPLAY; i++){   //for i=0; i<NUMPLAY; i++
                if(count[i]>=17){           //if count[i]>=17
                    cout<<"GAME OVER! "<<strctr[i].name<<" WINS!"<<endl;
                    endGame=true; //set endGame=true
                }
            }
        }
    }
}
//sort the names by alphabetical order, then show user sorted names
//******************************************************************************
//******************************************************************************
void names(players sortN[]){
    //declare and initialize variables
    int p1=0; //player 1 
    int p2=1; //player 2
    bool swap; //bool for swapping
    char temp;  //temp 1
    char temp2; //temp 2
    int size1=sortN[p1].name.size(); //size of name of player 1
    int size2=sortN[p2].name.size(); //size of name of player 2 
    char* name1 = new char[size1];  //name 1 dynamic array
    char* name2 = new char[size2];  //name 2 dynamic array
    
    //fill character arrays with for loop i=0; i<size1; i++
    for(int i=0; i<size1; i++){
        name1[i]=sortN[p1].name[i];  //name1[i]=sortN[p1].name[i]
    }
    
    for(int i=0; i<size2; i++){     //i=0; i<size2; i++
        name2[i]=sortN[p2].name[i]; //name2[i]=sortN[p2].name[i];
    }
    
    //bubble sort character arrays for name 2
    do{
        swap=false;
        for(int count=0; count<(size2-1); count++){
            if(*(name2+count)>name2[count+1]){
                temp2=*(name2+count);
                *(name2+count)=name2[count+1];
                name2[count+1]=temp2;
                swap=true;
            }
        }
    }while(swap);
    
    //bubble sort character arrays for name1
    do{
        swap=false;
        for(int count=0; count<(size1-1); count++){
            if(*(name1+count)>name1[count+1]){
                temp=*(name1+count);
                *(name1+count)=name1[count+1];
                name1[count+1]=temp;
                swap=true;
            }
        }
    }while(swap);
    
    //output sorted names for player 1
    cout<<sortN[p1].name<<"'s name sorted by alphabetical order is: ";
    for(int i=0; i<size1; i++){ //for loop i=0; i<size1; i++
        cout<<*(name1+i);       //output *(name1+i)
    }
    
    //output sorted name for player 2
    cout<<endl<<endl;
    cout<<sortN[p2].name<<"'s name sorted by alphabetical order is:  ";
    for(int i=0; i<size2; i++){ //for loop i=0; i<size2; i++
        cout<<name2[i];         //output name2[i];
    }
    cout<<endl<<endl;
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    cout<<endl<<endl;
    //delete allocated memory
    delete[] name1;
    delete[] name2;
}