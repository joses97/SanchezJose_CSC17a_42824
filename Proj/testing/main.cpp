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
#include "plyrInfo.h"
#include <fstream>
using namespace std;

/*
 * 
 */

//functions
void inputS(board&, int);
char checkC(board, int, int, int, int, int);

int main(int argc, char** argv) {
    int count;
    info *players = new info[NUMPLAY];
    
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    //set the names of the ships to the ships created
    player1.setSNms();
    player1.setSize(); //set the size of the ships to the ships created
    
    //set the names of the ships to the ships created
    player2.setSNms();
    player2.setSize(); //set the size of the ships to the ships created
    
    //enter the info of the players
    for(int i=0; i<NUMPLAY; i++){
        cout<<"Enter name of player "<<i+1<<" ";
        getline(cin, players[i].names);
    }
    
    for(int i=0; i<NUMSHIP; i++){
        player1.display();
        inputS(player1, i);
        player1.display();
    }
    for(int i=0; i<NUMSHIP; i++){
        player2.display();
        inputS(player2, i);
        player2.display();
    }
    
    delete [] players;
    
    return 0;
}
//******************************************************************************
//******************************************************************************
//get the rules of the game, reused code from last project
void rules(){
    fstream rules; //rules fstream
    string line;  //to read into 
    
    //open the file rules.txt for input
    rules.open("rules.txt", ios::in);
    
    //if failed to open  tell user failed to open
    if (rules.fail()){
        cout<<"rules.txt not found!"<<endl;
    }
    //else display contents of the .txt
    else{
        while(! rules.eof()){       //while !rules.eof())
            getline(rules, line); //call get line
            cout<<line<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    //close rules file
    rules.close();
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
void inputS(board &player, int i){
    int x=0;
    int y=0; 
    int x2=0; 
    int y2=0;
    char Cypos;
    bool reDo=false;
    
    //enter
    do{
        reDo=false;
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
        try{
            reDo=player.testCor(i, x, y, x2, y2);
        }
        catch(board::invalid){
            cout<<endl;
            cout<<"Invalid Coordinates were entered"<<endl;
            cout<<"Re-Enter Values with the with correct size"<<endl;
            cout<<endl;
            player.display();
        }
    }while(!reDo);
    
    
    //create ship with initial x and pos positions
    player.makeShp(i, x, y, x2, y2);
    player.shipOn(i);
    player.disCoor(i);
    player.fillrest(i);

}