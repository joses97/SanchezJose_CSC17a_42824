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
        int xpos;
        int ypos;
        int fxpos;
        int fypos;
    public:
        battlegship(){
            xpos=0;
            ypos=0;
            fxpos=0;
            fypos=0;
        }
        void battleshipC(int x, int y, int x2, int y2){
            xpos=x;
            ypos=y;
            fxpos=x2;
            fypos=y2;
        }
        int getxpos() const {return xpos;}
        int getypos() const {return ypos;}
        int getfxpos() const {return fxpos;}
        int getfypos() const {return fypos;}
};


#endif /* SHIPPS_H */

