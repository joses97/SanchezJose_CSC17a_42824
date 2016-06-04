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
#include <cmath>
#include "board.h"
using namespace std;

/*
 * 
 */

//functions
void inputS(board&, int);
char checkC(board, int, int, int, int, int);

int main(int argc, char** argv) {
    int count;
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    
    player1.setSNms();
    player1.setSize();
    
    
    for(int i=0; i<1; i++){
        player1.display();
        inputS(player1, i);
        player1.display();
    }
    
    
    
    
    cout<<"Testing copy"<<endl;
    copy1=player1;
    copy1.display();
    
    return 0;
}
//******************************************************************************
//******************************************************************************
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
//******************************************************************************
//******************************************************************************
char checkC(board player, int i, int x, int y, int x2, int y2){
    //NOTE TO DR LEHR. RETURNING BOOL KEPT RESULTING IN RUN FAILED, USED INT NOW
    bool check1=false; //check for y value difference is 0
    bool check2=false; //check for x value difference is 0
    int size = player.getSzs(i);
    //swap x and x2 for greatest value
    if(x>x2){
        int temp=x;
        x=x2;
        x2=temp;
    }
    //swap y and y2 for the greatest value
    if(y>y2){
        int temp=y;
        y=y2;
        y2=temp;
    }
    //find if y is constant in the user entered values
    if(y2-y==0){
        check1=true;
    }
    //find if the x is constant in the user entered values
    if(x2-x==0){
        check2=true;
    } 
    //if the y values are constant
    if(check1==true){
        //check to see if x values are the correct distance from each other
        if(x2-x==size){
            return 'n'; //return n for a good user entry, no need to rereun
        }
        else{
            return 'y'; //return y for a bad user entry, yes need to rerun
        }
        
    }
    else if(check2==true){
        //check to see if y values are the correct distance from each other
        if(y2-y==size){
            return 'n'; //return n for a good user entry
        }
        else{
            return 'y'; //return y for a bad user entry
        }        
    }
    else{
        return 'y'; //return y for a bad user entry
    }
    
    
}
//
void inputS(board &player, int i){
    int x=0;
    int y=0; 
    int x2=0; 
    int y2=0;
    char Cypos;
    
    //enter
    do{
        cout<<"Enter "<<player.getN(i)<<" which is of size"
                " "<<player.getSzs(i)<<endl;
        cout<<"enter the initial x position 1-10"<<endl;
        do{
            cin>>x;
            try{
                if(x>10||x<1)
                {
                    string error1="Please enter a value between 1 and 10";
                    throw error1;
                }
            }
            catch (string error1)
            {
                cout<<error1<<endl;
            }
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
    }while(checkC(player, i, x, y, x2, y2)=='y');
    
    
    //create ship with initial x and pos positions
    player.makeShp(i, x, y, x2, y2);
    player.shipOn(i);
    player.disCoor(i);
    player.fillrest(i);

}