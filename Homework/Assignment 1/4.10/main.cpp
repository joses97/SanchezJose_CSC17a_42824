/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on February 29 2016
 * Purpose: Find if year is leap year
 *  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    int month=0;  //month set to 0 
    int year=0;   //year set to 0 
    bool leapYr=false;  //set leapyr false
    
    //explain
    cout<<"Gaddis 8th Ed Chapter 4 Problem 10"<<endl;
    
    //Input the month and year
    cout<<"This program takes the users input for month and displays"
            " the amount of days in it"<<endl;
    cout<<"Please enter the month you would like to see (1-12): ";
    cin>>month;
    cout<<"Now enter the year: ";
    cin>>year;
    
    //Find the month
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: { //case 1, 3, 5, 6, 7. 8, 10, 12
            cout<<"31 Days"<<endl;
            break;
        }
        case 4: case 6: case 9: case 11:{ //case 4, 6, 9, 11
            cout<<"30 Days"<<endl;
            break;
        }
        case 2:{ //case==2
            if(year%100==0&&year%400==0){ //if  year%100==0&&year%400==0
                leapYr=true;                    //leapYr=true
            }else if(year%100!=0&&year%4==0){   //else if year%100!=0&&year%4==0
                leapYr=true;                        //leapYr=true
            }
            if(leapYr==true){           //leapYr==true
                cout<<"29 days"<<endl;
            }else{                      //else
                cout<<"28 days"<<endl;
            }
            break;
        }
    }
    //exit
    return 0;
}

