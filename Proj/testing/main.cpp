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
void inputS(board&, int);

int main(int argc, char** argv) {
    int count;
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    
    
    for(int i=0; i<2; i++){
        player1.display();
        inputS(player1, i);
        player1.display();
    }
    
    
    
    
    cout<<"Testing copy"<<endl;
    copy1=player1;
    copy1.display();

    
    
    return 0;
}
//character to int
int CtoInt(char y){
    switch (y){
        case 'A':return 1;
        case 'B':return 2;
        case 'C':return 3;
        case 'D':return 4;
        case 'E':return 5;
        case 'F':return 6;
        case 'G':return 7;
        case 'H':return 8;
        case 'I':return 9;
        case 'J':return 10;
        default: return 11;
    }
}

//create ships;
void inputS(board &player, int i){
    int x=0;
    int y=0; 
    int x2=0; 
    int y2=0;
    char Cypos;
    

    
    //enter
    do{
        cout<<"enter the initial x position 1-10"<<endl;
        cin>>x;
    }while(x>10||x<1);
        //enter
    do{    
        cout<<"enter the initial y position A-J"<<endl;
        cin>>Cypos;
    }while(CtoInt(toupper(Cypos))==11);
    //convert
    y=CtoInt(toupper(Cypos));
    
    //enter
    do{
        cout<<"enter the final x position 1-10"<<endl;
        cin>>x2;
    }while(x2>10||x2<1);
    //enter
    do{    
        cout<<"enter the final y position A-J"<<endl;
        cin>>Cypos;
    }while(CtoInt(toupper(Cypos))==11);
    //convert
    y2=CtoInt(toupper(Cypos));
    
    //create ship with initial x and pos positions
    player.makeShp(i, x, y, x2, y2, "BATTLESHIP");
    player.shipOn(i);
    player.disCoor(i);
    player.fillrest(i);
}