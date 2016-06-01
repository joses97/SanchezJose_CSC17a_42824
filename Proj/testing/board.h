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
const int SIZE=10;
const int NUMSHIP=5;

class board : public warShip{
    private:
        static int count;
        static string names[NUMSHIP];
        char array[SIZE][SIZE];
        warShip *ships;
    public:
        board();
        ~board();
        string getN(int);
        void disCoor(int); 
        void operator = (const board &right);
        void setSNms();
        void makeShp(int , int , int , int , int);
        void shipOn(int);
        void display();  
        void fillrest(int);
        int getNumS(){return totShip;}
        operator int(){ return count; }
        board operator +(const board &);
        board operator -(const board &);
        board& operator++();
        board operator++(int);
        board& operator--();
        board operator--(int);
};

#endif	/* BOARD_H */


