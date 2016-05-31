/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "shipps.h"

int warShip::totShip=0;

warShip::warShip(){
    xpos=0;
    ypos=0;
    fxpos=0;
    fypos=0;
    //totShip++;
}
void warShip::bShipC(int x, int y , int x2,  int y2){
    xpos=x;
    ypos=y;
    fxpos=x2;
    fypos=y2;
}