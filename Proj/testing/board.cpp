/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "board.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//initialize static variable to 0
int board::count=0;
//******************************************************************************
//******************************************************************************
//Set static variable of array of 5 to the values of names of ships
int board::sizes[NUMSHIP]={5, 4, 3, 3, 2};
//******************************************************************************
//******************************************************************************
//Set static variable of array of 5 to the values of names of ships
string board::names[NUMSHIP]={"Carrier", "Battleship", "Cruiser", "Submarine",
    "Destroyer"};
//******************************************************************************
//******************************************************************************
//Defaulted Constructor For creating a board
board::board(){
    //create 5 ships per board, dynamically create 5 ships of class warShip
    ships = new warShip[NUMSHIP];
    //for loop to create the 10x10 board
    for(int i=0; i<SIZE; i++) //loop 10 times for row
    { 
        for(int j=0; j<SIZE; j++) //loop 10 times for column
        {
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
//Test to see if user entered values are valid entries
bool board::testCor(int i, int xOne, int yOne, int xTwo, int yTwo){
    bool test1=false;   //to test if x is a constant
    bool test2=false;   //to test if y is a constant
    //set the size to the size of the ship, for testing users entered size
    int size=ships[i].getSize();
    
    //test to see if x is a constant
    if(abs(xOne-xTwo)==0){
        test1=true; //if true set test1 to true, shows x is constant
    }
    
    //test to see if y is a constant
    if(abs(yOne-yTwo)==0){
        test2=true; //if true set test2 to true, shows y is a constant
    }
    
    //try to see if any errors occured
        //test for x and y constance
        if(test1&&test2){
            throw invalid();//if both x and y are constant return false, bad input
            return false;   //return false for bad input
        }

        // if test 1 was the constant test for the difference in y coordinates
        else if(test1){
            if(abs(yOne-yTwo-1)==size){ //if difference is equal to size
                return true;    //return true for good input
            }
            else{   //else
                throw invalid(); //throw invalid for bad input
                return false;   //return false for a bad input
            }   
        }
        //if test 2 was the constant test for the difference in x coordinates
        else if(test2){
            if(abs(xOne-xTwo-1)==size){ //if difference in x was = to size
                return true;    //return true for good input
            }   
            else{
                throw invalid(); //throw invalid for bad input
                return false; //return false for a bad input
            }
        }
    //if for some reason all tests failed, 
    throw invalid();    //throw invalid
    return false;       //return false
}

//******************************************************************************
//******************************************************************************
void board::setSize(){
    //loop 5 time to set the size of the ships
    for(int i=0; i<NUMSHIP; i++){
        ships[i].setSize(sizes[i]);
    }
}
//******************************************************************************
//******************************************************************************
void board::setSNms(){
    //loop 5 times to assign a name to the object
    for(int i=0; i<NUMSHIP; i++){
        ships[i].setsNam(names[i]);
    }
}
//******************************************************************************
//******************************************************************************
string board::getN(int i){ //returns the name of the ship requested
    return ships[i].getName();
}
//******************************************************************************
//******************************************************************************
int board::getSzs(int i){ //returns the name of the ship requested
    return ships[i].getSize();
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
void board::makeShp(int i, int a, int b, int c, int d){
    //fill in values for the array of ships, 
    // a and b are the initial x and y position
    //c and d are the final x and y position
    ships[i].bShipC(a, b, c, d);
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
    char p='A';
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<static_cast<char>(p+i);
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
        array[ships[n].getypos()-1][i]='X'; //array[ships[n].getypos()-1][i]='X'
    }
    

    ////fills in from the initial ship position to the final position for y
    for(int i=ships[n].getypos(); i<ships[n].getfypos(); i++){
        array[i][ships[n].getxpos()-1]='X'; //array[i][ships[n].getxpos()-1]='X'
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