/* 
 * File:   board.h
 * Author: Jose
 *
 * Created on May 27, 2016, 12:58 AM
 */

#include "shipps.h"
#include <iostream>
using namespace std;


#ifndef BOARD_H
#define	BOARD_H
const int SIZE=10; //size of the board
const int NUMSHIP=5; //number of ships

class board : public warShip{
    private:
        static int count; //count
        static int sizes[NUMSHIP]; //sizes of the ship
        static string names[NUMSHIP]; //names of the ships
        char array[SIZE][SIZE]; //holds the board information
        warShip *ships; //pointer to ships on the board
    public:
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
        int getNumS(){return totShip;} //returns the number of ships created
        operator int(){ return count; } //returns the count
        board operator +(const board &);    //
        board operator -(const board &);    //
        board& operator++(); //
        board operator++(int);//
        board& operator--();//
        board operator--(int);//
};

#endif	/* BOARD_H */


