/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shipps.h
 * Author: Jose
 *
 * Created on May 27, 2016, 1:28 AM
 */

#ifndef SHIPPS_H
#define SHIPPS_H
#include <iostream>
using namespace std;

class warShip{
    protected:
        string sName;
        int xpos;
        int ypos;
        int fxpos;
        int fypos;
        static int totShip;
    public:
        warShip();
        void bShipC(int , int , int , int);
        void setsNam(string n){sName=n;}
        int getxpos() const {return xpos;}
        int getypos() const {return ypos;}
        int getfxpos() const {return fxpos;}
        int getfypos() const {return fypos;}
        string getName() const {return sName;}
};
#endif /* SHIPPS_H */

