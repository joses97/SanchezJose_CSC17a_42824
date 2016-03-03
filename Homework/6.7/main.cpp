/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on February 29 2016
 * Purpose: Celsius Temp Table
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
float conv(int fahr); //converts f to c 
//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    int loop=101; //size of the loop
    
    //explain 
    cout<<"Gaddis 8th Ed Chapter 6 Problem 7"<<endl;
    cout<<"This program takes Fahrenheit and converts it to Celsius in a table"<<endl;
    
    //set decimal places to 2
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    //table
    cout<<"F    C"<<endl;
    //call function
    for (int i=0; i<loop; i++){
        cout<<i<<"    "<<conv(i)<<endl;
    }
    
    //exit
    return 0;
}
//******************************************************************************
//*********************Convert F to C*******************************************
//******************************************************************************
float conv(int fahr){   
    float cels=(fahr-32)*(5.0f/9.0f); // calculate cels=(fahr-32)*(5.0f/9.0f
    return cels; //return cels
}
