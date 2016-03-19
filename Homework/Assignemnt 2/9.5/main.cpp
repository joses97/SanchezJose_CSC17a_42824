/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.5
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int doSomething(int *x, int *y);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variable
    int a=0; //initialize a to 0    
    int b=0; //initialize b to 0
    
    cout<<"Enter a number"<<endl;
    cin>>a;
    
    cout<<"Enter another number"<<endl;
    cin>>b;
    
    cout<<doSomething(&a, &b)<<endl;
    
    //exit
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}