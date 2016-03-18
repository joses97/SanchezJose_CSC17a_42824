/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on February 29 2016
 * Purpose: Fahrenheit to celsius
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
    //Declare and initialize variables
    float fahr=0;       //Initialize F to 0
    float celsius=0;    //Initialize C to 0
    
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    //explain
    cout<<"Gaddis 8th Ed Chapter 3 Problem 12"<<endl;
    cout<<"This program converts C to F"<<endl;
    
    //Input the degrees in celsius
    cout<<"Please enter the degrees Celsius to see the degrees in Fahrenheit"<<endl;
    cin>>celsius;
    
    //Calculate for Fahrenheit
    fahr=(9.0f/5.0f)*celsius+32;
    
    //Output Celsius and Fahrenheit 
    cout<<celsius<<" degrees Celsius is equivalent to "<<fahr<<" degrees Fahrenheit"<<endl;
    
    //exit
    return 0;
}

