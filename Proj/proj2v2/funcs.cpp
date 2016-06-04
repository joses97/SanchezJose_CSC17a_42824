/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: hold main functions
 * Created on June 4th 2016
 */

//System Libraries 
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

//user libraries
#include "board.h"
#include "plyrInfo.h"
using namespace std;

//global constants

//******************************************************************************
//******************************************************************************
//get the rules of the game, reused code from last project
void rules(){
    fstream rules; //rules fstream
    string line;  //to read into 
    
    //open the file rules.txt for input
    rules.open("rules.txt", ios::in);
    
    //if failed to open  tell user failed to open
    if (rules.fail())
    {
        cout<<"rules.txt not found!"<<endl;
    }
    //else display contents of the .txt
    else{
        while(! rules.eof()){       //while !rules.eof())
            getline(rules, line); //call get line
            cout<<line<<endl;
        }
    }
    cout<<endl;
    //close rules file
    rules.close();
}
//******************************************************************************
//******************************************************************************
//this functions changes a character to an integer
int CtoInt(char y){
    switch (y)
    {
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
//This function is used to get the coordinates of the users ships
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
        do
        {
            cin>>x;
            try
            {
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
        }
        while(x>10||x<1);
        //enter
        do
        {    
            cout<<"enter the initial y position A-J"<<endl;
            cin>>Cypos;
        } while(CtoInt(toupper(Cypos))==11);
        
        //convert
        y=CtoInt(toupper(Cypos));

        //enter
        do{
            cout<<"enter the final x position 1-10"<<endl;
            cin>>x2;
        }while(x2>10||x2<1);
        
        //enter
        do
        {    
            cout<<"enter the final y position A-J"<<endl;
            cin>>Cypos;
        } while(CtoInt(toupper(Cypos))==11);
        //convert
        y2=CtoInt(toupper(Cypos));
        try
        {
            reDo=player.testCor(i, x, y, x2, y2);
        }
        catch(board::invalid)
        {
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
