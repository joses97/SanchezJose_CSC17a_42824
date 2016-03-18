/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on February 29 2016
 * Purpose: Dollar to Yen and Euros
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    float dollar=0;   //the amount of dollars
    float yen=0;      //the amount of yen
    float euros=0;    //the amount of euros
    const float YPERD=113.5834;  //yen per dollar
    const float EPERD=0.9188f;    //euro per dollar 
    
    //Set precision to 2 decimal places
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    //explain 
    cout<<"Gaddis 8th Ed Chapter 3 Problem 12"<<endl;
    
    //input the amount of dollars
    cout<<"This program takes Dollars and converts them to Yen and Euros"<<endl;
    cout<<"Please enter the amount of dollars to see it converted to Yen and Euros"<<endl;
    cin>>dollar;
    
    //calculate yen and euros
    yen=YPERD*dollar;
    euros=EPERD*dollar;
    
    //output dollars, yen, and euros
    cout<<"$"<<dollar<<" is "<<yen<<" Yen "<<endl;
    cout<<"$"<<dollar<<" is "<<euros<<" Euros"<<endl;
    
    //exit
    return 0;
}

