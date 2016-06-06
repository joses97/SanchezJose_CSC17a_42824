/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on June 4th 2016
 */

//define ship.h
#ifndef SHIPPS_H
#define SHIPPS_H

//System Libraries 
#include <iostream>
using namespace std;

//user libraries

//create class warShip
class warShip{
    protected:
        string sName;
        int size;
        int xpos;
        int ypos;
        int fxpos;
        int fypos;
        static int totShip;
    public:
        warShip();
        void bShipC(int , int , int , int);
        void setsNam(string n){sName=n;}
        void setSize(int n){size=n;}
        virtual void info(){};
        int getxpos() const {return xpos;}
        int getypos() const {return ypos;}
        int getfxpos() const {return fxpos;}
        int getfypos() const {return fypos;}
        int getSize() const {return size;}
        string getName() const {return sName;}
};
#endif /* SHIPPS_H */

