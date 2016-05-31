/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jose
 *
 * Created on May 27, 2016, 1:25 AM
 */

#include <cstdlib>
#include <iostream>
#include "board.h"
using namespace std;

/*
 * 
 */

//functions


int main(int argc, char** argv) {
    int count;
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    count=player1;
    
    cout<<count<<endl;
    
    
    
    
    player1.display();
    player1.makeShp(0, 2, 2, 6, 2, "SS JOSE");
    player1.shipOn(0);
    player1.disCoor(0);
    player1.fillrest(0);
    player1.display();
    cout<<player1.getN(0)<<endl;
    
    cout<<"Testing copy"<<endl;
    copy1=player1;
    copy1.display();

    
    
    return 0;
}
