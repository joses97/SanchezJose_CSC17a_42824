/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "board.h"
#include <iostream>
#include <string>
using namespace std;

//initialize static variable to 0
int board::count=0;

//******************************************************************************
//******************************************************************************
string board::names[NUMSHIP]={"Battleship", " ", " ", " ", " "};

//******************************************************************************
//Defaulted Constructor For creating a board
board::board(){
    //create 5 ships per board, dynamically create 5 ships of class warShip
    ships = new warShip[NUMSHIP];
    //for loop to create the 10x10 board
    for(int i=0; i<SIZE; i++){ //loop 10 times for row
        for(int j=0; j<SIZE; j++){//loop 10 times for column
            array[i][j]='-'; //set the private member to - for the grid
        }
    }
    //every time a board is created add one to static variable count
    count++;
}
//******************************************************************************
//******************************************************************************
board::~board(){
    //delete the dynamically created array of ships
    delete [] ships;
}
//******************************************************************************
//******************************************************************************
string board::getN(int i){
    return ships[i].getName();
}
//******************************************************************************
//******************************************************************************
void board::disCoor(int i){
    //Displays the coordinates of the ship at i 
    //output ships[i].getxpos(), ships[i].getypos()
    cout<<"Ship "<<i+1<<" is located at: "<<ships[i].getxpos()<<" and "
                        ""<<ships[i].getypos()<<endl;
}
//******************************************************************************
//******************************************************************************
void board::operator =(const board& right){
    //= operator copies to board of one board object to another
        for(int i=0; i<SIZE; i++){ //loop 10 times for the row fill in
            for(int j=0; j<SIZE; j++){ //loop 10 times for the column fill in
                array[i][j]=right.array[i][j]; //array[i][j]=right.array[i][j];
            }
        }
}
//******************************************************************************
//******************************************************************************
void board::makeShp(int i, int a, int b, int c, int d, string n){
    //fill in values for the array of ships, 
    // a and b are the initial x and y position
    //c and d are the final x and y position
    ships[i].bShipC(a, b, c, d, n);
}
//******************************************************************************
//******************************************************************************
void board::shipOn(int i){
    //assign the given ship initial coordinates to the array(board) 'X'
    array[ships[i].getypos()-1][ships[i].getxpos()-1]='X';
    //assign the final given ship coordinates to the array(board) to 'X'
    array[ships[i].getfypos()-1][ships[i].getfxpos()-1]='X';
}
//******************************************************************************
//******************************************************************************
void board::display(){
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<i+1;
        for(int j=0; j<SIZE; j++){
            cout<<" | "<<array[i][j];
        }  
        cout<<endl;
    }      
}
//******************************************************************************
//******************************************************************************
void board::fillrest(int n){
    //fills in from the initial ship position to the final position for x
    for(int i=ships[n].getxpos(); i<ships[n].getfxpos(); i++){
        array[ships[n].getxpos()-1][i]='X'; //array[ships[n].getypos()-1][i]='X'
    }
    

    ////fills in from the initial ship position to the final position for y
    for(int i=ships[n].getypos(); i<ships[n].getfypos(); i++){
        array[i][ships[n].getypos()-1]='X'; //array[i][ships[n].getxpos()-1]='X'
    }       
}
//******************************************************************************
//******************************************************************************
board board::operator +(const board &){
    
}
//******************************************************************************
//******************************************************************************
board board::operator -(const board &){
    
}
//******************************************************************************
//******************************************************************************
board& board::operator++(){
    
}
//******************************************************************************
//******************************************************************************
board board::operator++(int){
    
}
//******************************************************************************
//******************************************************************************
board& board::operator--(){
    
}
//******************************************************************************
//******************************************************************************
board board::operator--(int){
    
}