/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on June 4th 2016
 */

//System libraries
#include <iostream>

//User libraries
#include "shipps.h"
using namespace std;

//define board.h
#ifndef BOARD_H
#define	BOARD_H

//global constants
const int SIZE=10; //size of the board
const int NUMSHIP=5; //number of ships
const int NUMPLAY=2; //number of players

//create class board, inherit from warShip to gain access to protected members
class board : public warShip{
    private:
        static int hits; //count
        static int misses;
        static int sizes[NUMSHIP]; //sizes of the ship
        static string names[NUMSHIP]; //names of the ships
        char array[SIZE][SIZE]; //holds the board information
        warShip *ships; //pointer to ships on the board
        int xGuess;
        int yGuess;
    public:
        class invalid{};
        board(); //constructor
        ~board(); //destructor 
        string getN(int); //gets the name of the current ship 
        void disCoor(int);  //gets the coordinates of the current ship
        void operator = (const board &right); //operator to copy  data
        void setSNms(); //set names of the ships
        void setSize(); //set the sizes of the ships created
        void makeShp(int , int , int , int , int); //create ships
        void shipOn(int);   //set initial points of ships
        void display();     //diplay the 2d array
        void fillrest(int); //fills in the values
        void getGess(int, int); //assigns values to the class for the users guesses
        char check(int, int, board&); //checks to see if coordinates contain ship
        int getSzs(int);    //get the size of the current ship
        int getXGss(){return xGuess;} //return the users x value guess
        int getYGss(){return yGuess;}   //return the users y value guess 
        int getNumS(){return totShip;} //returns the number of ships created
        bool testCor(int, int, int, int, int);//tests the coordinates of the 
        operator int(){ return (hits+misses); } //returns the count
        board operator +(const board &);    //
        board operator -(const board &);    //
        board& operator++(); //
        board operator++(int);//
        board& operator--();//
        board operator--(int);//
};

#endif	/* BOARD_H */


