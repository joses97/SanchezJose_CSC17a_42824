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
bool checkS(board, int, int, int, int, int);

int main(int argc, char** argv) {
    int count;
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    
    player1.setSNms();
    player1.setSize();
    
    
    for(int i=0; i<5; i++){
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
bool checkS(board player, int i, int x, int y, int x2, int y2){
    bool check1=false;
    bool check2=false;
    bool check3=false;
    int size=player.getSzs(i);
    
    if(x2-x==0){
        check1=true;
    }
    if(y2-y==0){
        check2=true;
    }
    if(x2-x==size){
        check3=true;
    }
    if(y2-y==size){
        check3=true;
    }
    if((check1||check2)==true){
        if(check3==true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
//
void inputS(board &player, int i){
    int x=0;
    int y=0; 
    int x2=0; 
    int y2=0;
    char Cypos;
    bool test=false;
    
    //enter
    do{
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
        test=checkS(player, i, x, y, x2, y2);
        cout<<test<<endl;
    }while(test==false);
    
    
    //create ship with initial x and pos positions
    player.makeShp(i, x, y, x2, y2);
    player.shipOn(i);
    player.disCoor(i);
    player.fillrest(i);

}