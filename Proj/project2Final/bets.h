/* 
 * File:   bets.h
 * Author: Jose Sanchez
 * Purpose: bets file
 * Created on June 4th 2016
 */

//System Libraries

//User Libraries

//Global Constants
 
//Define board
#ifndef BETS_H
#define BETS_H

//create template class
template <class T>
//class bets
class bets{
    T p1; //first variable
    T p2; //second variable
    //public functions
    public:
        bets(T a, T b){ //constructor accepts two variables
            p1=a; //set p1=a
            p2=b; //set p2=a
        }
        //get bets
        T getBets(){return p1+p2;} //when called returns total in pool
};

#endif /* BETS_H */

